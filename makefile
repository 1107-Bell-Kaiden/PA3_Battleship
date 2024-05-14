battleship: main.o helpers.o boat.o player.o aiPlayer.o
	g++ -o battleship main.o helpers.o boat.o player.o aiPlayer.o

main.o: main.cpp boat.h player.h aiPlayer.h dynamicArray.h helpers.h square.h
	g++ -c main.cpp

helpers.o: helpers.cpp helpers.h boat.h player.h aiPlayer.h dynamicArray.h square.h
	g++ -c helpers.cpp

boat.o: boat.cpp boat.h square.h
	g++ -c boat.cpp

player.o: player.cpp player.h boat.h dynamicArray.h square.h helpers.h
	g++ -c player.cpp

aiPlayer.o: aiPlayer.cpp aiPlayer.h boat.h player.h dynamicArray.h square.h helpers.h
	g++ -c aiPlayer.cpp

clean:
	rm *.o battleship
