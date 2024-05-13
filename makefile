battleship: main.o helpers.o boat.o player.o aiPlayer.o dynamicArray.o square.o
	g++ -o battleship main.o helpers.o boat.o player.o aiPlayer.o dynamicArray.o square.o

main.o: boat.h player.h aiPlayer.h dynamicArray.h helpers.cpp
	g++ -c main.cpp

helpers.o: boat.h player.h aiPlayer.h dynamicArray.h square.h
	g++ -c helpers.cpp

boat.o: boat.h boat.cpp square.h
	g++ -c boat.cpp

player.o: boat.h player.h player.cpp dynamicArray.h square.h
	g++ -c player.cpp

aiPlayer.o: boat.h player.h aiPlayer.h aiPlayer.cpp dynamicArray.h square.h
	g++ -c aiPlayer.cpp

dynamicArray.o: dynamicArray.h
	g++ -c dynamicArray.h

square.o: square.h
	g++ -c square.h

clean:
	rm *.o battleship