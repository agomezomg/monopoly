#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "Table.h"
#include "Properties.h"
#include "Player.h"
#include "Avenue.h"
#include "Cards.h"
#include <vector>

using namespace std;

void boardPic();
void cleanScreen();
void drawDiceOne(int);
void drawDiceTwo(int);
void draw(int);

int main(int argc, char const *argv[])
{
	/*vector<Properties*> tablero;
	for (int i = 0; i < 40; ++i)
	{
		Properties* p;
		p = new Properties();
		p -> setAll(i);
		tablero.push_back(p);
	}

	for (int i = 0; i < tablero.size(); ++i)
	{
		if (i % 5 != 0)
		{
			Properties* temp = tablero.at(i);
			temp = dynamic_cast<Avenue*>(tablero.at(i));
			tablero.at(i) = temp;
		}
	}
	*/
	initscr();
	start_color();
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
		vector<Properties*> board;
		board.push_back(new Avenue(2,60,30,60,"Mediterranean Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"Community CHEST",false));
		board.push_back(new Avenue(4,60,30,60,"Valtic Avenue",false));
		board.push_back(new Avenue(4,60,30,60,"TAXES",false));
		board.push_back(new Avenue(2,60,30,60,"RailRoad",false));
		board.push_back(new Avenue(6,100,50,100,"Oriental Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"FORTUNE",false));
		board.push_back(new Avenue(6,100,50,100,"Connecticut Avenue",false));
		board.push_back(new Avenue(8,120,60,120,"Vermont Avenue",false));
		board.push_back(new Avenue(8,120,60,120,"VISIT JAIL",false));
		board.push_back(new Avenue(10,140,70,140,"Plaza San Carlos",false));
		board.push_back(new Avenue(2,60,30,60,"Electric Services",false));
		board.push_back(new Avenue(10,140,70,140,"Status Avenue",false));
		board.push_back(new Avenue(12,160,80,160,"Virginia Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"RailRoad",false));
		board.push_back(new Avenue(14,180,90,180,"Plaza SaintJames",false));
		board.push_back(new Avenue(14,180,90,180,"Community CHEST",false));
		board.push_back(new Avenue(14,180,90,180,"Tennessee Avenue",false));
		board.push_back(new Avenue(16,200,100,200,"New York Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"FREE SPACE",false));
		board.push_back(new Avenue(18,220,110,220,"Kentucky Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"FORTUNE",false));
		board.push_back(new Avenue(18,220,110,220,"Indiana Avenue",false));
		board.push_back(new Avenue(20,240,120,240,"Illinois Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"RailRoad",false));
		board.push_back(new Avenue(22,260,130,260,"Atlantic Avenue",false));
		board.push_back(new Avenue(22,260,130,260,"Vetnor Avenue",false));
		board.push_back(new Avenue(22,260,130,260,"Water Services",false));
		board.push_back(new Avenue(24,280,140,280,"Jardines Marvin Avenue",false));
		board.push_back(new Avenue(22,260,130,260,"GO TO JAIL",false));
		board.push_back(new Avenue(26,300,150,300,"Pacific Avenue",false));
		board.push_back(new Avenue(26,300,150,300,"North Carolina Avenue",false));
		board.push_back(new Avenue(26,300,150,300,"Community CHEST",false));
		board.push_back(new Avenue(28,300,150,300,"Pensylvania Avenue",false));
		board.push_back(new Avenue(26,300,150,300,"RailRoad",false));
		board.push_back(new Avenue(26,300,150,300,"FORTUNE",false));
		board.push_back(new Avenue(35,300,150,300,"Plaza Park",false));
		board.push_back(new Avenue(2,60,30,60,"TAXES",false));
		board.push_back(new Avenue(50,400,250,400,"Muelle Avenue",false));
		board.push_back(new Avenue(2,60,30,60,"GO",false));
		//Falta La Inicializacion de las fichas 
			Player* Jugador1=new Player("Juana",2000);
			Player* Jugador2=new Player("Juanito",2000);
			do
			{
				int ControlTurno=0,dice1=0,dice2=0;
				char keyPlayer[1];
				if (ControlTurno%2==0)
				{
					mvprintw(4,80, "Player %d",ControlTurno);
					mvprintw(4,89, Jugador1 -> getName().c_str());
					mvprintw(5,80,"Choose your option...");
					mvprintw(6,80,"1.-Throwing dice\n");
					mvprintw(7,80,"2.-See your properties\n");
					mvprintw(8,80,"3.-See your data\n");
					mvprintw(9,80,"4.-Sale Properties\n");
					mvprintw(10,80,"5.-Build on complete avenues\n");
					//QUE NO HAREMOS PROBABLEMENTE mvprintw(12,80,"6.-Trade\n");
					mvprintw(11,80,"6.-Quit no QUICK \n");
					mvprintw(12,80,"7.-Save Game for later \n");
					mvprintw(13,80,"Your option? -> ");
					getstr(keyPlayer);
					cleanScreen();
					if(keyPlayer[0] == '1'){//TIRAR EL DADO Y VALIDACIONES DE POSICION
						dice1 = (1 + rand() % 6);
						dice2 = (1 + rand() % 6);
						int spaces = dice1 + dice2;
						Jugador1 -> TurnControl(spaces);
						init_pair(1, COLOR_BLACK, COLOR_WHITE);
						attron(COLOR_PAIR(1));
						drawDiceOne(dice1);
						drawDiceTwo(dice2);
						attroff(COLOR_PAIR(1));
						getch();
						int Espacio=Jugador1->getPosition()-1;
						cleanScreen();
						Espacio++;
						draw(Espacio);
						if (Espacio==2||Espacio==7||Espacio==17||Espacio==22||Espacio==33||Espacio==36)
						{
							//CARTAS DE COMMMUNITY CHEST Y FORTUNE						
						}else if (Espacio==4||Espacio==38){
							//TAXES
						}else if (Espacio==30){
							//GO TO JAIL
						}else if (Espacio==20||Espacio==10){
							//VISIT JAIL,FREE SPACE NO HACEN NADA SOLO ES EL DIBUJO
						}else if(Espacio!=2&&Espacio!=7&&Espacio!=17&&Espacio!=22&&Espacio!=33&&Espacio!=36&&Espacio!=10&&Espacio!=38
							&&Espacio!=4&&Espacio!=20&&Espacio!=30){
							if (board.at(Espacio)->getOwned()==false)
							{	
								Espacio--;
								if (Jugador1->getMoneyOwned()<board.at(Espacio)->getPrice())
								{
									//HEY JUANA NO PUEDES COMPRAR ESTA PROPIEDAD NO TIENES LAS VARAS
								}else{
									char keyPlayer[1];
									mvprintw(6,80,"1.-Buy this Property\n");
									mvprintw(7,80,"2.-NO\n");
									getstr(keyPlayer);
									if (keyPlayer[0] == '1')
									{
									mvprintw(8,80,"Congrats you bought this property!\n");
									Jugador1->setMoneyOwned(board.at(Espacio)->getPrice());
									board.at(Espacio)->setOwned(true);
									Jugador1->setProperties(board.at(Espacio));
									}
								}						
							}else{//CUANDO ALGUIEN TIENE LA PROPIEDAD
								if (Jugador1->validarProperties(board.at(Espacio)->getTitle()))
								{
									mvprintw(8,80,"Esta Propiedad es tuya");	
								}else{//COBRARLE AL JUGADOR LA RENTA
									Jugador1->setMoneyOwned(board.at(Espacio)->getRent());
								}
							}
						}
						echo();
						//mvprintw(4,100,board.at(Espacio)->toString().c_str());
						getch();
						cleanScreen();
						mvprintw(10,80,"5.-JUST A PROVING\n");

					}else if(keyPlayer[0] == '2'){
						//Observar las propiedades
						mvprintw(16,80,Jugador1->getProperties().c_str());

					}else if(keyPlayer[0] == '3'){
						//Observar la Informacion del jugador
						mvprintw(15,80, Jugador1 -> toString().c_str());
					}
					//cleanScreen();
				}
		} while (true);
	}
}

void boardPic(){
	move(1,1);
}
void cleanScreen(){
	for (int i = 0; i < 300; i++){
		for (int j = 0; j <300; j++){
			mvprintw(i,j,"     .    ");
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
void draw(int option){
if(option == 1){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_WHITE,COLOR_BLACK);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*           Mediterranean Ave.         *\n");
		mvprintw(13,20,"*                                      *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*                Rent $2               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $10      *\n");
		mvprintw(20,20,"*       with 2 houses---->    $30      *\n");
		mvprintw(21,20,"*       with 3 houses---->    $90      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $160      *\n");
		mvprintw(23,20,"*       with hotel------->   $250      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $30          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 3){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_WHITE,COLOR_BLACK);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*               Baltic Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*                Rent $4               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $20      *\n");
		mvprintw(20,20,"*       with 2 houses---->    $60      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $180      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $320      *\n");
		mvprintw(23,20,"*       with hotel------->   $450      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $30          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 6){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_MAGENTA);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*              Vermont Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*                Rent $6               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $30      *\n");
		mvprintw(20,20,"*       with 2 houses---->    $90      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $270      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $400      *\n");
		mvprintw(23,20,"*       with hotel------->   $550      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $50          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 8){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_MAGENTA);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*             Oriental Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*                Rent $6               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $30      *\n");
		mvprintw(20,20,"*       with 2 houses---->    $90      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $270      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $400      *\n");
		mvprintw(23,20,"*       with hotel------->   $550      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $50          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 9){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_MAGENTA);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*            Connecticut Ave.          *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*                Rent $8               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $40      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $100      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $300      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $450      *\n");
		mvprintw(23,20,"*       with hotel------->   $600      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $60          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 11){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*               States Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $10               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $50      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $150      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $450      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $650      *\n");
		mvprintw(23,20,"*       with hotel------->   $750      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $70          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 13){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*           ST. Charles Place          *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $10               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $50      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $150      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $450      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $625      *\n");
		mvprintw(23,20,"*       with hotel------->   $750      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $70          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 14){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*              Virginia Ave.           *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $12               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $60      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $180      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $500      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $700      *\n");
		mvprintw(23,20,"*       with hotel------->   $900      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $80          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	}else if(option == 16){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_CYAN);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*              New York Ave.           *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $16               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $80      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $220      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $600      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $800      *\n");
		mvprintw(23,20,"*       with hotel------->  $1000      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*         Mortgage Value $100          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 18){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_CYAN);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*             Tennessee Ave.           *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $14               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $70      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $200      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $550      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $750      *\n");
		mvprintw(23,20,"*       with hotel------->   $950      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $90          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 19){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_CYAN);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*            ST. James Place           *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $14               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $70      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $200      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $550      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $750      *\n");
		mvprintw(23,20,"*       with hotel------->   $950      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $90          *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 21){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_RED);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*              Kentucky Ave.           *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $18               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $90      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $250      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $700      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $875      *\n");
		mvprintw(23,20,"*       with hotel------->  $1050      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $110         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 23){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_RED);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*              Indiana Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $18               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->    $90      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $250      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $700      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $875      *\n");
		mvprintw(23,20,"*       with hotel------->  $1050      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $110         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 24){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_RED);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*             Illionis Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $20               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $100      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $300      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $750      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $925      *\n");
		mvprintw(23,20,"*       with hotel------->  $1100      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $120         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 26){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_YELLOW);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*             Atlantic Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $22               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $110      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $330      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $800      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $975      *\n");
		mvprintw(23,20,"*       with hotel------->  $1150      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $130         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 27){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_YELLOW);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*             Ventnor Ave.             *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $22               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $110      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $330      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $800      *\n");
		mvprintw(22,20,"*       with 4 houses---->   $975      *\n");
		mvprintw(23,20,"*       with hotel------->  $1150      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $130         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 29){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_YELLOW);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*             Marvin Gardens           *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $24               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $120      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $360      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $850      *\n");
		mvprintw(22,20,"*       with 4 houses---->  $1025      *\n");
		mvprintw(23,20,"*       with hotel------->  $1200      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $140         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 31){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_GREEN);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*            No. Carolina Ave.         *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $26               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $130      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $390      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $900      *\n");
		mvprintw(22,20,"*       with 4 houses---->  $1100      *\n");
		mvprintw(23,20,"*       with hotel------->  $1275      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $150         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 32){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_GREEN);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*              Pacific Ave.            *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $26               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $130      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $390      *\n");
		mvprintw(21,20,"*       with 3 houses---->   $900      *\n");
		mvprintw(22,20,"*       with 4 houses---->  $1100      *\n");
		mvprintw(23,20,"*       with hotel------->  $1275      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $150         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 34){
 		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_GREEN);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*           Pennsylvania Ave.          *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $28               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $150      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $450      *\n");
		mvprintw(21,20,"*       with 3 houses---->  $1000      *\n");
		mvprintw(22,20,"*       with 4 houses---->  $1200      *\n");
		mvprintw(23,20,"*       with hotel------->  $1400      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $160         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 37){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_BLUE);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*               Park Place             *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $35               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $175      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $500      *\n");
		mvprintw(21,20,"*       with 3 houses---->  $1100      *\n");
		mvprintw(22,20,"*       with 4 houses---->  $1300      *\n");
		mvprintw(23,20,"*       with hotel------->  $1500      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $175         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	} else if(option == 39){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		init_pair(2,COLOR_BLACK,COLOR_BLUE);
		attron(COLOR_PAIR(2));
		mvprintw(10,20,"****************************************\n");
		mvprintw(11,20,"*                                      *\n");
		mvprintw(12,20,"*               Boardwalk              *\n");
		mvprintw(13,20,"*        	                           *\n");
		mvprintw(14,20,"****************************************\n");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(15,20,"*                                      *\n");
		mvprintw(16,20,"*               Rent $35               *\n");
		mvprintw(17,20,"*                                      *\n");
		mvprintw(18,20,"*                                      *\n");
		mvprintw(19,20,"*       with 1 house ---->   $200      *\n");
		mvprintw(20,20,"*       with 2 houses---->   $600      *\n");
		mvprintw(21,20,"*       with 3 houses---->  $1400      *\n");
		mvprintw(22,20,"*       with 4 houses---->  $1700      *\n");
		mvprintw(23,20,"*       with hotel------->  $2000      *\n");
		mvprintw(24,20,"*                                      *\n");
		mvprintw(25,20,"*                                      *\n");
		mvprintw(26,20,"*          Mortgage Value $200         *\n");
		mvprintw(27,20,"*                                      *\n");
		mvprintw(28,20,"*                                      *\n");
		mvprintw(29,20,"*                                      *\n");
		mvprintw(30,20,"****************************************\n");
		attroff(COLOR_PAIR(1));
 	}else if (option == 4||option==38){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*                                        *\n");
		mvprintw(13,20,"*    * *   *   ***   ***   *   * *****   *\n");
		mvprintw(14,20,"*    * **  *  *     *   *  ** ** *       *\n");
		mvprintw(15,20,"*    * * * * *     *     * * * * ***     *\n");
		mvprintw(16,20,"*    * *  **  *     *   *  *   * *       *\n");
		mvprintw(17,20,"*    * *   *   ***   ***   *   * *****   *\n");
		mvprintw(18,20,"*                                        *\n");
		mvprintw(19,20,"*           ***** ***** *   *            *\n");
		mvprintw(20,20,"*             *   *   *  * *             *\n");
		mvprintw(21,20,"*             *   *****   *              *\n");
		mvprintw(22,20,"*             *   *   *  * *             *\n");
		mvprintw(23,20,"*             *   *   * *   *            *\n");
		mvprintw(24,20,"*                                        *\n");
		mvprintw(25,20,"*                                        *\n");
		mvprintw(26,20,"*                                        *\n");
		mvprintw(27,20,"*                PAY $200                *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*                                        *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	}else if(option == 30){
		init_pair(1,COLOR_BLACK,COLOR_RED);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*                                        *\n");
		mvprintw(13,20,"*     ****** ******    ******* ******    *\n");
		mvprintw(14,20,"*     *      *    *       *    *    *    *\n");
		mvprintw(15,20,"*     *      *    *       *    *    *    *\n");
		mvprintw(16,20,"*     *   ** *    *       *    *    *    *\n");
		mvprintw(17,20,"*     *    * *    *       *    *    *    *\n");
		mvprintw(18,20,"*     ****** ******       *    ******    *\n");
		mvprintw(19,20,"*                                        *\n");
		mvprintw(20,20,"*         *******  ******  *  *          *\n");
		mvprintw(21,20,"*            *     *    *  *  *          *\n");
		mvprintw(22,20,"*            *     *    *  *  *          *\n");
		mvprintw(23,20,"*            *     ******  *  *          *\n");
		mvprintw(24,20,"*            *     *    *  *  *          *\n");
		mvprintw(25,20,"*         ****     *    *  *  *****      *\n");
		mvprintw(26,20,"*           _____________________        *\n");
		mvprintw(27,20,"*           |   |   |   |   |   |        *\n");
		mvprintw(28,20,"*           |   |   |   |   |   |        *\n");
		mvprintw(29,20,"*           |___|___|___|___|___|        *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	} else if(option == 10){
		init_pair(1,COLOR_WHITE,COLOR_RED);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*        |                               *\n");
		mvprintw(12,20,"*        |                               *\n");
		mvprintw(13,20,"*        |                               *\n");
		mvprintw(14,20,"*        |                               *\n");
		mvprintw(15,20,"*        |                               *\n");
		mvprintw(16,20,"*        |                               *\n");
		mvprintw(17,20,"*        |                               *\n");
		mvprintw(18,20,"*        |                               *\n");
		mvprintw(19,20,"*        |                               *\n");
		mvprintw(20,20,"*        |                               *\n");
		mvprintw(21,20,"*        |                               *\n");
		mvprintw(22,20,"*        |                               *\n");
		mvprintw(23,20,"*        |                               *\n");
		mvprintw(24,20,"*        |                               *\n");
		mvprintw(25,20,"*        |                               *\n");
		mvprintw(26,20,"*        |_____________________________  *\n");
		mvprintw(27,20,"*                                        *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*                                        *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	}else if (option == 2 || option == 17 || option == 33){
		init_pair(1,COLOR_BLUE,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*                                        *\n");
		mvprintw(13,20,"*                                        *\n");
		mvprintw(14,20,"*    ********************************    *\n");
		mvprintw(15,20,"*    *            *   *             *    *\n");
		mvprintw(16,20,"*    ********************************    *\n");
		mvprintw(17,20,"*    *            *   *             *    *\n");
		mvprintw(18,20,"*    *             ***              *    *\n");
		mvprintw(19,20,"*    *                              *    *\n");
		mvprintw(20,20,"*    *                              *    *\n");
		mvprintw(21,20,"*    ********************************    *\n");
		mvprintw(22,20,"*                                        *\n");
		mvprintw(23,20,"*                                        *\n");
		mvprintw(24,20,"*                                        *\n");
		mvprintw(25,20,"*               COMMUNITY                *\n");
		mvprintw(26,20,"*                 CHEST                  *\n");
		mvprintw(27,20,"*                                        *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*                                        *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	}else if (option == 7 || option == 22 || option == 36){
		init_pair(1,COLOR_BLUE,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*                ???????                 *\n");
		mvprintw(13,20,"*               ??     ??                *\n");
		mvprintw(14,20,"*              ??       ??               *\n");
		mvprintw(15,20,"*               ??      ??               *\n");
		mvprintw(16,20,"*                      ??                *\n");
		mvprintw(17,20,"*                     ??                 *\n");
		mvprintw(18,20,"*                  ????                  *\n");
		mvprintw(19,20,"*                  ????                  *\n");
		mvprintw(20,20,"*                  ????                  *\n");
		mvprintw(21,20,"*                  ????                  *\n");
		mvprintw(22,20,"*                  ????                  *\n");
		mvprintw(23,20,"*                  ????                  *\n");
		mvprintw(24,20,"*                  ????                  *\n");
		mvprintw(25,20,"*                  ????                  *\n");
		mvprintw(26,20,"*                                        *\n");
		mvprintw(27,20,"*                   **                   *\n");
		mvprintw(28,20,"*                  ****                  *\n");
		mvprintw(29,20,"*                   **                   *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	}else if(option == 28){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                <===*===>               *\n");
		mvprintw(12,20,"*                    |                   *\n");
		mvprintw(13,20,"*           *      *****                 *\n");
		mvprintw(14,20,"*          * ***************             *\n");
		mvprintw(15,20,"*          * *              *            *\n");
		mvprintw(16,20,"*          * *               *           *\n");
		mvprintw(17,20,"*          * ************     *          *\n");
		mvprintw(18,20,"*           *            *    *          *\n");
		mvprintw(19,20,"*                         *   *          *\n");
		mvprintw(20,20,"*                         *   *          *\n");
		mvprintw(21,20,"*                         *****          *\n");
		mvprintw(22,20,"*   ----------------------------------   *\n");
		mvprintw(23,20,"*                Water Works             *\n");
		mvprintw(24,20,"*   ----------------------------------   *\n");
		mvprintw(25,20,"*   If one Service is owned rent is 4    *\n");
		mvprintw(26,20,"*   times amount shown on dice.          *\n");
		mvprintw(27,20,"*   If both Services are owned rent is   *\n");
		mvprintw(28,20,"*   10 times amount shown on dice.       *\n");
		mvprintw(29,20,"*                                        *\n");
		mvprintw(30,20,"*          Mortgage Value  $75           *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	} else if (option == 12){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*               ***********              *\n");
		mvprintw(12,20,"*              *   *   *   *             *\n");
		mvprintw(13,20,"*             *   * * * *   *            *\n");
		mvprintw(14,20,"*             *   *  *  *   *            *\n");
		mvprintw(15,20,"*             *    *_*_*    *            *\n");
		mvprintw(16,20,"*              *    | |    *             *\n");
		mvprintw(17,20,"*               *   | |   *              *\n");
		mvprintw(18,20,"*                *  | |  *               *\n");
		mvprintw(19,20,"*                 *******                *\n");
		mvprintw(20,20,"*                 *-----*                *\n");
		mvprintw(21,20,"*                 *******                *\n");
		mvprintw(22,20,"*   ----------------------------------   *\n");
		mvprintw(23,20,"*            Electronic Company          *\n");
		mvprintw(24,20,"*   ----------------------------------   *\n");
		mvprintw(25,20,"*   If one Service is owned rent is 4    *\n");
		mvprintw(26,20,"*   times amount shown on dice.          *\n");
		mvprintw(27,20,"*   If both Services are owned rent is   *\n");
		mvprintw(28,20,"*   10 times amount shown on dice.       *\n");
		mvprintw(29,20,"*                                        *\n");
		mvprintw(30,20,"*          Mortgage Value  $75           *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	}else if(option == 5){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*               ***      ****            *\n");
		mvprintw(13,20,"*               *        ***             *\n");
		mvprintw(14,20,"*               *************            *\n");
		mvprintw(15,20,"*              ***************           *\n");
		mvprintw(16,20,"*               ***************          *\n");
		mvprintw(17,20,"*                *  ***    ***           *\n");
		mvprintw(18,20,"*               ** *****  *****          *\n");
		mvprintw(19,20,"*              ***  ***    ***           *\n");
		mvprintw(20,20,"*   ----------------------------------   *\n");
		mvprintw(21,20,"*             B. & O. Railroad           *\n");
		mvprintw(22,20,"*   ----------------------------------   *\n");
		mvprintw(23,20,"*                                        *\n");
		mvprintw(24,20,"*      Rent        ------>        $25    *\n");
		mvprintw(25,20,"*      If 2 R.R.'s are owned -->  $50    *\n");
		mvprintw(26,20,"*      If 3 R.R.'s are owned --> $100    *\n");
		mvprintw(27,20,"*      If 4 R.R.'s are owned --> $150    *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*         Mortgage Value ---> $100       *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	} else if (option == 15){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*               ***      ****            *\n");
		mvprintw(13,20,"*               *        ***             *\n");
		mvprintw(14,20,"*               *************            *\n");
		mvprintw(15,20,"*              ***************           *\n");
		mvprintw(16,20,"*               ***************          *\n");
		mvprintw(17,20,"*                *  ***    ***           *\n");
		mvprintw(18,20,"*               ** *****  *****          *\n");
		mvprintw(19,20,"*              ***  ***    ***           *\n");
		mvprintw(20,20,"*   ----------------------------------   *\n");
		mvprintw(21,20,"*             Short Line R. R.           *\n");
		mvprintw(22,20,"*   ----------------------------------   *\n");
		mvprintw(23,20,"*                                        *\n");
		mvprintw(24,20,"*      Rent        ------>        $25    *\n");
		mvprintw(25,20,"*      If 2 R.R.'s are owned -->  $50    *\n");
		mvprintw(26,20,"*      If 3 R.R.'s are owned --> $100    *\n");
		mvprintw(27,20,"*      If 4 R.R.'s are owned --> $150    *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*         Mortgage Value ---> $100       *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	} else if (option == 25){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*               ***      ****            *\n");
		mvprintw(13,20,"*               *        ***             *\n");
		mvprintw(14,20,"*               *************            *\n");
		mvprintw(15,20,"*              ***************           *\n");
		mvprintw(16,20,"*               ***************          *\n");
		mvprintw(17,20,"*                *  ***    ***           *\n");
		mvprintw(18,20,"*               ** *****  *****          *\n");
		mvprintw(19,20,"*              ***  ***    ***           *\n");
		mvprintw(20,20,"*   ----------------------------------   *\n");
		mvprintw(21,20,"*             Reading Railroad           *\n");
		mvprintw(22,20,"*   ----------------------------------   *\n");
		mvprintw(23,20,"*                                        *\n");
		mvprintw(24,20,"*      Rent        ------>        $25    *\n");
		mvprintw(25,20,"*      If 2 R.R.'s are owned -->  $50    *\n");
		mvprintw(26,20,"*      If 3 R.R.'s are owned --> $100    *\n");
		mvprintw(27,20,"*      If 4 R.R.'s are owned --> $150    *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*         Mortgage Value ---> $100       *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	} else if (option == 35){
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"******************************************\n");
		mvprintw(11,20,"*                                        *\n");
		mvprintw(12,20,"*               ***      ****            *\n");
		mvprintw(13,20,"*               *        ***             *\n");
		mvprintw(14,20,"*               *************            *\n");
		mvprintw(15,20,"*              ***************           *\n");
		mvprintw(16,20,"*               ***************          *\n");
		mvprintw(17,20,"*                *  ***    ***           *\n");
		mvprintw(18,20,"*               ** *****  *****          *\n");
		mvprintw(19,20,"*              ***  ***    ***           *\n");
		mvprintw(20,20,"*   ----------------------------------   *\n");
		mvprintw(21,20,"*            Pennsylvania R. R.          *\n");
		mvprintw(22,20,"*   ----------------------------------   *\n");
		mvprintw(23,20,"*                                        *\n");
		mvprintw(24,20,"*      Rent        ------>        $25    *\n");
		mvprintw(25,20,"*      If 2 R.R.'s are owned -->  $50    *\n");
		mvprintw(26,20,"*      If 3 R.R.'s are owned --> $100    *\n");
		mvprintw(27,20,"*      If 4 R.R.'s are owned --> $150    *\n");
		mvprintw(28,20,"*                                        *\n");
		mvprintw(29,20,"*         Mortgage Value ---> $100       *\n");
		mvprintw(30,20,"*                                        *\n");
		mvprintw(31,20,"******************************************\n");
		attroff(COLOR_PAIR(1));
	}
}
