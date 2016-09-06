#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "Table.h"
#include "Properties.h"
#include "Player.h"
#include "Avenue.h"
#include "Cards.h"
void boardPic();
void cleanScreen();


int main(int argc, char const *argv[])
{
	initscr();
	echo();
	char key[1];
	boardPic();
	//srand(time(0));
	move(4,80);
	printw("WELCOME TO MONOPOLY");
	move(8,80);
	printw("NEW GAME --> TAP N");
	move(10,80);
	printw("LOAD GAME -> TAP L");
	move(12,80);
	printw("EXIT ------> TAP E");
	move(14,80);
	printw("OPTION: ");
	getstr(key);
	cleanScreen();
	endwin();
	int ContTurno=0;
	if(key[0] == 'n' || key[0] == 'N'){
		/*board.push_back(new go());
		board.push_back(new avenues(60,30,false,2));
		board.push_back(new community());
		board.push_back(new avenues(60,30,false,4));
		board.push_back(new tax());
		board.push_back(new railway(200,100,false,25));
		board.push_back(new avenues(100,50,false,6));
		board.push_back(new chance());
		board.push_back(new avenues(100,50,false,6));
		board.push_back(new avenues(120,60,false,8));
		board.push_back(new jail());
		board.push_back(new avenues(140,70,false,10));
		board.push_back(new services(150,75,false,0));
		board.push_back(new avenues(140,70,false,10));
		board.push_back(new avenues(160,80,false,12));
		board.push_back(new railway(200,100,false,25));
		board.push_back(new avenues(180,90,false,14));
		board.push_back(new community());
		board.push_back(new avenues(180,90,false,14));
		board.push_back(new avenues(200,100,false,16));
		board.push_back(new freeSquare());
		board.push_back(new avenues(220,110,false,18));
		board.push_back(new chance());
		board.push_back(new avenues(220,110,false,18));
		board.push_back(new avenues(240,120,false,20));
		board.push_back(new railway(200,100,false,25));
		board.push_back(new avenues(260,130,false,22));
		board.push_back(new avenues(260,130,false,22));
		board.push_back(new services(150,75,false,0));
		board.push_back(new avenues(280,140,false,24));
		board.push_back(new jail());
		board.push_back(new avenues(300,150,false,26));
		board.push_back(new avenues(300,150,false,26));
		board.push_back(new community());
		board.push_back(new avenues(320,160,false,28));
		board.push_back(new railway(200,100,false,25));
		board.push_back(new chance());
		board.push_back(new avenues(350,175,false,35));
		board.push_back(new tax());
		board.push_back(new avenues(400,200,false,50));*/
		//Falta La Inicializacion de las fichas 
			Player* Jugador1=new Player(Juana,2000);
			Player* Jugador2=new Player(Juanito,2000);
			do
			{
				int ControlTurno=0,dice1=0,dice2=0;
				char keyPlayer[1];
				if (ControlTurno%2==0)
				{
					mvprintw(4,80, "Player %d",ControlTurno);
					mvprintw(4,89, player1 -> getName());
					mvprintw(5,80,"Choose your option...");
					mvprintw(6,80,"1.-Throwing dice\n");
					mvprintw(7,80,"2.-See your properties\n");
					mvprintw(8,80,"3.-See your data\n");
					mvprintw(9,80,"4.-Quick\n");
					mvprintw(10,80,"5.-Save game\n");
					mvprintw(11,80,"6.-End of the game\n");
					mvprintw(12,80,"Your option? -> ");
					getstr(keyPlayer);
					if(keyPlayer[0] == '1'){
						dice1 = (1 + rand() % 6);
						dice2 = (1 + rand() % 6);
						spaces = dice1 + dice2;
						player1 -> setTurn(spaces);
						init_pair(1, COLOR_BLACK, COLOR_WHITE);
						attron(COLOR_PAIR(1));
						drawDiceOne(dice1);
						drawDiceTwo(dice2);
						attroff(COLOR_PAIR(1));
						noecho();
						//getch();
						cleanScreen();
						board.at(player1 -> getTurn()) -> printSquare(player1 -> getTurn());
						mvprintw(32,20, board.at(player1 -> getTurn()) -> toString().c_str());
						getch();
						echo();
						getch();
						cleanScreen();
						ControlTurno++;
					}/* else if (keyPlayer[0] == '2'){
								
				}*/
		} while (false!=false);
	}
}

void boardPic(){
	move(1,1);
}
void cleanScreen(){
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLS; j++){
			mvprintw(i,j," ");
		}
	}
}

