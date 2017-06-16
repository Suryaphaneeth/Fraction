all: frac

frac: fraction.o main.o
	g++ fraction.o main.o -std=c++11 -o frac

main.o:main.cpp
	g++ -g -c -std=c++11 main.cpp

fraction.o:fraction.cpp
	g++ -g -c -std=c++11 fraction.cpp

# .PHONY: clean
clean: rm -f *.o frac

