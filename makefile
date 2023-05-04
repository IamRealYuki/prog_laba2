flags = -Wall -Werror -g -O0

.PHONY: app

app:
	gcc $(flags) -o app src/IntVector.c src/IntVectorMain.c

.PHONY: run
run:
	valgrind ./app