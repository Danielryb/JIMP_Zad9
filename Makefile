all:
	gcc -Wall --pedantic src/*.c -o bin/gauss -lm

testall: all test test1 test2 test3

test: all
	bin/gauss dane/A dane/b

test1: all
	bin/gauss dane/A1 dane/b1

test2: all
	bin/gauss dane/A2 dane/b2

test3: all
	bin/gauss dane/A3 dane/b3
