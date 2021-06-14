CC=g++
CFLAGS=-std=c++11
OBJECTS = Reservation.o Car.o main.o

default = main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o program $(OBJECTS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

Car.o: Car.cpp
	$(CC) -c $(CFLAGS) Car.cpp

Reservation.o: Reservation.cpp
	$(CC) -c $(CFLAGS) Reservation.cpp

clean:
	rm -rf ./*.o
	rm -rf ./program
