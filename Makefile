.PHONY: clean All

All:
	@echo "----------Building project:[ XsquareAndChocolatesBars - Debug ]----------"
	@cd "XsquareAndChocolatesBars" && "$(MAKE)" -f  "XsquareAndChocolatesBars.mk"
clean:
	@echo "----------Cleaning project:[ XsquareAndChocolatesBars - Debug ]----------"
	@cd "XsquareAndChocolatesBars" && "$(MAKE)" -f  "XsquareAndChocolatesBars.mk" clean
