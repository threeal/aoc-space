.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 11: Reactor..."
	@cat input.txt | ./puzzle-1
