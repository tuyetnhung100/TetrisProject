clean: all
	rm main.o pieces.o checkFilled.o display.o

all: main.o checkFilled.o pieces.o display.o
	gcc main.o checkFilled.o pieces.o display.o -o KindaTetris.exe

main.o: main.c
	gcc -c main.c

checkFilled.o: checkFilled.h checkFilled.c
	gcc -c checkFilled.c

pieces.o: pieces.h pieces.c
	gcc -c pieces.c

display.o: display.h display.c
	gcc -c display.c