void drawDiceOne(int dice1){
	if (dice1 == 1){
		mvprintw(1,3,"*******************************\n");
		mvprintw(2,3,"*                             *\n");
		mvprintw(3,3,"*                             *\n");
		mvprintw(4,3,"*                             *\n");
		mvprintw(5,3,"*                             *\n");
		mvprintw(6,3,"*                             *\n");
		mvprintw(7,3,"*             ***             *\n");
		mvprintw(8,3,"*             ***             *\n");
		mvprintw(9,3,"*             ***             *\n");
		mvprintw(10,3,"*                             *\n");
		mvprintw(11,3,"*                             *\n");
		mvprintw(12,3,"*                             *\n");
		mvprintw(13,3,"*                             *\n");
		mvprintw(14,3,"*                             *\n");
		mvprintw(15,3,"*******************************\n");
	} else if (dice1 == 2){
		mvprintw(1,3,"*******************************\n");
		mvprintw(2,3,"*                             *\n");
		mvprintw(3,3,"*                             *\n");
		mvprintw(4,3,"*                             *\n");
		mvprintw(5,3,"*                             *\n");
		mvprintw(6,3,"*                             *\n");
		mvprintw(7,3,"*      ***           ***      *\n");
		mvprintw(8,3,"*      ***           ***      *\n");
		mvprintw(9,3,"*      ***           ***      *\n");
		mvprintw(10,3,"*                             *\n");
		mvprintw(11,3,"*                             *\n");
		mvprintw(12,3,"*                             *\n");
		mvprintw(13,3,"*                             *\n");
		mvprintw(14,3,"*                             *\n");
		mvprintw(15,3,"*******************************\n");
	} else if (dice1 == 3) {
		mvprintw(1,3,"*******************************\n");
		mvprintw(2,3,"*                             *\n");
		mvprintw(3,3,"*     ***                     *\n");
		mvprintw(4,3,"*     ***                     *\n");
		mvprintw(5,3,"*     ***                     *\n");
		mvprintw(6,3,"*                             *\n");
		mvprintw(7,3,"*             ***             *\n");
		mvprintw(8,3,"*             ***             *\n");
		mvprintw(9,3,"*             ***             *\n");
		mvprintw(10,3,"*                             *\n");
		mvprintw(11,3,"*                     ***     *\n");
		mvprintw(12,3,"*                     ***     *\n");
		mvprintw(13,3,"*                     ***     *\n");
		mvprintw(14,3,"*                             *\n");
		mvprintw(15,3,"*******************************\n");
	} else if (dice1 == 4) {
		mvprintw(1,3,"*******************************\n");
		mvprintw(2,3,"*                             *\n");
		mvprintw(3,3,"*     ***             ***     *\n");
		mvprintw(4,3,"*     ***             ***     *\n");
		mvprintw(5,3,"*     ***             ***     *\n");
		mvprintw(6,3,"*                             *\n");
		mvprintw(7,3,"*                             *\n");
		mvprintw(8,3,"*                             *\n");
		mvprintw(9,3,"*                             *\n");
		mvprintw(10,3,"*                             *\n");
		mvprintw(11,3,"*     ***             ***     *\n");
		mvprintw(12,3,"*     ***             ***     *\n");
		mvprintw(13,3,"*     ***             ***     *\n");
		mvprintw(14,3,"*                             *\n");
		mvprintw(15,3,"*******************************\n");
	} else if (dice1 == 5) {
		mvprintw(1,3,"*******************************\n");
		mvprintw(2,3,"*                             *\n");
		mvprintw(3,3,"*     ***             ***     *\n");
		mvprintw(4,3,"*     ***             ***     *\n");
		mvprintw(5,3,"*     ***             ***     *\n");
		mvprintw(6,3,"*                             *\n");
		mvprintw(7,3,"*             ***             *\n");
		mvprintw(8,3,"*             ***             *\n");
		mvprintw(9,3,"*             ***             *\n");
		mvprintw(10,3,"*                             *\n");
		mvprintw(11,3,"*     ***             ***     *\n");
		mvprintw(12,3,"*     ***             ***     *\n");
		mvprintw(13,3,"*     ***             ***     *\n");
		mvprintw(14,3,"*                             *\n");
		mvprintw(15,3,"*******************************\n");
	} else if (dice1 == 6) {
		mvprintw(1,3,"*******************************\n");
		mvprintw(1,3,"*                             *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*                             *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*                             *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*     ***             ***     *\n");
		mvprintw(1,3,"*                             *\n");
		mvprintw(1,3,"*******************************\n");
	}
}

