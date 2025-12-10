.PHONY: test

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    Z3_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lz3
else
    Z3_FLAGS = -I/usr/include -L/usr/lib -lz3
endif

%: %.cpp
	@clang++ -std=c++20 $< -o $@

puzzle-2: puzzle-2.cpp
	@clang++ -std=c++20 ${Z3_FLAGS} $< -o $@

test: puzzle-2
	@echo "Testing Day 10: Factory..."
	@cat input.txt | ./puzzle-1
	@cat input.txt | ./puzzle-2
