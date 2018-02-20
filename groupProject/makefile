

output: main.o Ant.o Critter.o Doodlebugs.o Grid.o Helper.o 
	g++ main.o Ant.o Critter.o Doodlebugs.o Grid.o Helper.o -o output

main.o: main.cpp Position.h Status.h CritterType.h
	g++ -c -std=c++11 main.cpp

Ant.o: Ant.cpp Ant.h
	g++ -c -std=c++11 Ant.cpp 

Critter.o: Critter.cpp Critter.h
	g++ -c -std=c++11 Critter.cpp

Doodlebugs.o: Doodlebugs.cpp Doodlebugs.h
	g++ -c -std=c++11 Doodlebugs.cpp

Grid.o: Grid.cpp Grid.h
	g++ -c -std=c++11 Grid.cpp

Helper.o: Helper.cpp Helper.h
	g++ -c -std=c++11 Helper.cpp

clean:
	rm *.o output 