void drawDiceTwo(int dice2){
	if (dice2 == 1){
		mvprintw(1,36,"*******************************\n");
		mvprintw(2,36,"*                             *\n");
		mvprintw(3,36,"*                             *\n");
		mvprintw(4,36,"*                             *\n");
		mvprintw(5,36,"*                             *\n");
		mvprintw(6,36,"*                             *\n");
		mvprintw(7,36,"*             ***             *\n");
		mvprintw(8,36,"*             ***             *\n");
		mvprintw(9,36,"*             ***             *\n");
		mvprintw(10,36,"*                             *\n");
		mvprintw(11,36,"*                             *\n");
		mvprintw(12,36,"*                             *\n");
		mvprintw(13,36,"*                             *\n");
		mvprintw(14,36,"*                             *\n");
		mvprintw(15,36,"*******************************\n");
	} else if (dice2 == 2){
		mvprintw(1,36,"*******************************\n");
		mvprintw(2,36,"*                             *\n");
		mvprintw(3,36,"*                             *\n");
		mvprintw(4,36,"*                             *\n");
		mvprintw(5,36,"*                             *\n");
		mvprintw(6,36,"*                             *\n");
		mvprintw(7,36,"*      ***           ***      *\n");
		mvprintw(8,36,"*      ***           ***      *\n");
		mvprintw(9,36,"*      ***           ***      *\n");
		mvprintw(10,36,"*                             *\n");
		mvprintw(11,36,"*                             *\n");
		mvprintw(12,36,"*                             *\n");
		mvprintw(13,36,"*                             *\n");
		mvprintw(14,36,"*                             *\n");
		mvprintw(15,36,"*******************************\n");
	} else if (dice2 == 3) {
		mvprintw(1,36,"*******************************\n");
		mvprintw(2,36,"*                             *\n");
		mvprintw(3,36,"*     ***                     *\n");
		mvprintw(4,36,"*     ***                     *\n");
		mvprintw(5,36,"*     ***                     *\n");
		mvprintw(6,36,"*                             *\n");
		mvprintw(7,36,"*             ***             *\n");
		mvprintw(8,36,"*             ***             *\n");
		mvprintw(9,36,"*             ***             *\n");
		mvprintw(10,36,"*                             *\n");
		mvprintw(11,36,"*                     ***     *\n");
		mvprintw(12,36,"*                     ***     *\n");
		mvprintw(13,36,"*                     ***     *\n");
		mvprintw(14,36,"*                             *\n");
		mvprintw(15,36,"*******************************\n");
	} else if (dice2 == 4) {
		mvprintw(1,36,"*******************************\n");
		mvprintw(2,36,"*                             *\n");
		mvprintw(3,36,"*     ***             ***     *\n");
		mvprintw(4,36,"*     ***             ***     *\n");
		mvprintw(5,36,"*     ***             ***     *\n");
		mvprintw(6,36,"*                             *\n");
		mvprintw(7,36,"*                             *\n");
		mvprintw(8,36,"*                             *\n");
		mvprintw(9,36,"*                             *\n");
		mvprintw(10,36,"*                             *\n");
		mvprintw(11,36,"*     ***             ***     *\n");
		mvprintw(12,36,"*     ***             ***     *\n");
		mvprintw(13,36,"*     ***             ***     *\n");
		mvprintw(14,36,"*                             *\n");
		mvprintw(15,36,"*******************************\n");
	} else if (dice2 == 5) {
		mvprintw(1,36,"*******************************\n");
		mvprintw(2,36,"*                             *\n");
		mvprintw(3,36,"*     ***             ***     *\n");
		mvprintw(4,36,"*     ***             ***     *\n");
		mvprintw(5,36,"*     ***             ***     *\n");
		mvprintw(6,36,"*                             *\n");
		mvprintw(7,36,"*             ***             *\n");
		mvprintw(8,36,"*             ***             *\n");
		mvprintw(9,36,"*             ***             *\n");
		mvprintw(10,36,"*                             *\n");
		mvprintw(11,36,"*     ***             ***     *\n");
		mvprintw(12,36,"*     ***             ***     *\n");
		mvprintw(13,36,"*     ***             ***     *\n");
		mvprintw(14,36,"*                             *\n");
		mvprintw(15,36,"*******************************\n");
	} else if (dice2 == 6) {
		mvprintw(1,36,"*******************************\n");
		mvprintw(2,36,"*                             *\n");
		mvprintw(3,36,"*     ***             ***     *\n");
		mvprintw(4,36,"*     ***             ***     *\n");
		mvprintw(5,36,"*     ***             ***     *\n");
		mvprintw(6,36,"*                             *\n");
		mvprintw(7,36,"*     ***             ***     *\n");
		mvprintw(8,36,"*     ***             ***     *\n");
		mvprintw(9,36,"*     ***             ***     *\n");
		mvprintw(10,36,"*                             *\n");
		mvprintw(11,36,"*     ***             ***     *\n");
		mvprintw(12,36,"*     ***             ***     *\n");
		mvprintw(13,36,"*     ***             ***     *\n");
		mvprintw(14,36,"*                             *\n");
		mvprintw(15,36,"*******************************\n");
	}
}