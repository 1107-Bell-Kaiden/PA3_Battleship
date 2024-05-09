battleship: main.o helpers.o boat.o player.o aiPlayer.o dynamicArray.o
	g++ -o battleship main.o helpers.o boat.o player.o aiPlayer.o dynamicArray.o

main.o: boat.h player.h aiPlayer.h dynamicArray.h helpers.cpp
	g++ -c main.cpp

helpers.o: boat.h player.h aiPlayer.h dynamicArray.h main.cpp
	g++ -c helpers.cpp

boat.o: boat.h boat.cpp
	g++ -c boat.cpp

player.o: boat.h player.h player.cpp
	g++ -c player.cpp

aiPlayer.o: boat.h player.h aiPlayer.h aiPlayer.cpp
	g++ -c aiPlayer.cpp

dynamicArray.o: dynamicArray.h dynamicArray.cpp
	g++ -c dynamicArray.cpp

clean:
	rm *.o battleship