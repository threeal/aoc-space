.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-2
	@echo "Testing Day 10: Factory..."
	@cat input.txt | ./puzzle-1
	@cat input.txt | ./puzzle-2
