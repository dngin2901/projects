test: test.o
	./test.o
	#debug50 test.o
	rm test.o

test.o: test.cpp heap.cpp
	g++ -std=c++11 test.cpp heap.cpp -o test.o #-ggdb

