.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 8: Playground..."
	@cat input.txt | ./puzzle-1
