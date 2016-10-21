.PHONY: clean All

All:
	@echo "----------Building project:[ RoyAndRopes - Debug ]----------"
	@cd "RoyAndRopes" && "$(MAKE)" -f  "RoyAndRopes.mk"
clean:
	@echo "----------Cleaning project:[ RoyAndRopes - Debug ]----------"
	@cd "RoyAndRopes" && "$(MAKE)" -f  "RoyAndRopes.mk" clean
