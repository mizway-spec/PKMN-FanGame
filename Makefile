# Pokemon Champions: Emerald Edition
# Master Makefile
#
# Targets:
#   all         — Full build (data + scripts + ROM)
#   data        — Rebuild data patches only
#   scripts     — Rebuild script patches only
#   tools       — Build required tools
#   validate    — Run data validation checks
#   clean       — Remove build artifacts
#   run         — Build and run in mGBA

# ── Config ──────────────────────────────────────────────────────────────────
ROM_NAME      := champions_emerald
BASE_ROM      := base_rom/pokemon_emerald.gba
OUTPUT_ROM    := $(ROM_NAME).gba
PATCH_DIR     := patches
BUILD_DIR     := build
SRC_DIR       := src

PYTHON        := python3
MGBA          := mgba

# pokeemerald submodule path
EMERALD_DIR   := pokeemerald

# ── Phony Targets ────────────────────────────────────────────────────────────
.PHONY: all data scripts tools validate clean run check-base

# ── Default: Full Build ───────────────────────────────────────────────────────
all: check-base tools validate $(OUTPUT_ROM)
	@echo ""
	@echo "============================================"
	@echo "  Build complete: $(OUTPUT_ROM)"
	@echo "============================================"

# ── Base ROM check ────────────────────────────────────────────────────────────
check-base:
	@if [ ! -f "$(BASE_ROM)" ]; then \
		echo "ERROR: Base ROM not found at $(BASE_ROM)"; \
		echo "Place a legally-obtained Pokemon Emerald (US) ROM there."; \
		exit 1; \
	fi
	@$(PYTHON) tools/validate_base_rom.py $(BASE_ROM)

# ── Build ROM ─────────────────────────────────────────────────────────────────
$(OUTPUT_ROM): $(BASE_ROM) $(PATCH_DIR)/data $(PATCH_DIR)/scripts
	@echo "[ROM] Applying all patches to base ROM..."
	cp $(BASE_ROM) $(BUILD_DIR)/working.gba
	$(PYTHON) tools/apply_patches.py \
		--base    $(BUILD_DIR)/working.gba \
		--patches $(PATCH_DIR) \
		--output  $(OUTPUT_ROM)
	@echo "[ROM] Output: $(OUTPUT_ROM)"

# ── Data Patches ─────────────────────────────────────────────────────────────
data: tools validate
	@echo "[DATA] Generating data patches..."
	@mkdir -p $(PATCH_DIR)/data $(BUILD_DIR)
	$(PYTHON) tools/gen_pokemon_data.py \
		--src  $(SRC_DIR)/data/pokemon \
		--out  $(PATCH_DIR)/data/pokemon.ips
	$(PYTHON) tools/gen_move_data.py \
		--src  $(SRC_DIR)/data/moves \
		--out  $(PATCH_DIR)/data/moves.ips
	$(PYTHON) tools/gen_trainers.py \
		--src  $(SRC_DIR)/data/trainers \
		--out  $(PATCH_DIR)/data/trainers.ips
	$(PYTHON) tools/gen_map_data.py \
		--src  $(SRC_DIR)/data/maps \
		--out  $(PATCH_DIR)/data/maps.ips
	@echo "[DATA] Done."

# ── Script Patches ────────────────────────────────────────────────────────────
scripts: tools
	@echo "[SCRIPTS] Compiling Poryscript files..."
	@mkdir -p $(PATCH_DIR)/scripts $(BUILD_DIR)/scripts
	@for f in $(SRC_DIR)/scripts/*.pory; do \
		name=$$(basename $$f .pory); \
		echo "  Compiling: $$name"; \
		tools/poryscript/poryscript compile \
			-i $$f \
			-o $(BUILD_DIR)/scripts/$$name.inc; \
	done
	$(PYTHON) tools/gen_script_patch.py \
		--src  $(BUILD_DIR)/scripts \
		--out  $(PATCH_DIR)/scripts/scripts.ips
	@echo "[SCRIPTS] Done."

# ── Tools ─────────────────────────────────────────────────────────────────────
tools:
	@echo "[TOOLS] Building / checking tools..."
	@mkdir -p tools/poryscript
	@if [ ! -f "tools/poryscript/poryscript" ]; then \
		echo "  Downloading poryscript..."; \
		git clone --depth=1 https://github.com/huderlem/poryscript tools/_poryscript_src; \
		cd tools/_poryscript_src && go build -o ../poryscript/poryscript; \
	fi
	@echo "[TOOLS] Done."

# ── Validation ────────────────────────────────────────────────────────────────
validate:
	@echo "[VALIDATE] Running data integrity checks..."
	$(PYTHON) tools/validate.py \
		--pokemon  $(SRC_DIR)/data/pokemon/species_data.h \
		--moves    $(SRC_DIR)/data/moves/move_data.h \
		--trainers $(SRC_DIR)/data/trainers/champion_parties.h
	@echo "[VALIDATE] All checks passed."

# ── Run in mGBA ───────────────────────────────────────────────────────────────
run: $(OUTPUT_ROM)
	$(MGBA) $(OUTPUT_ROM)

# ── Clean ─────────────────────────────────────────────────────────────────────
clean:
	@echo "[CLEAN] Removing build artifacts..."
	rm -rf $(BUILD_DIR) $(OUTPUT_ROM)
	rm -rf $(PATCH_DIR)/data $(PATCH_DIR)/scripts
	@echo "[CLEAN] Done."
