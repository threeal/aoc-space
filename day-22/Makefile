.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-1 puzzle-2
	@echo "Testing Day 22: Monkey Market..."
	@cat input-1.txt | ./puzzle-1
	@cat input-2.txt | ./puzzle-2
