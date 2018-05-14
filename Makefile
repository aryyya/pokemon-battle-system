compiler=c++
flags=-Wextra -Wall -std=c++17
sources=src/*.cpp
output=PokemonBattleSystem

all:
	$(compiler) $(flags) $(sources) -o $(output)

debug:
	$(compiler) $(flags) -g $(sources) -o $(output)

.PHONY: clean
clean:
	rm -rf $(output) *.dSYM
