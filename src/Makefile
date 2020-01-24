OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Magatzem.o Estanteria.o Sistema.o
	g++ -o program.exe *.o

program.o: program.cc Magatzem.hh
	g++ -c program.cc $(OPCIONS)

Magatzem.o: Magatzem.cc Magatzem.hh Estanteria.hh Sistema.hh BinTree.hh
	g++ -c Magatzem.cc $(OPCIONS)

Estanteria.o: Estanteria.cc Estanteria.hh
	g++ -c Estanteria.cc $(OPCIONS)

Sistema.o: Sistema.cc Sistema.hh
	g++ -c Sistema.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
