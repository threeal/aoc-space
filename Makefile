.PHONY: format test

test:
	@make -C day-01
	@make -C day-02
	@make -C day-03
	@make -C day-04

format:
	@clang-format -i **/*.cpp
