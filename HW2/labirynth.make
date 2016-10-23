labirynth: labirynth.o maze.o
	g++ -o labirynth labirynth.o maze.o
driver.o: labirynth.cpp maze.h
	g++ -c labirynth.cpp
maze.o: maze.cpp maze.h
	g++ -c maze.cpp
clean:
	rm -f *.o *~ ./#*#
