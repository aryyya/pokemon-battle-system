all:
	c++ -Wextra -Wall -std=c++17 src/*.cpp -o PokemonBattleSystem

debug:
	c++ -g -Wextra -Wall -std=c++17 src/*.cpp -o PokemonBattleSystem
