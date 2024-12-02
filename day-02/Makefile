.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 2: Red-Nosed Reports..."
	@cat input.txt | ./puzzle-1
