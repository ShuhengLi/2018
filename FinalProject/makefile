

output: main.o Door.o Game.o Geek.o Helper.o Steve.o Space.o Raymond.o OriginalSeat.o Omniscience.o MusicTeacher.o Meng.o Jerry.o
	g++ main.o Door.o Game.o Geek.o Helper.o Steve.o Space.o Raymond.o OriginalSeat.o Omniscience.o MusicTeacher.o Meng.o Jerry.o -o output

main.o: main.cpp Items.h Direction.h
	g++ -c -std=c++11 main.cpp

Door.o: Door.cpp Door.h
	g++ -c -std=c++11 Door.cpp 

Game.o: Game.cpp Game.h
	g++ -c -std=c++11 Game.cpp

Geek.o: Geek.cpp Geek.h
	g++ -c -std=c++11 Geek.cpp

Helper.o: Helper.cpp Helper.h
	g++ -c -std=c++11 Helper.cpp
	
Jerry.o: Jerry.cpp Jerry.h
	g++ -c -std=c++11 Jerry.cpp

Meng.o: Meng.cpp Meng.h
	g++ -c -std=c++11 Meng.cpp
	
MusicTeacher.o: MusicTeacher.cpp MusicTeacher.h
	g++ -c -std=c++11 MusicTeacher.cpp
	
Omniscience.o: Omniscience.cpp Omniscience.h
	g++ -c -std=c++11 Omniscience.cpp
	
OriginalSeat.o: OriginalSeat.cpp OriginalSeat.h
	g++ -c -std=c++11 OriginalSeat.cpp
	
Raymond.o: Raymond.cpp Raymond.h
	g++ -c -std=c++11 Raymond.cpp
	
Space.o: Space.cpp Space.h
	g++ -c -std=c++11 Space.cpp
	
Steve.o: Steve.cpp Steve.h
	g++ -c -std=c++11 Steve.cpp
	
clean:
	rm *.o output 
