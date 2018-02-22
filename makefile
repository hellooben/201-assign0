############################
#CS201, Assign0, makefile
#Ben Bailey
#This is the makefile for the sll, dll, stack and queue classes.
#It responds to make, make test (make test-sll/dll/stack/queue as well), make valgrind, and make clean.
############################
#sll-0-1.c sll-0-2.c sll-0-3.c sll-0-4.c sll-0-5.c sll-0-6.c sll-0-7.c sll-0-8.c sll-0-9.c sll-0-10.c sll-0-11.c sll-0-12.c sll-0-13.c sll-0-14.c
#sll-0-1.o sll-0-2.o sll-0-3.o sll-0-4.o sll-0-5.o sll-0-6.o sll-0-7.o sll-0-8.o sll-0-9.o sll-0-10.o sll-0-11.o sll-0-12.o sll-0-13.o sll-0-14.o
OBJS = integer.o real.o string.o sll.o dll.o stack.o queue.o a.out sll-*-*.o dll-*-*.o stack-*-*.o queue-*-*.o massive-test.o
LOPTS = -Wall -Wextra -std=c99

all : test-sll test-dll test-stack test-queue

test-sll :
	gcc $(LOPTS) -c sll.c integer.c sll-0-0.c
	gcc $(LOPTS) sll-0-0.o integer.o sll.o -o test-sll

test-dll :
	gcc $(LOPTS) -c dll.c integer.c dll-0-0.c
	gcc $(LOPTS) dll-0-0.o integer.o dll.o -o test-dll

test-stack :
	gcc $(LOPTS) -c stack.c dll.c integer.c stack-0-0.c
	gcc $(LOPTS) stack-0-0.o integer.o dll.o stack.o -o test-stack

test-queue :
	gcc $(LOPTS) -c queue.c sll.c integer.c queue-0-0.c
	gcc $(LOPTS) queue-0-0.o integer.o sll.o queue.o -o test-queue

test-big :
	gcc $(LOPTS) -c sll.c dll.c stack.c queue.c integer.c real.c string.c massive-test.c
	gcc $(LOPTS) massive-test.o integer.o real.o string.o sll.o dll.o stack.o queue.o -o test-big

valgrind :
	echo testing singly-linked list
	valgrind ./test-sll
	echo
	echo testing doubly-linked list
	valgrind ./test-dll
	echo
	echo testing stack
	valgrind ./test-stack
	echo
	echo testing queue
	valgrind ./test-queue
	echo

test :
	./test-sll
	./test-dll
	./test-stack
	./test-queue

clean :
	rm -f $(OBJS) test-*.o *final.o test-sll test-dll test-stack test-queue test-big
