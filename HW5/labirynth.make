labirynth: labirynth.o maze.o stack.o
	g++ -o labirynth labirynth.o maze.o stack.o
labirynth.o: labirynth.cpp maze.h stack.h
	g++ -c labirynth.cpp
maze.o: maze.cpp maze.h stack.h
	g++ -c maze.cpp stack.cpp
stack.o: stack.cpp stack.h
        g++ -c stack.cpp
clean:
	rm -f *.o *~ ./#*#
