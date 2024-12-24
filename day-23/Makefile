.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: puzzle-2
	@echo "Testing Day 23: LAN Party..."
	@cat input.txt | ./puzzle-1
	@cat input.txt | ./puzzle-2
