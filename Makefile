run: program.exe
	program.exe

compile: program.exe

program.exe: main.o graph.o
	g++ main.o graph.o -o program.exe -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

graph.o: graph.hpp
	g++ -c graph.hpp -std=c++11

clean:
	del *.o *.exe
