Monopoly:	Table.o Cards.o Properties.o Player.o Avenue.o Monopoly.o
	g++ Table.o Cards.o Properties.o Player.o Avenue.o Monopoly.o -lncurses -o Monopoly

Monopoly.o:	Monopoly.cpp Player.h Avenue.h Properties.h Cards.h Table.h
	g++ -c Monopoly.cpp

Player.o:	Player.cpp Player.h Table.h
	g++ -c Player.cpp

Avenue.o:	Avenue.cpp Avenue.h Properties.h Table.h Player.h
	g++ -c Avenue.cpp

Properties.o:	Properties.cpp Properties.h Table.h Player.h
	g++ -c Properties.cpp

Cards.o:	Cards.cpp Cards.h Table.h
	g++ -c Cards.cpp

Table.o:	Table.cpp Table.h
	g++ -c Table.cpp

clean:
	rm -f *.o Monopoly

