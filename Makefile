CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OUT = program
SRC = get_next_line.c get_next_line_utils.c program.c
BUFF_SIZE = 69

build:
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFF_SIZE) $(SRC) -o $(OUT)

run: build
	@./program Makefile
	@rm -f $(OUT)

clean:
	@rm -f $(OUT)

re: clean build

.PHONY: build clean run
