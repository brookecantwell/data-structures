labirynth: labirynth.o maze.o stack.o
	g++ -o labirynth labirynth.o maze.o stack.o
labirynth.o: labirynth.cpp maze.cpp stack.cpp
	g++ -c labirynth.cpp maze.cpp stack.cpp
maze.o: maze.cpp stack.cpp
	g++ -c maze.cpp stack.cpp
stack.o: stack.cpp
        g++ -c stack.cpp
clean:
	rm -f *.o *~ ./#*#
