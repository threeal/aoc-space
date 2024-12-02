.PHONY: test

%: %.cpp
	@clang++ -std=c++20 $< -o $@

test: main
	@echo "Testing Day 0..."
	@./main
