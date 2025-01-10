CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OUT = program
SRC = get_next_line.c get_next_line_utils.c program.c
BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c program_bonus.c
BUFF_SIZE = 69

build:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFF_SIZE) $(SRC) -o $(OUT)

build_bonus:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFF_SIZE) $(BONUS) -o $(OUT)

run: build
	@./program Makefile
	@rm -f $(OUT)

run_bonus: build_bonus
	@./program Makefile
	@rm -f $(OUT)

clean:
	@rm -f $(OUT)

re: clean build

.PHONY: build build_bonus clean run run_bonus
