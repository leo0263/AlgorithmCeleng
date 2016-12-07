.PHONY: clean All

All:
	@echo "----------Building project:[ DualProcessor - Debug ]----------"
	@cd "DualProcessor" && "$(MAKE)" -f  "DualProcessor.mk"
clean:
	@echo "----------Cleaning project:[ DualProcessor - Debug ]----------"
	@cd "DualProcessor" && "$(MAKE)" -f  "DualProcessor.mk" clean
