CC=gcc
FLAGS=-Wall -g
LIBFLAGS=-Wall -g -shared

all: task1.1 task1.2 task1.3 subtask2.1 subtask2.2 subtask2.3 subtask2.4

task1.1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o task1.1 main1_1.o hello_Ariel.o

task1.2: main1_2.o mylib
	$(CC) $(FLAGS) -o task1.2 main1_2.o -L. -lmylib

task1.3: main1_3.o
	$(CC) $(FLAGS) -o $@ main1_3.o -ldl

subtask2.1: subtask2_1.o
	$(CC) $(FLAGS) -o $@ $<

subtask2.2: subtask2_2.o
	$(CC) $(FLAGS) -o $@ $<

subtask2.3: subtask2_3.o
	$(CC) $(FLAGS) -o $@ $<

subtask2.4: subtask2_4.o subtask2_1.o subtask2_2.o
	$(CC) $(FLAGS) -o $@ subtask2_4.o

subtask2_1.o: subtask2_1.c
	$(CC) $(FLAGS) -c $<

subtask2_2.o: subtask2_2.c
	$(CC) $(FLAGS) -c $<

subtask2_3.o: subtask2_3.c
	$(CC) $(FLAGS) -c $<

subtask2_4.o: subtask2_4.c
	$(CC) $(FLAGS) -c $<

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c -fPIC hello_Ariel.c

mylib: hello_Ariel.o hello_Ariel.h
	$(CC) $(LIBFLAGS) -o libmylib.so hello_Ariel.o


.PHONY: clean all

clean:
	rm -f task1.1 task1.2 task1.3 *.o *.so subtask2.1 subtask2.2 subtask2.3 subtask2.4
