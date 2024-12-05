.PHONY: format test

format:
	@clang-format -i **/*.cpp

test:
	@make -C day-01
	@make -C day-02
	@make -C day-03
	@make -C day-04
