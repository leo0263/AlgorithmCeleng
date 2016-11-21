.PHONY: clean All

All:
	@echo "----------Building project:[ MiniOthello - Debug ]----------"
	@cd "MiniOthello" && "$(MAKE)" -f  "MiniOthello.mk"
clean:
	@echo "----------Cleaning project:[ MiniOthello - Debug ]----------"
	@cd "MiniOthello" && "$(MAKE)" -f  "MiniOthello.mk" clean
