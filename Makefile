CC      := cc
CFLAGS  := -Wall -Wextra -Werror
LDFLAGS := -lpthread

.PHONY: all
all: main pthreads macro strings

main: src/main.c
	$(CC) $(CFLAGS) src/main.c -o src/main $(LDFLAGS)

pthreads: src/pthreads.c
	$(CC) $(CFLAGS) src/pthreads.c -o src/pthreads $(LDFLAGS)

macro: src/macro.c
	$(CC) $(CFLAGS) src/macro.c -o src/macro $(LDFLAGS)

strings: src/strings.c
	$(CC) $(CFLAGS) src/strings.c -o src/strings $(LDFLAGS)

.PHONY: clean
clean:
	rm -f src/main src/pthreads src/macro src/strings

.PHONY: slides
slides: docs/slides.md
	pandoc -t beamer docs/slides.md -V theme:Warsaw -o docs/slides.pdf
