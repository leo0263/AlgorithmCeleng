.PHONY: clean All

All:
	@echo "----------Building project:[ OnceUponATimeInTimeLand - Debug ]----------"
	@cd "OnceUponATimeInTimeLand" && "$(MAKE)" -f  "OnceUponATimeInTimeLand.mk"
clean:
	@echo "----------Cleaning project:[ OnceUponATimeInTimeLand - Debug ]----------"
	@cd "OnceUponATimeInTimeLand" && "$(MAKE)" -f  "OnceUponATimeInTimeLand.mk" clean
