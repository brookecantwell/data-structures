labirynth: driver.o maze.o
	g++ -o labirynth driver.o maze.o
driver.o: driver.cpp maze.h
	g++ -c driver.cpp
maze.o: maze.cpp maze.h
	g++ -c maze.cpp
clean:
	rm -f *.o *~ ./#*#
