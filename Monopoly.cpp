#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <time.h>
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
	srand (time(NULL));
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
						srand (time(NULL));
						drawDiceOne(dice1);
						drawDiceTwo(dice2);
						attroff(COLOR_PAIR(1));
						getch();
						int Espacio=Jugador1->getPosition()-1;
						cleanScreen();
						draw(Espacio+1);
						if (Espacio==2||Espacio==7||Espacio==17||Espacio==22||Espacio==33||Espacio==36)
						{
							//CARTAS DE COMMMUNITY CHEST Y FORTUNE						
						}else if (Espacio==4||Espacio==3){
							//TAXES
						}else if (Espacio==30){
							//GO TO JAIL
						}else if (Espacio==20||Espacio==10){
							//VISIT JAIL,FREE SPACE NO HACEN NADA SOLO ES EL DIBUJO
						}else{
							if (board.at(Espacio)->getOwned()==false)
							{	
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
					}else if(keyPlayer[0] == '6'){
						
						endwin();
						exit(0);
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
		mvprintw(1,3,"*********\n");
		mvprintw(2,3,"*       *\n");
		mvprintw(3,3,"*   *   *\n");
		mvprintw(4,3,"*       *\n");
		mvprintw(5,3,"*********\n");
	} else if (dice1 == 2){
		mvprintw(1,3,"*********\n");
		mvprintw(2,3,"*       *\n");
		mvprintw(3,3,"*  * *  *\n");
		mvprintw(4,3,"*       *\n");
		mvprintw(5,3,"*********\n");
	} else if (dice1 == 3) {
		mvprintw(1,3,"*********\n");
		mvprintw(2,3,"* *     *\n");
		mvprintw(3,3,"*   *   *\n");
		mvprintw(4,3,"*     * *\n");
		mvprintw(5,3,"*********\n");
	} else if (dice1 == 4) {
		mvprintw(1,3,"*********\n");
		mvprintw(2,3,"* *   * *\n");
		mvprintw(3,3,"*       *\n");
		mvprintw(4,3,"* *   * *\n");
		mvprintw(5,3,"*********\n");
	} else if (dice1 == 5) {
		mvprintw(1,3,"*********\n");
		mvprintw(2,3,"* *   * *\n");
		mvprintw(3,3,"*   *   *\n");
		mvprintw(4,3,"* *   * *\n");
		mvprintw(5,3,"*********\n");
	} else if (dice1 == 6) {
		mvprintw(1,3,"*********\n");
		mvprintw(2,3,"*  * *  *\n");
		mvprintw(3,3,"*  * *  *\n");
		mvprintw(4,3,"*  * *  *\n");
		mvprintw(5,3,"*********\n");
	}
}

