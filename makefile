flags = -Wall -Werror -g -O0

.PHONY: app.exe

app:
	gcc $(flags) -o app.exe src/IntVector.c src/IntVectorMain.c

.PHONY: run
run:
	valgrind ./app.exe