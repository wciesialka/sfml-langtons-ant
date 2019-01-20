ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

langtons-ant: build/Main.o build/Grid.o build/Cell.o build/Ant.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system
build/Main.o: src/Main.cpp src/Grid.cpp src/Cell.cpp src/Ant.cpp build
	g++ -c $< -o $@
build/Grid.o: src/Grid.cpp src/Grid.h src/Cell.cpp build
	g++ -c $< -o $@
build/Cell.o: src/Cell.cpp src/Cell.h build
	g++ -c $< -o $@
build/Ant.o: src/Ant.cpp src/Ant.h build
	g++ -c $< -o $@
build:
	mkdir $(ROOT_DIR)/build
run: langtons-ant
	./$<
clean:
	-rm -rf $(ROOT_DIR)/build
	-rm langtons-ant