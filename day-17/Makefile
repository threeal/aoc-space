.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1 puzzle-2
	@echo "Testing Day 17: Chronospatial Computer..."
	@cat input.txt | ./puzzle-1
	@cat input.txt | ./puzzle-2
