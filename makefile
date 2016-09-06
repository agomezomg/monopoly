Monopoly:	Table.o Cards.o Properties.o Player.o Avenues.o Monopoly.o
	g++ Table.o Cards.o Properties.o Player.o Avenues.o Monopoly.o -lncurses -o pruebame

Monopoly.o:	Monopoly.cpp Player.h Avenues.h Properties.h Cards.h Table.h
	g++ -c Monopoly.cpp

Player.o:	Player.cpp Player.h Table.h
	g++ -c Player.cpp

Avenues.o:	Avenues.cpp Avenues.h Properties.h Table.h Player.h
	g++ -c avenues.cpp

Properties.o:	Properties.cpp Properties.h Table.h player.h
	g++ -c Properties.cpp

Cards.o:	Cards.cpp Cards.h Table.h
	g++ -c cards.cpp

Table.o:	Table.cpp Table.h
	g++ -c Table.cpp

clean:
	rm -f *.o Monopoly
