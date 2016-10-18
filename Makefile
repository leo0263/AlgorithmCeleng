.PHONY: clean All

All:
	@echo "----------Building project:[ aadc_TripleCoreProcessor - Debug ]----------"
	@cd "aadc_TripleCoreProcessor" && "$(MAKE)" -f  "aadc_TripleCoreProcessor.mk"
clean:
	@echo "----------Cleaning project:[ aadc_TripleCoreProcessor - Debug ]----------"
	@cd "aadc_TripleCoreProcessor" && "$(MAKE)" -f  "aadc_TripleCoreProcessor.mk" clean
