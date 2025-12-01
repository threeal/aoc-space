.PHONY: format test

test:
	@make -C aoc-2024

format:
	@clang-format -i **/**/*.cpp