void drawDiceTwo(int dice2){
	if (dice2 == 1){
		mvprintw(1,15,"*********\n");
		mvprintw(2,15,"*       *\n");
		mvprintw(3,15,"*   *   *\n");
		mvprintw(4,15,"*       *\n");
		mvprintw(5,15,"*********\n");
	} else if (dice2 == 2){
		mvprintw(1,15,"*********\n");
		mvprintw(2,15,"*       *\n");
		mvprintw(3,15,"*  * *  *\n");
		mvprintw(4,15,"*       *\n");
		mvprintw(5,15,"*********\n");
	} else if (dice2 == 3) {
		mvprintw(1,15,"*********\n");
		mvprintw(2,15,"* *     *\n");
		mvprintw(3,15,"*   *   *\n");
		mvprintw(4,15,"*     * *\n");
		mvprintw(5,15,"*********\n");
	} else if (dice2 == 4) {
		mvprintw(1,15,"*********\n");
		mvprintw(2,15,"* *   * *\n");
		mvprintw(3,15,"*       *\n");
		mvprintw(4,15,"* *   * *\n");
		mvprintw(5,15,"*********\n");
	} else if (dice2 == 5) {
		mvprintw(1,15,"*********\n");
		mvprintw(2,15,"* *   * *\n");
		mvprintw(3,15,"*   *   *\n");
		mvprintw(4,15,"* *   * *\n");
		mvprintw(5,15,"*********\n");
	} else if (dice2 == 6) {
		mvprintw(1,15,"*********\n");
		mvprintw(2,15,"*  * *  *\n");
		mvprintw(3,15,"*  * *  *\n");
		mvprintw(4,15,"*  * *  *\n");
		mvprintw(5,15,"*********\n");
	}
}
void draw(int space){
	int controlador = 0;
	string linea[15];
    linea[0] = "***********************\n";
    linea[2] = "***********************\n";
    linea[3] = "*                     *\n";
    linea[5] = "*                     *\n"; 
    linea[11] = "*                     *\n";
    linea[13] = "*                     *\n";  
    linea[14] = "***********************\n";
   
    if (space == 1){
    	init_color(COLOR_RED, 141, 73, 37);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*  Mediterranean Ave. *\n";
    	linea[4] = "*        Rent $2      *\n";
    	linea[6] = "*  1 house --->   $10 *\n";
    	linea[7] = "*  2 houses--->   $30 *\n";
    	linea[8] = "*  3 houses--->   $90 *\n";
    	linea[9] = "*  4 houses--->  $160 *\n";
    	linea[10] = "*  hotel------>  $250 *\n";
    	linea[12] = "*  Mortgage Value $30 *\n";
    }else if (space == 3){
    	init_color(COLOR_RED, 141, 73, 37);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*    Baltic Avenue    *\n";
    	linea[4] = "*        Rent $4      *\n";
    	linea[6] = "*  1 house --->   $20 *\n";
    	linea[7] = "*  2 houses--->   $60 *\n";
    	linea[8] = "*  3 houses--->  $180 *\n";
    	linea[9] = "*  4 houses--->  $320 *\n";
    	linea[10] = "*  hotel------>  $450 *\n";
    	linea[12] = "*  Mortgage Value $30 *\n";
    }else if (space == 6){
    	init_color(COLOR_BLUE, 100, 100, 400);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Oriental Avenue   *\n";
    	linea[4] = "*        Rent $6      *\n";
    	linea[6] = "*  1 house --->   $30 *\n";
    	linea[7] = "*  2 houses--->   $90 *\n";
    	linea[8] = "*  3 houses--->  $270 *\n";
    	linea[9] = "*  4 houses--->  $400 *\n";
    	linea[10] = "*  hotel------>  $550 *\n";
    	linea[12] = "*  Mortgage Value $50 *\n";
    }else if (space == 8){
    	init_color(COLOR_BLUE, 100, 100, 400);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Vermont Avenue    *\n";
    	linea[4] = "*        Rent $6      *\n";
    	linea[6] = "*  1 house --->   $30 *\n";
    	linea[7] = "*  2 houses--->   $90 *\n";
    	linea[8] = "*  3 houses--->  $270 *\n";
    	linea[9] = "*  4 houses--->  $400 *\n";
    	linea[10] = "*  hotel------>  $550 *\n";
    	linea[12] = "*  Mortgage Value $50 *\n";
    }else if (space == 9){
    	init_color(COLOR_BLUE, 100, 100, 400);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "* Connecticut Avenue  *\n";
    	linea[4] = "*        Rent $8      *\n";
    	linea[6] = "*  1 house --->   $40 *\n";
    	linea[7] = "*  2 houses--->  $100 *\n";
    	linea[8] = "*  3 houses--->  $300 *\n";
    	linea[9] = "*  4 houses--->  $450 *\n";
    	linea[10] = "*  hotel------>  $600 *\n";
    	linea[12] = "*  Mortgage Value $60 *\n";
    }else if (space == 11 || space == 13){
    	init_color(COLOR_RED, 400, 50, 150);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 11)linea[1] = "*  St. Charles Palce  *\n";
    	if (space == 13)linea[1] = "*    States Avenue    *\n";
    	linea[4] = "*       Rent $10      *\n";
    	linea[6] = "*  1 house --->   $50 *\n";
    	linea[7] = "*  2 houses--->  $150 *\n";
    	linea[8] = "*  3 houses--->  $450 *\n";
    	linea[9] = "*  4 houses--->  $650 *\n";
    	linea[10] = "*  hotel------>  $750 *\n";
    	linea[12] = "*  Mortgage Value $70 *\n";
    }else if (space == 14){
    	init_color(COLOR_RED, 400, 50, 150);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Virginia Avenue   *\n";
    	linea[4] = "*       Rent $12      *\n";
    	linea[6] = "*  1 house --->   $60 *\n";
    	linea[7] = "*  2 houses--->  $180 *\n";
    	linea[8] = "*  3 houses--->  $500 *\n";
    	linea[9] = "*  4 houses--->  $700 *\n";
    	linea[10] = "*  hotel------>  $900 *\n";
    	linea[12] = "*  Mortgage Value $80 *\n";
    }else if (space == 16 || space == 18){
    	init_color(COLOR_RED, 280, 220, 80);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 16)linea[1] = "*   ST. James Place   *\n";
    	if (space == 18)linea[1] = "*  Tennessee Avenue   *\n";	
    	linea[4] = "*       Rent $14      *\n";
    	linea[6] = "*  1 house --->   $70 *\n";
    	linea[7] = "*  2 houses--->  $200 *\n";
    	linea[8] = "*  3 houses--->  $550 *\n";
    	linea[9] = "*  4 houses--->  $750 *\n";
    	linea[10] = "*  hotel------>  $950 *\n";
    	linea[12] = "*  Mortgage Value $90 *\n";
    }else if (space == 19){
    	init_color(COLOR_RED, 280, 220, 80);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   New York Avenue   *\n";
    	linea[4] = "*       Rent $16      *\n";
    	linea[6] = "*  1 house --->   $80 *\n";
    	linea[7] = "*  2 houses--->  $220 *\n";
    	linea[8] = "*  3 houses--->  $600 *\n";
    	linea[9] = "*  4 houses--->  $800 *\n";
    	linea[10] = "* hotel------>  $1000 *\n";
    	linea[12] = "* Mortgage Value $100 *\n";
    }else if (space == 21 || space ==23){
    	init_color(COLOR_RED, 700,0,0);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 21)linea[1] = "*   Kentucky Avenue   *\n";
        if (space == 23)linea[1] = "*    Indiana Avenue   *\n";
    	linea[4] = "*       Rent $18      *\n";
    	linea[6] = "*  1 house --->   $90 *\n";
    	linea[7] = "*  2 houses--->  $250 *\n";
    	linea[8] = "*  3 houses--->  $700 *\n";
    	linea[9] = "*  4 houses--->  $875 *\n";
    	linea[10] = "*  hotel------> $1050 *\n";
    	linea[12] = "* Mortgage Value $110 *\n";
    }else if (space == 24){
    	init_color(COLOR_RED, 700,0,0);
    	init_pair(1,COLOR_WHITE,COLOR_RED);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Illinois Avenue   *\n";
    	linea[4] = "*       Rent $20      *\n";
    	linea[6] = "*  1 house --->  $1000 *\n";
    	linea[7] = "*  2 houses--->  $300 *\n";
    	linea[8] = "*  3 houses--->  $750 *\n";
    	linea[9] = "*  4 houses--->  $925 *\n";
    	linea[10] = "*  hotel------> $1100 *\n";
    	linea[12] = "* Mortgage Value $120 *\n";
    }else if (space == 26 || space == 27){
    	init_pair(1,COLOR_WHITE,COLOR_YELLOW);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 26)linea[1] = "*   Atlantic Avenue   *\n";
        if (space == 27)linea[1] = "*   Ventnor Avenue    *\n";
    	linea[4] = "*       Rent $22      *\n";
    	linea[6] = "*  1 house --->  $110 *\n";
    	linea[7] = "*  2 houses--->  $330 *\n";
    	linea[8] = "*  3 houses--->  $800 *\n";
    	linea[9] = "*  4 houses--->  $975 *\n";
    	linea[10] = "*  hotel------> $1150 *\n";
    	linea[12] = "* Mortgage Value $130 *\n";
    }else if (space == 29){
    	init_pair(1,COLOR_WHITE,COLOR_YELLOW);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*   Marvin Gardens    *\n";
    	linea[4] = "*       Rent $24      *\n";
    	linea[6] = "*  1 house --->  $120 *\n";
    	linea[7] = "*  2 houses--->  $360 *\n";
    	linea[8] = "*  3 houses--->  $850 *\n";
    	linea[9] = "*  4 houses---> $1025 *\n";
    	linea[10] = "*  hotel------> $1200 *\n";
    	linea[12] = "* Mortgage Value $140 *\n";
    }else if (space == 31 || space == 32){
    	init_pair(1,COLOR_WHITE,COLOR_GREEN);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
        if (space == 31)linea[1] = "*   Pacific Avenue    *\n";
        if (space == 32)linea[1] = "* North Carolina Av.  *\n";
    	linea[4] = "*       Rent $26      *\n";
    	linea[6] = "*  1 house --->  $130 *\n";
    	linea[7] = "*  2 houses--->  $390 *\n";
    	linea[8] = "*  3 houses--->  $900 *\n";
    	linea[9] = "*  4 houses---> $1100 *\n";
    	linea[10] = "*  hotel------> $1275 *\n";
    	linea[12] = "* Mortgage Value $150 *\n";
    }else if (space == 34){
    	init_pair(1,COLOR_WHITE,COLOR_GREEN);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*  Pensylvania Avenue *\n";
    	linea[4] = "*       Rent $28      *\n";
    	linea[6] = "*  1 house --->  $150 *\n";
    	linea[7] = "*  2 houses--->  $450 *\n";
    	linea[8] = "*  3 houses---> $1000 *\n";
    	linea[9] = "*  4 houses---> $1200 *\n";
    	linea[10] = "*  hotel------> $1400 *\n";
    	linea[12] = "* Mortgage Value $160 *\n";
    }else if (space == 37){
    	init_color(COLOR_BLUE,0,0,700);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*      Park Place     *\n";
    	linea[4] = "*       Rent $35      *\n";
    	linea[6] = "*  1 house --->  $175 *\n";
    	linea[7] = "*  2 houses--->  $500 *\n";
    	linea[8] = "*  3 houses---> $1100 *\n";
    	linea[9] = "*  4 houses---> $1300 *\n";
    	linea[10] = "*  hotel------> $1500 *\n";
    	linea[12] = "* Mortgage Value $175 *\n";
    }else if (space == 39){
    	init_color(COLOR_BLUE,0,0,700);
    	init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_BLACK,COLOR_WHITE);
    	linea[1] = "*       Boardwalk     *\n";
    	linea[4] = "*       Rent $35      *\n";
    	linea[6] = "*  1 house --->  $200 *\n";
    	linea[7] = "*  2 houses--->  $600 *\n";
    	linea[8] = "*  3 houses---> $1400 *\n";
    	linea[9] = "*  4 houses---> $1700 *\n";
    	linea[10] = "*  hotel------> $2000 *\n";
    	linea[12] = "* Mortgage Value $200 *\n";
    }else if (space == 5 || space == 15 || space == 25 || space == 35){
    	controlador = 1;
    	if(space == 5){
			linea[1] = "*   Reading Railroad       *";
		}else if(space == 15)
			linea[1] = "*   Pennsylvania R. R.     *";
		else if(space == 25)
			linea[1] = "*    B. & O. Railroad      *";
		else if(space == 35)
			linea[1] = "*     Short Line R. R.     *";
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************\n");
		mvprintw(11,20,"*        ***    ***        *\n");
		mvprintw(12,20,"*        *      **         *\n");
		mvprintw(13,20,"*        **********        *\n");
		mvprintw(14,20,"*       ************       *\n");
		mvprintw(15,20,"*        **********        *\n");
		mvprintw(16,20,"*         **    **         *\n");
		mvprintw(17,20,linea[1].c_str());
		mvprintw(18,20,"*    Rent ------>   $25    *\n");
		mvprintw(19,20,"* If 2 are owned--> $50    *\n");
		mvprintw(20,20,"* If 3 are owned-->$100    *\n");
		mvprintw(21,20,"* If 4 are owned-->$150    *\n");
		mvprintw(22,20,"*                          *\n");
		mvprintw(23,20,"* Mortgage Value ---> $100 *\n");
		mvprintw(24,20,"****************************\n");		
		attroff(COLOR_PAIR(1));
    }else if (space == 2 || space == 17 || space == 33){
    	controlador = 1;
		init_pair(1,COLOR_BLUE,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************\n");
		mvprintw(11,20,"*                          *\n");
		mvprintw(12,20,"*   *******************    *\n");
		mvprintw(13,20,"*   *      *   *      *    *\n");
		mvprintw(14,20,"*   *******************    *\n");
		mvprintw(15,20,"*   *      *   *      *    *\n");
		mvprintw(16,20,"*   *       ***       *    *\n");
		mvprintw(17,20,"*   *******************    *\n");
		mvprintw(18,20,"*                          *\n");
		mvprintw(19,20,"*                          *\n");
		mvprintw(20,20,"*        COMMUNITY         *\n");
		mvprintw(21,20,"*          CHEST           *\n");
		mvprintw(22,20,"*                          *\n");
		mvprintw(23,20,"****************************\n");
		attroff(COLOR_PAIR(1));
	}else if (space == 7 || space == 22 || space == 36){
		controlador = 1;
		init_pair(1,COLOR_BLUE,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************\n");
		mvprintw(11,20,"*                          *\n");
		mvprintw(12,20,"*          ??????          *\n");
		mvprintw(13,20,"*         ?      ?         *\n");
		mvprintw(14,20,"*        ?       ?         *\n");
		mvprintw(15,20,"*         ?      ?         *\n");
		mvprintw(16,20,"*               ?          *\n");
		mvprintw(17,20,"*              ?           *\n");
		mvprintw(18,20,"*             ?            *\n");
		mvprintw(19,20,"*            ?             *\n");
		mvprintw(20,20,"*            ?             *\n");
		mvprintw(21,20,"*                          *\n");
		mvprintw(22,20,"*            *             *\n");
		mvprintw(23,20,"****************************\n");
		attroff(COLOR_PAIR(1));
	}else if(space == 28){
		controlador = 1;
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************\n");
		mvprintw(11,20,"*          <==*==>         *\n");
		mvprintw(12,20,"*             |            *\n");
		mvprintw(13,20,"*     *     *****          *\n");
		mvprintw(14,20,"*     * **************     *\n");
		mvprintw(15,20,"*     * ***********  *     *\n");
		mvprintw(16,20,"*     *            * *     *\n");
		mvprintw(17,20,"*                  * *     *\n");
		mvprintw(18,20,"*       Water Works        *\n");
		mvprintw(19,20,"*  1 Service->rent 4 times *\n");
		mvprintw(20,20,"*  amount shown on dice.   *\n");
		mvprintw(21,20,"*2 Services->rent 10 times *\n");
		mvprintw(22,20,"*   amount shown on dice.  *\n");
		mvprintw(23,20,"*   Mortgage Value  $75    *\n");
		mvprintw(24,20,"****************************\n");
		attroff(COLOR_PAIR(1));
	} else if (space == 12){
		controlador = 1;
		init_pair(1,COLOR_BLACK,COLOR_WHITE);
		attron(COLOR_PAIR(1));
		mvprintw(10,20,"****************************\n");
		mvprintw(11,20,"*         *********        *\n");
		mvprintw(12,20,"*        *   * *   *       *\n");
		mvprintw(13,20,"*        * *  *  * *       *\n");
		mvprintw(14,20,"*         *  | |  *        *\n");
		mvprintw(15,20,"*          * | | *         *\n");
		mvprintw(16,20,"*           *****          *\n");
		mvprintw(17,20,"*           *---*          *\n");
		mvprintw(18,20,"*    Electronic Company    *\n");
		mvprintw(19,20,"*  1 Service->rent 4 times *\n");
		mvprintw(20,20,"*  amount shown on dice.   *\n");
		mvprintw(21,20,"*2 Services->rent 10 times *\n");
		mvprintw(22,20,"*   amount shown on dice.  *\n");
		mvprintw(23,20,"*   Mortgage Value  $75    *\n");
		mvprintw(24,20,"****************************\n");
		attroff(COLOR_PAIR(1));
	}
    if (controlador == 0)
    {
    	attron(COLOR_PAIR(1));
    	for (int i = 0; i < 15; i++)
    	{
    	    if (i >=3){
    	    attroff(COLOR_PAIR(1));
    	    attron(COLOR_PAIR(2));
    	}
    	    mvprintw(i+10,20,linea[i].c_str());
	    }    
    	attroff(COLOR_PAIR(2));    
    }

	
	
}
