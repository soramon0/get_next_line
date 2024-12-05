CC = cc
CFLAGS = -Wall -Wextra -Werror
OUT = program
SRC = get_next_line.c get_next_line_utils.c program.c


build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./program
	clean

clean:
	rm -f $(OUT)

re: clean build 

.PHONY: build clean run
