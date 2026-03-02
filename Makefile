all: main.o parser.o
	g++ -I includes parser.o main.o -o main.exe
	make clean

main.o: main.cpp 
	g++ -c -I includes main.cpp -o main.o

parser.o: src/utils/parser.cpp
	g++ -c -I includes src/utils/parser.cpp -o parser.o

clean: 
	rm -f parser.o main.o