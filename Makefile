CC=g++ 
CFLAGS=-c -Wall -std=c++11

all: clean linkedlist.o queue.o  stack.o bst.o main.o
	$(CC) linkedlist.o queue.o stack.o bst.o main.o

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) linkedlist.cpp 

queue.o: queue.cpp queue.h 
	$(CC) $(CFLAGS) queue.cpp 

stack.o: stack.cpp stack.h 
	$(CC) $(CFLAGS) stack.cpp

bst.o: bst.cpp bst.h
	$(CC) $(CFLAGS) bst.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean: 
	rm -f linkedlist.o queue.o stack.o main.o a.out