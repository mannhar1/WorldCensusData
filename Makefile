all: Country.o Continent.o Driver.o
	g++ -Wall Country.cpp Continent.cpp Driver.cpp -o driver.out

Country.o: Country.cpp
	g++ -Wall -c Country.cpp

Continent.o: Continent.cpp
	g++ -Wall -c Continent.cpp

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

run:
	./driver.out

valgrind:
	valgrind driver.out