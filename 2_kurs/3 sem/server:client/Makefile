CC=gcc
CFLAGS=-Wall -pedantic

BIN=client.exe server.exe

all: clean  $(BIN)

%.exe:%.c
	@echo "Build $@"
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo "Clean project"
	rm -rf *.exe