.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 10: Hoof It..."
	@cat input.txt | ./puzzle-1
