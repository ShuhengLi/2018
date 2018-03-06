

output: main.o Menu.o Helper.o 
	g++ main.o Menu.o  Helper.o -o output

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c -std=c++11 Menu.cpp 

Helper.o: Helper.cpp Helper.h
	g++ -c -std=c++11 Helper.cpp

clean:
	rm *.o output 
