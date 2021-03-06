all: build_game

build_game: main.o game.o game_state_start.o game_state_editor.o texture_manager.o animation_handler.o tile.o
	g++ main.o game.o game_state_start.o game_state_editor.o texture_manager.o animation_handler.o tile.o -o CityBuilder -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -std=c++14

game.o: game.cpp
	g++ -c game.cpp -std=c++14

game_state_start.o: game_state_start.cpp
	g++ -c game_state_start.cpp -std=c++14

game_state_editor.o: game_state_editor.cpp
	g++ -c game_state_editor.cpp -std=c++14

texture_manager.o: texture_manager.cpp
	g++ -c texture_manager.cpp -std=c++14

animation_handler.o: animation_handler.cpp
	g++ -c animation_handler.cpp -std=c++14

tile.o: tile.cpp
	g++ -c tile.cpp -std=c++14

clean:
	rm -rf *.o build_game