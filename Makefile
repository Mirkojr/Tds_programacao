ALL: bin main

bin:
	mkdir -p bin/

main: bin/main.o bin/arvoreBinaria.o
	gcc bin/*.o -o main

bin/main.o: main.c src/inc/arvoreBinaria.h
	gcc -c main.c -o bin/main.o

bin/arvoreBinaria.o: src/arvoreBinaria.c src/inc/arvoreBinaria.h
	gcc -c src/arvoreBinaria.c -o bin/arvoreBinaria.o

clean:
	rm -rf bin/ main