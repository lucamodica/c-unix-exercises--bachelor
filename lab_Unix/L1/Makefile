a: application.o sum.o mult.o
	gcc -o a application.o sum.o mult.o

application.o: application.c
	gcc -c application.c

sum.o: sum.c
	gcc -c sum.c

mult.o: mult.c
	gcc -c mult.c

clean:
	rm *.o a

