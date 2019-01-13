ROOT_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

langtons-ant: build/main.o
	g++ $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system
build/main.o: build src/main.cpp
	g++ -c src/main.cpp -o $@
build:
	mkdir $(ROOT_DIR)/build
run: langtons-ant
	./$<
clean:
	-rm -rf $(ROOT_DIR)/build
	-rm langtons-ant