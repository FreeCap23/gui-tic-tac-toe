all:
	g++ main.cpp `wx-config --libs` `wx-config --cxxflags` -o build/TicTacToe
run:
	g++ main.cpp `wx-config --libs` `wx-config --cxxflags` -o build/TicTacToe && ./build/TicTacToe