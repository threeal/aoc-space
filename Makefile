.PHONY: format test

test:
	@make -C day-01
	@make -C day-02
	@make -C day-03
	@make -C day-04
	@make -C day-05
	@make -C day-06
	@make -C day-07
	@make -C day-08
	@make -C day-09
	@make -C day-10
	@make -C day-11
	@make -C day-12
	@make -C day-13
	@make -C day-14
	@make -C day-15
	@make -C day-16
	@make -C day-17

format:
	@clang-format -i **/*.cpp
