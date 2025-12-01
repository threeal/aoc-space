.PHONY: format test

test:
	@make -C aoc-2024
	@make -C aoc-2025

format:
	@clang-format -i **/**/*.cpp
