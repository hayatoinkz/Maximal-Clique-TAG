all: main

main: main.cpp t1.cpp t1.h
	g++ -std=c++11 main.cpp t1.cpp -o main

clean: 
	rm main