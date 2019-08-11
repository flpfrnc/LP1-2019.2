.PHONY: all, bin, folders, clean

all: bin

bin: folders caixa

folders: 
	mkdir -p obj

obj/main.o: src/main.cpp include/funcoes.hpp
	g++ src/main.cpp -Wall -pedantic -c -o obj/main.o

obj/funcoes.o: src/funcoes.cpp include/funcoes.hpp
	g++ src/funcoes.cpp -Wall -pedantic -c -o obj/funcoes.o

caixa: src/main.cpp obj/main.o obj/funcoes.o
	g++ obj/main.o obj/funcoes.o -Wall -pedantic  -o caixa

clean:
	rm -rf obj
	rm -rf caixa
