

output: main.o Menu.o MyQueue.o  Node.o Helper.o 
	g++ main.o Menu.o MyQueue.o Node.o Helper.o -o output

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c -std=c++11 Menu.cpp 

MyQueue.o: MyQueue.cpp MyQueue.h
	g++ -c -std=c++11 MyQueue.cpp

Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp

Helper.o: Helper.cpp Helper.h
	g++ -c -std=c++11 Helper.cpp

clean:
	rm *.o output 
