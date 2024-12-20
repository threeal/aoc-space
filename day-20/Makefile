.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 20: Race Condition..."
	@cat input.txt | ./puzzle-1
