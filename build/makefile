all: link compile compile-exe exec

link:
	g++ -std=c++17 -c ../source/main.cpp ../source/sim.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -I../headers

compile:
	g++ main.o sim.o -o sim -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

compile-exe:
	g++ main.o sim.o -o sim.exe -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

exec:
	./sim
