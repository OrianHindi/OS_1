CC=gcc
FLAGS=-Wall -g
LIBFLAGS=-Wall -g -shared

all: task1.1 task1.2 task1.3

task1.1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o task1.1 main1_1.o hello_Ariel.o

task1.2: main1_2.o mylib
	$(CC) $(FLAGS) -o task1.2 main1_2.o ./libmylib.so

task1.3: main1_3.o
	$(CC) $(FLAGS) -o $@ main1_3.o -ldl

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c -fPIC hello_Ariel.c

mylib: hello_Ariel.o
	$(CC) $(LIBFLAGS) -o libmylib.so hello_Ariel.o





.PHONY: clean all

clean:
	rm -f task1.1 task1.2 *.o *.so