build: fib.o
	g++ main.cpp fib.o -o main.exe

fib.o: fib.cpp
	g++ -c fib.cpp -o fib.o