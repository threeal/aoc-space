.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 6: Trash Compactor..."
	@cat input.txt | ./puzzle-1
