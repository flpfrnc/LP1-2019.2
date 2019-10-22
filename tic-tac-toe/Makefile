.PHONY: all, bin, folders, clean

all: bin

bin: folders tictac

folders: 
	mkdir -p obj

obj/main.o: src/main.cpp include/tabuleiro.hpp include/jogo.hpp include/jogador.hpp
	g++ src/main.cpp -Wall -pedantic -c -o obj/main.o

obj/tabuleiro.o: src/tabuleiro.cpp include/tabuleiro.hpp
	g++ src/tabuleiro.cpp -Wall -pedantic -c -o obj/tabuleiro.o

obj/jogo.o: src/jogo.cpp include/jogo.hpp
	g++ src/jogo.cpp -Wall -pedantic -c -o obj/jogo.o

obj/jogador.o: src/jogador.cpp include/jogador.hpp
	g++ src/jogador.cpp -Wall -pedantic -c -o obj/jogador.o

tictac: src/main.cpp obj/main.o obj/tabuleiro.o obj/jogo.o obj/jogador.o
	g++ obj/main.o obj/tabuleiro.o obj/jogo.o obj/jogador.o -Wall -pedantic  -o tictac

clean:
	rm -rf obj
	rm -rf tictac
