.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1
	@echo "Testing Day 9: Movie Theater..."
	@cat input.txt | ./puzzle-1
