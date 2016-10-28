.PHONY: clean All

All:
	@echo "----------Building project:[ TheManyPath - Debug ]----------"
	@cd "TheManyPath" && "$(MAKE)" -f  "TheManyPath.mk"
clean:
	@echo "----------Cleaning project:[ TheManyPath - Debug ]----------"
	@cd "TheManyPath" && "$(MAKE)" -f  "TheManyPath.mk" clean
