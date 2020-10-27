fractions: fractions.o main.o
	gcc fractions.o main.o -lm -g -fsanitize=address -fsanitize=leak -o fractions


fractions.o: fractions.c fractions.h
	gcc -c fractions.c -W -Wall


main.o: main.c
	gcc -c main.c -W -Wall


clean: 
	rm -f *.o

mrproper: clean
	rm -rf fractions