#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/rysowanie_3D

__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj obj/main.o obj/lacze_do_gnuplota.o  obj/lamana.o obj/powierzchnia.o\
					obj/powierzchnia3d.o obj/bryla.o obj/dron.o obj/scena.o
	g++ -Wall -pedantic -std=c++11 -o ./rysowanie_3D obj/main.o\
                        obj/lacze_do_gnuplota.o  obj/lamana.o obj/powierzchnia.o\
						obj/powierzchnia3d.o obj/bryla.o obj/dron.o obj/scena.o


obj:
	mkdir -p obj

obj/scena.o: inc/scena.hh src/scena.cpp
	g++ -c ${CXXFLAGS} -o obj/scena.o src/scena.cpp

obj/dron.o: inc/dron.hh src/dron.cpp
	g++ -c ${CXXFLAGS} -o obj/dron.o src/dron.cpp

obj/bryla.o: inc/bryla.hh src/bryla.cpp
	g++ -c ${CXXFLAGS} -o obj/bryla.o src/bryla.cpp

obj/powierzchnia3d.o: inc/powierzchnia3d.hh src/powierzchnia3d.cpp
	g++ -c ${CXXFLAGS} -o obj/powierzchnia3d.o src/powierzchnia3d.cpp

obj/powierzchnia.o: inc/powierzchnia.hh src/powierzchnia.cpp
	g++ -c ${CXXFLAGS} -o obj/powierzchnia.o src/powierzchnia.cpp

obj/lamana.o: inc/lamana.hh src/lamana.cpp
	g++ -c ${CXXFLAGS} -o obj/lamana.o src/lamana.cpp

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh inc/Wektor3D.hh inc/matrix.hh inc/lamana.hh inc/powierzchnia.hh\
							inc/powierzchnia3d.hh inc/bryla.hh inc/dron.hh inc/scena.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o ./rysowanie_3D
