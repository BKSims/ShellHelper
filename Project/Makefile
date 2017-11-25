CC=gcc
CFLAGS=-c -Wall -g

all: cmd-line

cmd-line: shell.o cmd-line.o
	$(CC) shell.o cmd-line.o -o cmd-line

shell.o: shell.c
	$(CC) $(CFLAGS) shell.c

cmd-line.o: cmd-line.c
	$(CC) $(CFLAGS) cmd-line.c

clean:
	/bin/rm -f cmd-line *.o *.gz

run:
	./cmd-line

tarball:
	# put your tar command here
	# tar -cvzf <lastname>.tar.gz *

