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
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>


using namespace std;

void boardPic();
void cleanScreen();
void drawDiceOne(int);
void drawDiceTwo(int);
void draw(int);
int drawCard();
bool ifJail();
void init_curses();
void drawSpace3(WINDOW *, int);
void drawSpace4(WINDOW *, int);
void drawBoard();

int main(int argc, char const *argv[1])
{
	initscr();
	start_color();
	//use_default_colors();
	drawBoard();
	echo();
	char key[1];
	boardPic();
	//srand(time(0));
	bool Load=true;
	int ContTurno=0;
	
	vector<Properties*> board;
	Player* Jugador1;
	Player* Jugador2;

	int ControlTurno = 0;
	
	do{
		move(4,115);
		printw("WELCOME TO MONOPOLY");
		move(8,115);
		printw("NEW GAME --> TAP N");
		move(10,115);
		printw("LOAD GAME -> TAP L");
		move(12,115);
		printw("EXIT ------> TAP E");
		move(14,115);
		printw("OPTION: ");
		getstr(key);
		cleanScreen();
		endwin();

		if(key[0] == 'n' || key[0] == 'N'){
			if(Load==true)
			{	
				board.push_back(new Avenue(2,60,30,60,"Mediterranean-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"Community-CHEST",false));
				board.push_back(new Avenue(4,60,30,60,"Valtic-Avenue",false));
				board.push_back(new Avenue(4,60,30,60,"TAXES",false));
				board.push_back(new Avenue(2,60,30,60,"RailRoad",false));
				board.push_back(new Avenue(6,100,50,100,"Oriental-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"FORTUNE",false));
				board.push_back(new Avenue(6,100,50,100,"Connecticut-Avenue",false));
				board.push_back(new Avenue(8,120,60,120,"Vermont-Avenue",false));
				board.push_back(new Avenue(8,120,60,120,"VISIT-JAIL",false));
				board.push_back(new Avenue(10,140,70,140,"Plaza-San-Carlos",false));
				board.push_back(new Avenue(2,60,30,60,"Electric-Services",false));
				board.push_back(new Avenue(10,140,70,140,"Status-Avenue",false));
				board.push_back(new Avenue(12,160,80,160,"Virginia-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"RailRoad",false));
				board.push_back(new Avenue(14,180,90,180,"Plaza-SaintJames",false));
				board.push_back(new Avenue(14,180,90,180,"Community-CHEST",false));
				board.push_back(new Avenue(14,180,90,180,"Tennessee-Avenue",false));
				board.push_back(new Avenue(16,200,100,200,"New-York-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"FREE-SPACE",false));
				board.push_back(new Avenue(18,220,110,220,"Kentucky-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"FORTUNE",false));
				board.push_back(new Avenue(18,220,110,220,"Indiana-Avenue",false));
				board.push_back(new Avenue(20,240,120,240,"Illinois-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"RailRoad",false));
				board.push_back(new Avenue(22,260,130,260,"Atlantic-Avenue",false));
				board.push_back(new Avenue(22,260,130,260,"Ventnor-Avenue",false));
				board.push_back(new Avenue(22,260,130,260,"Water-Services",false));
				board.push_back(new Avenue(24,280,140,280,"Jardines-Marvin-Avenue",false));
				board.push_back(new Avenue(22,260,130,260,"GO-TO-JAIL",false));
				board.push_back(new Avenue(26,300,150,300,"Pacific-Avenue",false));
				board.push_back(new Avenue(26,300,150,300,"North-Carolina-Avenue",false));
				board.push_back(new Avenue(26,300,150,300,"Community-CHEST",false));
				board.push_back(new Avenue(28,300,150,300,"Pennsylvania-Avenue",false));
				board.push_back(new Avenue(26,300,150,300,"RailRoad",false));
				board.push_back(new Avenue(26,300,150,300,"FORTUNE",false));
				board.push_back(new Avenue(35,300,150,300,"Plaza-Park",false));
				board.push_back(new Avenue(2,60,30,60,"TAXES",false));
				board.push_back(new Avenue(50,400,250,400,"Muelle-Avenue",false));
				board.push_back(new Avenue(2,60,30,60,"GO",false));
				//Falta La Inicializacion de las fichas
				//que fichas? ^^^
				Jugador1 = new Player("Aceituno",1500);
				Jugador2 = new Player("Herbert",1500); //para que jueguen juntos, diversion en familia (?)
				//y de paso, Herbert recuerda que lo tracionaste ;)
				mvprintw(18,110, "New game");
				initscr();
				start_color();
				drawBoard();
			}

			do {
				initscr();
				start_color();
				drawBoard();
				if (ControlTurno % 2 == 0)
				{
					if(Jugador1 -> checkInJail())	//SI EL JUGADOR ESTA EN LA CARCEL
					{	
						mvprintw(15,50, "Player ","You are in jail you must ");
						mvprintw(15,50, "get out to throw the dice again");
						Jugador1 -> setInJail(ifJail());
						if(Jugador1 -> checkInJail()){
							
						}else{
							Jugador1 -> setMoneyOwned(50);
						}
						cleanScreen();
					}else{
						int ControlTurno = 0, dice1 = 0, dice2 = 0;
						char keyPlayer[1];
						if (ControlTurno % 2 == 0)
						{
							mvprintw(4,111, "Player %d",ControlTurno);
							mvprintw(4,111, Jugador1 -> getName().c_str());
							mvprintw(5,111,"Choose your option...");
							mvprintw(6,111,"1. Throwing dice\n");
							mvprintw(7,111,"2. See your properties\n");
							mvprintw(8,111,"3. See your data\n");
							mvprintw(9,111,"4. Sales/Mortgages\n");
							mvprintw(10,111,"5. Build on complete avenues\n");
							//QUE NO HAREMOS PROBABLEMENTE mvprintw(12,80,"6.-Trade\n");
							mvprintw(11,111,"6.-Quit no QUICK \n");
							mvprintw(12,111,"7.-Save Game for later \n");
							mvprintw(13,111,"Your option? -> ");
							getstr(keyPlayer);
							cleanScreen();
							if(keyPlayer[0] == '1'){//TIRAR EL DADO Y VALIDACIONES DE POSICION
								dice1 = (1 + rand() % 6);
								dice2 = (1 + rand() % 6);
								int spaces = dice1 + dice2;
								Jugador1 -> TurnControl(spaces);
								init_pair(2, COLOR_BLACK, COLOR_WHITE);
								attron(COLOR_PAIR(2));
								srand (time(NULL));
								drawDiceOne(dice1);
								drawDiceTwo(dice2);
								attroff(COLOR_PAIR(2));
								getch();
								int Espacio = Jugador1 -> getPosition() - 1;
								cleanScreen();
								Espacio++;
								draw(Espacio);
								if (Espacio == 2 || Espacio == 7 || Espacio == 17 || Espacio==22 || Espacio == 33 || Espacio == 36)
								{	
									int TemporalCarta = 0;
									TemporalCarta = drawCard();
									if(TemporalCarta < 40 && TemporalCarta != 10 && TemporalCarta > -6){
										Jugador1 -> TurnControl(TemporalCarta);	
									} else if(TemporalCarta != 10) {
										Jugador1 -> setMoney_Owned(TemporalCarta);
									} else {
										Jugador1 -> setPosition(10);
										Jugador1 -> setInJail(true);
									}
									//CARTAS DE COMMMUNITY CHEST Y FORTUNE						
								} else if (Espacio == 4 || Espacio == 38) {
									mvprintw(15,50,"Gracias por pagar tus impuestos de 200$!");
									Jugador1 -> setMoneyOwned(200);
									//TAXES
								} else if (Espacio ==30) {
									mvprintw(15,50,"Por ser muy Brayan ve directamente a la carcel!");
									Jugador1 -> TurnControl(-20);
									Jugador1 -> setInJail(true);
									//GO TO JAIL
								} else if (Espacio == 20 || Espacio == 10) {
									mvprintw(15,50,"Esta Casilla no hace absolutamente nada!");
									//VISIT JAIL,FREE SPACE NO HACEN NADA SOLO ES EL DIBUJO
								} else if(Espacio != 2 && Espacio != 7 && Espacio != 17 && Espacio != 22 && Espacio != 33 && Espacio != 36 && Espacio != 10 && Espacio != 38
									&& Espacio != 4 && Espacio != 20 && Espacio!=30){
									Espacio--;
									if (board.at(Espacio) -> getOwned()==false)
									{	
										
										if (Jugador1 -> getMoneyOwned() < board.at(Espacio) -> getPrice())
										{
											mvprintw(15,50,"You do not have the money to buy this property \n");
								  		}else{
											char keyPlayer[1];
											mvprintw(15,50,"1. Buy this Property \n");
											mvprintw(16,50,"2. NO \n");
											getstr(keyPlayer);
											if (keyPlayer[0] == '1')
											{
												cleanScreen();
											mvprintw(15,50,"You have purchased this property!\n");
											Jugador1 -> setMoneyOwned(board.at(Espacio) -> getPrice());
											board.at(Espacio) -> setOwned(true);
											Jugador1 -> setProperties(board.at(Espacio));
											
											}
										}						
									}else {//CUANDO ALGUIEN TIENE LA PROPIEDAD
										if (Jugador1 -> validarProperties(board.at(Espacio) -> getTitle()))
										{	
											mvprintw(15,50,board.at(Espacio)->getTitle().c_str());
											mvprintw(16,50,"Esta Propiedad es tuya");	
										}else{//COBRARLE AL JUGADOR LA RENTA
											if (board.at(Espacio) -> getMortgage() == 0)
											{
												mvprintw(8,80,"Pagas la renta.");
												mvprintw(9,80,board.at(Espacio) -> getTitle().c_str());
												Jugador1 -> setMoneyOwned(board.at(Espacio) -> getRent());
											} else {
												mvprintw(8,80,"Property is mortgaged, no rent is payed!");
											}
										}
									}
								}
								echo();
								getch();
								cleanScreen();
							}else if(keyPlayer[0] == '2'){
								//Observar las propiedades
								mvprintw(16, 110,Jugador1 -> getProperties().c_str());
								cleanScreen();
							}else if(keyPlayer[0] == '3'){
								//Observar la Informacion del jugador
								mvprintw(15, 80, Jugador1 -> toString().c_str());
							}else if(keyPlayer[0] == '4') {//Vender Propiedades
								int Espacio = Jugador1 -> getPosition() - 1;
								if (Jugador1 -> validarProperties(board.at(Espacio) -> getTitle())) {
									Avenue* tryTemp = dynamic_cast<Avenue*>(board.at(Espacio));
									if (tryTemp -> getHouses() == 0)
									{
										char confirm[1];
										mvprintw(15,50,tryTemp -> getTitle().c_str());
										mvprintw(16,50,"Esta seguro de querer vender/hipotecar? [y/n] \n");	
										getstr(confirm);

										if (confirm[0] == 'y' || confirm[0] == 'Y')
										{
										
											char toWhom[1];
											mvprintw(15, 50, "1. Sell Property to Player 2 \n");
											mvprintw(16, 50, "2. Mortgage this property. \n");
											mvprintw(17, 50, "3. Pay back your mortgage.");
											getstr(toWhom);
											if (toWhom[0] == '1')
											{
												Jugador1 = Jugador1 -> removeProperty(Jugador1, board.at(Espacio));								
												Jugador1 -> setMoney_Owned((board.at(Espacio) -> getPrice()));
												Jugador2 -> setMoneyOwned(board.at(Espacio) -> getPrice());
												Jugador2 -> setProperties(board.at(Espacio));
												mvprintw(18, 50, "Your property has been sold! \n");
											} else if (toWhom[0] == '2')
											{
												Properties* lemmeTrySmth = Jugador1 -> mortgageProperty(board.at(Espacio));
												board.erase(board.begin() + Espacio);
												board.insert(board.begin() + Espacio, lemmeTrySmth);
												mvprintw(18, 50, "You have mortgaged your property!\n");
												
											} else if (toWhom[0] == '3') {
												int mortgageTax = (board.at(Espacio) -> getMortgage()) * 0.1;
												int mortgageDue = board.at(Espacio) -> getMortgage() + mortgageTax;
												if (Jugador1 -> getMoneyOwned() >= mortgageDue && board.at(Espacio) -> getMortgage() > 0)
												{
													Jugador1 -> payMortgage(board.at(Espacio), mortgageDue);
													board.at(Espacio) -> setMortgage(0);
													mvprintw(18, 50, "Mortgage has been lifted. \n");
												} else if (board.at(Espacio) -> getMortgage() == 0 && Jugador1 -> getMoneyOwned() >= mortgageDue)
												{
													mvprintw(17, 50, "But this property isn't mortgaged! \n");
												} else {
													mvprintw(17, 50, "You're broke. You cannot lift this mortgage. \n");
												}
											} else {
												mvprintw(18,50,"k bai.");
											}
										}
									} else if (tryTemp -> getHouses() > 0) {
										char confirm[1];
										mvprintw(15,50,board.at(Espacio) -> getTitle().c_str());
										mvprintw(16,50,"This property has been improved.\n");
										mvprintw(17,50,"To sell a hotel, sell 5 houses.\n");
										mvprintw(18,50,"Coninue? [y/n] \n");
										getstr(confirm);
										if (confirm[0] == 'y' || confirm[0] == 'Y')
										{
											char howmuch[1];
											stringstream battery;
											battery << "You can sell: " << tryTemp -> getHouses() << " houses";
											string ugh = battery.str();
											mvprintw(17,50, ugh.c_str());
											mvprintw(18,50,"How many houses will you sell? \n");
											getstr(howmuch);
											if (howmuch[0] == '0')
											{
												mvprintw(18,50,"Coolio, not selling then. \n");
											} else if (howmuch[0] == '1')
											{
												Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice()/2)); //gain half
												tryTemp -> setHouses(tryTemp -> getHouses() - 1);
												mvprintw(18,50,"Sold 1 house. \n");
											} else if (howmuch[0] == '2' && tryTemp -> getHouses() >= 2)
											{
												Jugador1 -> setMoney_Owned(tryTemp -> getHousePrice()); //for two you gain one
												tryTemp -> setHouses(tryTemp -> getHouses() - 2);
												mvprintw(18,50,"Sold 2 houses. \n");
											} else if (howmuch[0] == '3' && tryTemp -> getHouses() >= 3)
											{
												Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice() + tryTemp -> getHousePrice() / 2)); //1 and a half
												tryTemp -> setHouses(tryTemp -> getHouses() - 3);
												mvprintw(18,50,"Sold 3 houses. \n");
											} else if (howmuch[0] == '4' && tryTemp -> getHouses() >= 4 && tryTemp-> getHouses() < 5)
											{
												Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice() * 2)); //2
												tryTemp -> setHouses(tryTemp -> getHouses() - 4);
												mvprintw(18,50,"Sold 4 houses. \n");
											} else if (howmuch[0] == '5' && tryTemp -> getHouses() == 5)
											{
												Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice() * 2 + tryTemp -> getHousePrice() / 2)); //2 and a half
												tryTemp -> setHouses(tryTemp -> getHouses() - 5);
												tryTemp -> setHotels(0);
												mvprintw(12, 80,"Sold everything. \n");
											} else {
												mvprintw(18,50,"Can't sell what you ain't got. \n");
											}
											board.erase(board.begin() + Espacio);
											board.insert(board.begin() + Espacio, tryTemp);
										}
									}
								} else { //NOTHING
									mvprintw(5,50,"This doesn't belong to you.");
								}

								echo();
								getch();
								cleanScreen();
							}else if (keyPlayer[0] == '5')//Construir Casas
							{
								int Espacio = Jugador1 -> getPosition() - 1;				
								if (Jugador1 -> validarProperties(board.at(Espacio) -> getTitle()))
								{	
									mvprintw(9, 80, board.at(Espacio) -> getTitle().c_str());
									Avenue* tryTemp = dynamic_cast<Avenue*>(board.at(Espacio));
									//hmmmm hello there, me distraigo rapido, entonces dejo comentado aqui pa saber que tengo que hacer esto bai <3
									if (Jugador1 -> canBuildOnLot(tryTemp) && Jugador1 -> getMoneyOwned() >= tryTemp -> getHousePrice())
									{
										board.erase(board.begin() + Espacio);
										board.insert(board.begin() + Espacio, Jugador1 -> buildOnLot(tryTemp));
										Avenue* secondaryTemp = dynamic_cast<Avenue*>(board.at(Espacio));
										secondaryTemp -> setRent(secondaryTemp -> getRent());
										board.erase(board.begin() + Espacio);
										board.insert(board.begin() + Espacio, secondaryTemp);
										mvprintw(9,80,"A house has been built.\n");
									} else { //hello, if you are here, it's because the lot is not an avenue that can be built OR because you ain't got the $$$
										mvprintw(9,80,"Lot/Player does not meet prerequisites.\n");
									}
								} else { //soz, it just doesn't.
									mvprintw(8,80,"This doesn't belong to you.");
								}
								echo();
								getch();
								cleanScreen();
							}else if(keyPlayer[0] == '6'){//Abandonar el juego
								endwin();
								exit(0);
							}else if(keyPlayer[0] == '7'){//Salvar el juego
								ofstream ficheroSalida;
								ficheroSalida.open ("./Tablero.txt");
								for (int i = 0; i < board.size(); ++i)
								{
								ficheroSalida << board.at(i) -> toString(1)<<endl;
								}
								ficheroSalida << "Exit";
								ficheroSalida.close();
								//FIN GUARDADO DEL TABLERO
								ofstream ficheroSalida1;
								ficheroSalida1.open ("./Jugador1.txt");
								ficheroSalida1 << Jugador1 -> toString(1) << endl;
								ficheroSalida1<< Jugador1 -> getProperties(1) << endl;
								ficheroSalida1 << "Exit";
								ficheroSalida1.close();
								//FIN GUARDADO JUGADOR 1
								/*ofstream ficheroSalida2;
								ficheroSalida2.open ("./Jugador2.txt");
								ficheroSalida2 <<Jugador2->toString(1)<<endl;
								ficheroSalida2<< Jugador2->getProperties(1)<<endl;
								ficheroSalida2 << "Exit";
								ficheroSalida2.close();*FIN GUARDADO JUGADOR 2/*/
							}
						}
					}
				} else { //AQUI LO DE PLAYER2 JUE PUCHA X_X
						if(Jugador2 -> checkInJail())	//SI EL JUGADOR ESTA EN LA CARCEL
					{	
						mvprintw(4, 110, "Player ","You are in jail you must ");
						mvprintw(5, 110, "get out to throw the dice again");
						Jugador2 -> setInJail(ifJail());
						if(Jugador2 -> checkInJail()){
							
						}else{
							Jugador2 -> setMoneyOwned(50);
						}
						cleanScreen();
					} else {
						int dice1 = 0, dice2 = 0;
						char keyPlayer[1];
						mvprintw(4,110, "Player 1: ");
						mvprintw(4,110, Jugador2 -> getName().c_str());
						mvprintw(5,110,"Choose your option...");
						mvprintw(6,110,"1. Throwing dice\n");
						mvprintw(7,110,"2. See your properties\n");
						mvprintw(8,110,"3. See your data\n");
						mvprintw(9,110,"4. Sales/Mortgages\n");
						mvprintw(10,110,"5. Build on complete avenues\n");
						//QUE NO HAREMOS PROBABLEMENTE mvprintw(12,80,"6.-Trade\n");
						mvprintw(11,110,"6.-Quit no QUICK \n");
						mvprintw(12,110,"7.-Save Game for later \n");
						mvprintw(13,110,"Your option? -> ");
						getstr(keyPlayer);
						cleanScreen();
						if(keyPlayer[0] == '1'){//TIRAR EL DADO Y VALIDACIONES DE POSICION
							dice1 = (1 + rand() % 6);
							dice2 = (1 + rand() % 6);
							int spaces = dice1 + dice2;
							Jugador2 -> TurnControl(spaces);
							init_pair(1, COLOR_BLACK, COLOR_WHITE);
							attron(COLOR_PAIR(1));
							srand (time(NULL));
							drawDiceOne(dice1);
							drawDiceTwo(dice2);
							attroff(COLOR_PAIR(1));
							getch();
							int Espacio = Jugador2 -> getPosition() - 1;
							cleanScreen();
							Espacio++;
							draw(Espacio);
							if (Espacio == 2 || Espacio == 7 || Espacio == 17 || Espacio==22 || Espacio == 33 || Espacio == 36)
							{	
								int TemporalCarta = 0;
								TemporalCarta = drawCard();
								if(TemporalCarta < 40 && TemporalCarta != 10 && TemporalCarta > -6){
									Jugador2 -> TurnControl(TemporalCarta);	
								} else if(TemporalCarta != 10) {
									Jugador2 -> setMoney_Owned(TemporalCarta);
								} else {
									Jugador2 -> setPosition(10);
									Jugador2 -> setInJail(true);
								}
								//CARTAS DE COMMMUNITY CHEST Y FORTUNE						
							} else if (Espacio == 4 || Espacio == 38) {
								mvprintw(6,80,"Gracias por pagar tus impuestos de 200$!");
								Jugador2 -> setMoneyOwned(200);
								//TAXES
							} else if (Espacio ==30) {
								mvprintw(6,80,"Por ser muy Brayan ve directamente a la carcel!");
								Jugador2 -> TurnControl(-20);
								Jugador2 -> setInJail(true);
								//GO TO JAIL
							} else if (Espacio == 20 || Espacio == 10) {
								mvprintw(6,80,"Esta Casilla no hace absolutamente nada!");
								//VISIT JAIL,FREE SPACE NO HACEN NADA SOLO ES EL DIBUJO
							} else if(Espacio != 2 && Espacio != 7 && Espacio != 17 && Espacio != 22 && Espacio != 33 && Espacio != 36 && Espacio != 10 && Espacio != 38
								&& Espacio != 4 && Espacio != 20 && Espacio!=30){
								Espacio--;
								if (board.at(Espacio) -> getOwned()==false)
								{	
									
									if (Jugador2 -> getMoneyOwned() < board.at(Espacio) -> getPrice())
									{
										mvprintw(6,60,"You do not have the money to buy this property \n");
							  		}else{
										char keyPlayer[1];
										mvprintw(6,80,"1. Buy this Property \n");
										mvprintw(7,80,"2. NO \n");
										getstr(keyPlayer);
										if (keyPlayer[0] == '1')
										{
										mvprintw(8,80,"You have purchased this property!\n");
										Jugador2 -> setMoneyOwned(board.at(Espacio) -> getPrice());
										board.at(Espacio) -> setOwned(true);
										Jugador2 -> setProperties(board.at(Espacio));
										}
									}						
								}else {//CUANDO ALGUIEN TIENE LA PROPIEDAD
									if (Jugador2 -> validarProperties(board.at(Espacio) -> getTitle()))
									{	
										mvprintw(9,80,board.at(Espacio)->getTitle().c_str());
										mvprintw(8,80,"Esta Propiedad es tuya");	
									}else{//COBRARLE AL JUGADOR LA RENTA
										if (board.at(Espacio) -> getMortgage() == 0)
										{
											mvprintw(8,80,"Pagas la renta.");
											mvprintw(9,80,board.at(Espacio) -> getTitle().c_str());
											Jugador2 -> setMoneyOwned(board.at(Espacio) -> getRent());
										} else {
											mvprintw(8,80,"Property is mortgaged, no rent is payed!");
										}
									}
								}
							}
							echo();
							getch();
							cleanScreen();
						}else if(keyPlayer[0] == '2'){
							//Observar las propiedades
							mvprintw(16, 110,Jugador2 -> getProperties().c_str());
							//cleanScreen();
						}else if(keyPlayer[0] == '3'){
							//Observar la Informacion del jugador
							mvprintw(15, 80, Jugador2 -> toString().c_str());
						}else if(keyPlayer[0] == '4') {//Vender Propiedades
							int Espacio = Jugador2 -> getPosition() - 1;
							if (Jugador2 -> validarProperties(board.at(Espacio) -> getTitle())) {
								Avenue* tryTemp = dynamic_cast<Avenue*>(board.at(Espacio));
								if (tryTemp -> getHouses() == 0)
								{
									char confirm[1];
									mvprintw(8,80,tryTemp -> getTitle().c_str());
									mvprintw(9,80,"Esta seguro de querer vender/hipotecar? [y/n] \n");	
									getstr(confirm);

									if (confirm[0] == 'y' || confirm[0] == 'Y')
									{
									
										char toWhom[1];
										mvprintw(11, 80, "1. Sell Property to Player 2 \n");
										mvprintw(12, 80, "2. Mortgage this property. \n");
										mvprintw(13, 80, "3. Pay back your mortgage.");
										getstr(toWhom);
										if (toWhom[0] == '1')
										{
											Jugador2 = Jugador2 -> removeProperty(Jugador2, board.at(Espacio));								
											Jugador2 -> setMoney_Owned((board.at(Espacio) -> getPrice()));
											Jugador1 -> setMoneyOwned(board.at(Espacio) -> getPrice());
											Jugador1 -> setProperties(board.at(Espacio));
											mvprintw(14, 80, "Your property has been sold! \n");
										} else if (toWhom[0] == '2')
										{
											Properties* lemmeTrySmth = Jugador2 -> mortgageProperty(board.at(Espacio));
											board.erase(board.begin() + Espacio);
											board.insert(board.begin() + Espacio, lemmeTrySmth);
											mvprintw(14, 80, "You have mortgaged your property!\n");
											
										} else if (toWhom[0] == '3') {
											int mortgageTax = (board.at(Espacio) -> getMortgage()) * 0.1;
											int mortgageDue = board.at(Espacio) -> getMortgage() + mortgageTax;
											if (Jugador2 -> getMoneyOwned() >= mortgageDue && board.at(Espacio) -> getMortgage() > 0)
											{
												Jugador2 -> payMortgage(board.at(Espacio), mortgageDue);
												board.at(Espacio) -> setMortgage(0);
												mvprintw(15, 80, "Mortgage has been lifted. \n");
											} else if (board.at(Espacio) -> getMortgage() == 0 && Jugador2 -> getMoneyOwned() >= mortgageDue)
											{
												mvprintw(14, 80, "But this property isn't mortgaged! \n");
											} else {
												mvprintw(14, 80, "You're broke. You cannot lift this mortgage. \n");
											}
										} else {
											mvprintw(15,80,"k bai.");
										}
									}
								} else if (tryTemp -> getHouses() > 0) {
									char confirm[1];
									mvprintw(8,80,board.at(Espacio) -> getTitle().c_str());
									mvprintw(9,80,"This property has been improved.\n");
									mvprintw(10,80,"To sell a hotel, sell 5 houses.\n");
									mvprintw(11,80,"Coninue? [y/n] \n");
									getstr(confirm);
									if (confirm[0] == 'y' || confirm[0] == 'Y')
									{
										char howmuch[1];
										stringstream battery;
										battery << "You can sell: " << tryTemp -> getHouses() << " houses";
										string ugh = battery.str();
										mvprintw(11,80, ugh.c_str());
										mvprintw(12,80,"How many houses will you sell? \n");
										getstr(howmuch);
										if (howmuch[0] == '0')
										{
											mvprintw(12,80,"Coolio, not selling then. \n");
										} else if (howmuch[0] == '1')
										{
											Jugador2 -> setMoney_Owned((tryTemp -> getHousePrice()/2)); //gain half
											tryTemp -> setHouses(tryTemp -> getHouses() - 1);
											mvprintw(12,80,"Sold 1 house. \n");
										} else if (howmuch[0] == '2' && tryTemp -> getHouses() >= 2)
										{
											Jugador2 -> setMoney_Owned(tryTemp -> getHousePrice()); //for two you gain one
											tryTemp -> setHouses(tryTemp -> getHouses() - 2);
											mvprintw(12,80,"Sold 2 houses. \n");
										} else if (howmuch[0] == '3' && tryTemp -> getHouses() >= 3)
										{
											Jugador2 -> setMoney_Owned((tryTemp -> getHousePrice() + tryTemp -> getHousePrice() / 2)); //1 and a half
											tryTemp -> setHouses(tryTemp -> getHouses() - 3);
											mvprintw(12,80,"Sold 3 houses. \n");
										} else if (howmuch[0] == '4' && tryTemp -> getHouses() >= 4 && tryTemp-> getHouses() < 5)
										{
											Jugador2 -> setMoney_Owned((tryTemp -> getHousePrice() * 2)); //2
											tryTemp -> setHouses(tryTemp -> getHouses() - 4);
											mvprintw(12,80,"Sold 4 houses. \n");
										} else if (howmuch[0] == '5' && tryTemp -> getHouses() == 5)
										{
											Jugador2 -> setMoney_Owned((tryTemp -> getHousePrice() * 2 + tryTemp -> getHousePrice() / 2)); //2 and a half
											tryTemp -> setHouses(tryTemp -> getHouses() - 5);
											tryTemp -> setHotels(0);
											mvprintw(12, 80,"Sold everything. \n");
										} else
										{
											mvprintw(12, 80, "Can't sell what you ain't got. \n");
										}
										board.erase(board.begin() + Espacio);
										board.insert(board.begin() + Espacio, tryTemp);
									}
								}
							} else { //NOTHING
								mvprintw(8,80,"This doesn't belong to you.");
							}

							echo();
							getch();
							cleanScreen();
						}else if (keyPlayer[0] == '5')//Construir Casas
						{
							int Espacio = Jugador2 -> getPosition() - 1;				
							if (Jugador2 -> validarProperties(board.at(Espacio) -> getTitle()))
							{	
								mvprintw(9, 80, board.at(Espacio) -> getTitle().c_str());
								Avenue* tryTemp = dynamic_cast<Avenue*>(board.at(Espacio));
								//hmmmm hello there, me distraigo rapido, entonces dejo comentado aqui pa saber que tengo que hacer esto bai <3
								if (Jugador2 -> canBuildOnLot(tryTemp) && Jugador2 -> getMoneyOwned() >= tryTemp -> getHousePrice())
								{
									board.erase(board.begin() + Espacio);
									board.insert(board.begin() + Espacio, Jugador2 -> buildOnLot(tryTemp));
									Avenue* secondaryTemp = dynamic_cast<Avenue*>(board.at(Espacio));
									secondaryTemp -> setRent(secondaryTemp -> getRent());
									board.erase(board.begin() + Espacio);
									board.insert(board.begin() + Espacio, secondaryTemp);
									mvprintw(9,80,"A house has been built.\n");
								} else { //hello, if you are here, it's because the lot is not an avenue that can be built OR because you ain't got the $$$
									mvprintw(9,80,"Lot/Player does not meet prerequisites.\n");
								}
							} else { //soz, it just doesn't.
								mvprintw(8,80,"This doesn't belong to you.");
							}
							echo();
							getch();
							cleanScreen();
						}else if(keyPlayer[0] == '6'){//Abandonar el juego
							endwin();
							exit(0);
						}else if(keyPlayer[0] == '7'){//Salvar el juego
							ofstream ficheroSalida;
							ficheroSalida.open ("./Tablero.txt");
							for (int i = 0; i < board.size(); ++i)
							{
							ficheroSalida << board.at(i) -> toString(1)<<endl;
							}
							ficheroSalida << "Exit";
							ficheroSalida.close();
							//FIN GUARDADO DEL TABLERO
							ofstream ficheroSalida1;
							ficheroSalida1.open ("./Jugador2.txt");
							ficheroSalida1 << Jugador2 -> toString(1) << endl;
							ficheroSalida1<< Jugador2 -> getProperties(1) << endl;
							ficheroSalida1 << "Exit";
							ficheroSalida1.close();
							//FIN GUARDADO JUGADOR 1
							/*ofstream ficheroSalida2;
							ficheroSalida2.open ("./Jugador2.txt");
							ficheroSalida2 <<Jugador2->toString(1)<<endl;
							ficheroSalida2<< Jugador2->getProperties(1)<<endl;
							ficheroSalida2 << "Exit";
							ficheroSalida2.close();*FIN GUARDADO JUGADOR 2/*/
						}
					}
				}
				ControlTurno++;
			} while (true);
			
			} else if(key[0] == 'l' || key[0] == 'L') {
				Load=false;
				ifstream myfile (argv[1]);
				myfile.open("./Tablero.txt");
				int Renta,Compra,Hipoteca,Venta,Estado,Dinero,Posicion;
				string Nombre,Temporal;
				//char str[30];
				char const*J;
				while(Temporal!="Exit"){
					myfile>>Temporal;
					J=Temporal.c_str();
					Renta=atoi(J);
					myfile>>Temporal;
					J=Temporal.c_str();
					Compra=atoi(J);
					myfile>>Temporal;
					J=Temporal.c_str();
					Hipoteca=atoi(J);
					myfile>>Temporal;
					J=Temporal.c_str();
					Venta=atoi(J);
					myfile>>Nombre;
					myfile>>Temporal;
					J=Temporal.c_str();
					Estado=atoi(J);
					board.push_back(new Avenue(Renta,Compra,Hipoteca,Venta,Nombre,Estado));
				}//FIN CARGA DEL TABLERO

				myfile.close();

				myfile.open("./Jugador1.txt");
				myfile >> Nombre;
				myfile >> Temporal;
				J=Temporal.c_str();
				Dinero=atoi(J);
				myfile>>Temporal;
				J=Temporal.c_str();
				Posicion=atoi(J);
				Jugador1=new Player(Nombre,Dinero);
				Jugador1->setPosition(Posicion);
				//FIN INICIALIZAR EL JUGADOR
				while(Temporal!="Exit"){
					myfile>>Temporal;
					for (int i = 0; i < board.size(); ++i)
					{
						if (Temporal==board.at(i)->getTitle())
						{
							Jugador1->setProperties(board.at(i));
						}
					}
					
				}
				myfile.close();
				//FIN JUGADOR 1

				myfile.open("./Jugador2.txt");
				myfile>>Nombre;
				myfile>>Temporal;
				J=Temporal.c_str();
				Dinero=atoi(J);
				myfile>>Temporal;
				J=Temporal.c_str();
				Posicion=atoi(J);
				Jugador2 = new Player(Nombre,Dinero);
				Jugador2->setPosition(Posicion);
				//FIN INICIALIZAR EL JUGADOR
				while(Temporal!="Exit"){
					myfile>>Temporal;
					for (int i = 0; i < board.size(); ++i)
					{
						if (Temporal==board.at(i)->getTitle())
						{
							Jugador2->setProperties(board.at(i));
						}
					}
					
				}
			myfile.close();
			mvprintw(16,80, "Load Game Succesful now get a new game to load your last game! ");	
		}
	} while(key[0] != 'e' || key[0] == 'E');	
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
		mvprintw(15,20,"*********\n");
		mvprintw(16,20,"*       *\n");
		mvprintw(17,20,"*   *   *\n");
		mvprintw(18,20,"*       *\n");
		mvprintw(19,20,"*********\n");
	} else if (dice1 == 2){
		mvprintw(15,20,"*********\n");
		mvprintw(16,20,"*       *\n");
		mvprintw(17,20,"*  * *  *\n");
		mvprintw(18,20,"*       *\n");
		mvprintw(19,20,"*********\n");
	} else if (dice1 == 3) {
		mvprintw(15,20,"*********\n");
		mvprintw(16,20,"* *     *\n");
		mvprintw(17,20,"*   *   *\n");
		mvprintw(18,20,"*     * *\n");
		mvprintw(19,20,"*********\n");
	} else if (dice1 == 4) {
		mvprintw(15,20,"*********\n");
		mvprintw(16,20,"* *   * *\n");
		mvprintw(17,20,"*       *\n");
		mvprintw(18,20,"* *   * *\n");
		mvprintw(19,20,"*********\n");
	} else if (dice1 == 5) {
		mvprintw(15,20,"*********\n");
		mvprintw(16,20,"* *   * *\n");
		mvprintw(17,20,"*   *   *\n");
		mvprintw(18,20,"* *   * *\n");
		mvprintw(19,20,"*********\n");
	} else if (dice1 == 6) {
		mvprintw(15,20,"*********\n");
		mvprintw(16,20,"*  * *  *\n");
		mvprintw(17,20,"*  * *  *\n");
		mvprintw(18,20,"*  * *  *\n");
		mvprintw(19,20,"*********\n");
	}
}

void drawDiceTwo(int dice2){
	if (dice2 == 1){
		mvprintw(15,30,"*********\n");
		mvprintw(16,30,"*       *\n");
		mvprintw(17,30,"*   *   *\n");
		mvprintw(18,30,"*       *\n");
		mvprintw(19,30,"*********\n");
	} else if (dice2 == 2){
		mvprintw(15,30,"*********\n");
		mvprintw(16,30,"*       *\n");
		mvprintw(17,30,"*  * *  *\n");
		mvprintw(18,30,"*       *\n");
		mvprintw(19,30,"*********\n");
	} else if (dice2 == 3) {
		mvprintw(15,30,"*********\n");
		mvprintw(16,30,"* *     *\n");
		mvprintw(17,30,"*   *   *\n");
		mvprintw(18,30,"*     * *\n");
		mvprintw(19,30,"*********\n");
	} else if (dice2 == 4) {
		mvprintw(15,30,"*********\n");
		mvprintw(16,30,"* *   * *\n");
		mvprintw(17,30,"*       *\n");
		mvprintw(18,30,"* *   * *\n");
		mvprintw(19,30,"*********\n");
	} else if (dice2 == 5) {
		mvprintw(15,30,"*********\n");
		mvprintw(16,30,"* *   * *\n");
		mvprintw(17,30,"*   *   *\n");
		mvprintw(18,30,"* *   * *\n");
		mvprintw(19,30,"*********\n");
	} else if (dice2 == 6) {
		mvprintw(15,30,"*********\n");
		mvprintw(16,30,"*  * *  *\n");
		mvprintw(17,30,"*  * *  *\n");
		mvprintw(18,30,"*  * *  *\n");
		mvprintw(19,30,"*********\n");
	}
}
void draw(int space){
	int controlador = 0;
	string linea[15];
	if (space != 2 && space != 7 && space != 17 && space!=22 && space != 33 && space != 36){
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
	    	linea[6] = "*  1 house ---> $1000 *\n";
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
	    	linea[1] = "* Pennsylvania Avenue *\n";
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
		}else if (space == 1 || space == 40){
	    	controlador = 1;
			init_pair(1,COLOR_BLUE,COLOR_WHITE);
			attron(COLOR_PAIR(1));
			mvprintw(10,20,"****************************\n");
			mvprintw(11,20,"*                          *\n");
			mvprintw(12,20,"*     ******     ****      *\n");
			mvprintw(13,20,"*     *         *    *     *\n");
			mvprintw(14,20,"*     *  ***    *    *     *\n");
			mvprintw(15,20,"*     *    *    *    *     *\n");
			mvprintw(16,20,"*     ******     ****      *\n");
			mvprintw(17,20,"*                          *\n");
			mvprintw(18,20,"*                          *\n");
			mvprintw(19,20,"*                          *\n");
			mvprintw(20,20,"*          COLLECT         *\n");
			mvprintw(21,20,"*           $200           *\n");
			mvprintw(22,20,"*                          *\n");
			mvprintw(23,20,"****************************\n");
			attroff(COLOR_PAIR(1));
		}else if (space == 4){
			controlador = 1;
			init_pair(2,COLOR_BLACK,COLOR_WHITE);
			attron(COLOR_PAIR(2));
			mvprintw(10,20,"****************************\n");
			mvprintw(11,20,"*                          *\n");
			mvprintw(12,20,"*                          *\n");
			mvprintw(13,20,"*                          *\n");
			mvprintw(14,20,"*                          *\n");
			mvprintw(15,20,"*          INCOME          *\n");
			mvprintw(16,20,"*                          *\n");
			mvprintw(17,20,"*           TAX            *\n");
			mvprintw(18,20,"*                          *\n");
			mvprintw(19,20,"*                          *\n");
			mvprintw(20,20,"*                          *\n");
			mvprintw(21,20,"*                          *\n");
			mvprintw(22,20,"*                          *\n");
			mvprintw(23,20,"****************************\n");
			attroff(COLOR_PAIR(2));
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
			mvprintw(18,20,"*      Electric Company    *\n");
			mvprintw(19,20,"*  1 Service->rent 4 times *\n");
			mvprintw(20,20,"*  amount shown on dice.   *\n");
			mvprintw(21,20,"*2 Services->rent 10 times *\n");
			mvprintw(22,20,"*   amount shown on dice.  *\n");
			mvprintw(23,20,"*   Mortgage Value  $75    *\n");
			mvprintw(24,20,"****************************\n");
			attroff(COLOR_PAIR(1));
		}
		else if (space == 10){
			controlador = 1;
			init_pair(1,COLOR_BLUE,COLOR_WHITE);
			attron(COLOR_PAIR(1));
			mvprintw(10,20,"*****************************\n");
			mvprintw(11,20,"* *     *     *     *     * *\n");
			mvprintw(12,20,"* ************************* *\n");
			mvprintw(13,20,"* *     *     *     *     * *\n");
			mvprintw(14,20,"* *     *     *     *     * *\n");
			mvprintw(15,20,"* ************************* *\n");
			mvprintw(16,20,"*                           *\n");
			mvprintw(17,20,"*  *****    *     *  *      *\n");
			mvprintw(18,20,"*    *     * *    *  *      *\n");
			mvprintw(19,20,"*    *    * * *   *  *      *\n");
			mvprintw(20,20,"*  ***   *     *  *  *****  *\n");
			mvprintw(21,20,"* ************************* *\n");
			mvprintw(22,20,"* *     *     *     *     * *\n");
			mvprintw(23,20,"*****************************\n");
			attroff(COLOR_PAIR(1));
		}else if (space == 20)
		{
			controlador = 1;
			init_pair(2,COLOR_BLACK,COLOR_WHITE);
			attron(COLOR_PAIR(2));
			mvprintw(10,20,"****************************\n");
			mvprintw(11,20,"*                          *\n");
			mvprintw(12,20,"*          ******          *\n");
			mvprintw(13,20,"*        ***    ***        *\n");
			mvprintw(14,20,"*       ************       *\n");
			mvprintw(15,20,"*        **********        *\n");
			mvprintw(16,20,"*         **    **         *\n");
			mvprintw(17,20,"*                          *\n");
			mvprintw(18,20,"*                          *\n");
			mvprintw(19,20,"*                          *\n");
			mvprintw(20,20,"*           FREE           *\n");
			mvprintw(21,20,"*         PARKING          *\n");
			mvprintw(22,20,"*                          *\n");
			mvprintw(23,20,"*                          *\n");
			mvprintw(24,20,"****************************\n");		
			attroff(COLOR_PAIR(2));
		}
		else if (space == 30){
			controlador = 1;
			init_pair(1,COLOR_BLUE,COLOR_WHITE);
			attron(COLOR_PAIR(1));
			mvprintw(10,20,"****************************\n");
			mvprintw(11,20,"*                          *\n");
			mvprintw(12,20,"* *****  ***   *****  ***  *\n");
			mvprintw(13,20,"* *     *   *    *   *   * *\n");
			mvprintw(14,20,"* *  ** *   *    *   *   * *\n");
			mvprintw(15,20,"* *****  ***     *    ***  *\n");
			mvprintw(16,20,"*                          *\n");
			mvprintw(17,20,"* *****    *     *  *      *\n");
			mvprintw(18,20,"*   *     * *    *  *      *\n");
			mvprintw(19,20,"*   *    * * *   *  *      *\n");
			mvprintw(20,20,"*  **   *     *  *  *****  *\n");
			mvprintw(21,20,"*                          *\n");
			mvprintw(22,20,"*                          *\n");
			mvprintw(23,20,"****************************\n");
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
    
}

int drawCard(){ //Recibe la posicion en el vector, si valor<40 el valor retornado será la nueva posicion,
						 //Si valor es mayor a 50 se trata de dinero sumado o restado
	int randCard = rand() % 15;
	int valor = 0;
    init_pair(4,COLOR_BLACK,COLOR_YELLOW);
    attron(COLOR_PAIR(4));

    if (randCard == 1 || randCard == 0){
    	mvprintw(15,20,"*                        *\n");
    	mvprintw(16,20,"*    You Inherit $100    *\n");
	   	mvprintw(17,20,"*                        *\n");
    	valor = 100;
    }else if (randCard == 2){
    	mvprintw(15,20,"*  You have won second   *\n");
    	mvprintw(16,20,"*   price in a beauty    *\n");
    	mvprintw(17,20,"*   contest collet $50   *\n");
    	valor = 50;
    }else if (randCard == 3){
    	mvprintw(15,20,"*      Bank error        *\n");
    	mvprintw(16,20,"*     in your favor      *\n");
    	mvprintw(17,20,"*     collect $200       *\n");
    	valor = 200;
    } else if (randCard == 4){
    	mvprintw(15,20,"*        Receive         *\n");
    	mvprintw(16,20,"*     for services       *\n");
    	mvprintw(17,20,"*          $45           *\n");
    	valor = 45;
    }else if (randCard == 5){
    	mvprintw(15,20,"*         Life           *\n");
    	mvprintw(16,20,"*    insurance mature    *\n");
    	mvprintw(17,20,"*      collect $100      *\n");
    	valor = 100;
    }else if (randCard == 6){
    	mvprintw(15,20,"*     Bank pays you      *\n");
    	mvprintw(16,20,"*      dividends of      *\n");
    	mvprintw(17,20,"*          $50           *\n");
    	valor = 50;
    }else if (randCard == 7){
    	mvprintw(15,20,"*           Pay          *\n");
    	mvprintw(16,20,"*        poor tax        *\n");
    	mvprintw(17,20,"*         of $50         *\n");
    	valor = -50;
    }else if (randCard == 8){
    	mvprintw(15,20,"*           Pay          *\n");
    	mvprintw(16,20,"*         Hospital       *\n");
    	mvprintw(17,20,"*           $100         *\n");
    	valor = -100;
    }else if (randCard == 9){
    	mvprintw(15,20,"*           Pay          *\n");
    	mvprintw(16,20,"*      for services      *\n");
    	mvprintw(17,20,"*           $50          *\n");
    	valor = -50;
    }else if (randCard == 10){
    	mvprintw(15,20,"*        GO TO JAIL      *\n");
    	mvprintw(16,20,"*    do not pass GO      *\n");
    	mvprintw(17,20,"*  do not collect $200   *\n");
    	valor = 10;
    }else if (randCard == 11){
    	mvprintw(15,20,"*           GO           *\n");
    	mvprintw(16,20,"*          BACK          *\n");
    	mvprintw(17,20,"*        3 spaces        *\n");
    	valor = -3;
    }else if (randCard == 12){
    	mvprintw(15,20,"*       Pay 150 for      *\n");
    	mvprintw(16,20,"*          for bad       *\n");
    	mvprintw(17,20,"*         president      *\n");
    	valor = -150;
    }else if (randCard == 13){
    	mvprintw(15,20,"*           GO           *\n");
    	mvprintw(16,20,"*          BACK          *\n");
    	mvprintw(17,20,"*        5 spaces        *\n");
    	valor = -5;
    }
    else if (randCard == 14){
    	mvprintw(15,20,"*       Advance to       *\n");
    	mvprintw(16,20,"*        Illinois        *\n");
    	mvprintw(17,20,"*         Avenue         *\n");
    	valor = 24;
    }else if (randCard == 15){
    	mvprintw(15,20,"*        Go take        *\n");
    	mvprintw(16,20,"*       a walk advance  *\n");
    	mvprintw(17,20,"*       3 spaces        *\n");
    	valor = 3;
    }
   	attroff(COLOR_PAIR(4));
   	return valor;
}

bool ifJail(){

	int D1 = rand() % 6;
	int D2 = rand() % 6;
	D1++;
	D2++;
	srand (time(NULL));
	echo();
	char keyPlayer[1];
	mvprintw(15,50, "1- Pay 50$ to get out");
	//mvprintw(7,80, "2- Try to get pairs on the dice to get free");
	mvprintw(18,50, "2- Try to get pairs on the dice to get free");
	mvprintw(19,50, "-->");
	getstr(keyPlayer);
	//getch();
	do{
		if(keyPlayer[0] =='1'){
			mvprintw(21,50, "You pay 50$");
			return false;			
		}else if(keyPlayer[0] =='2'){
			drawDiceOne(D1);
			drawDiceTwo(D2);
			getch();
			mvprintw(21,50, "Dices");
			if(D1==D2){
				mvprintw(21,50, "The dices favour you!");				
				return false;
			}else{
				mvprintw(21,50, "The dices don't favour you, stay in jail.");
				return true;
			}
		}
	}while(keyPlayer[0]!=1&&keyPlayer[0]!=2);
		
}

void init_curses()
{
    initscr();
    start_color();
    init_color(COLOR_RED, 700,0,0);
    init_pair(0,COLOR_WHITE,COLOR_BLACK);
    init_pair(1,COLOR_WHITE,COLOR_RED);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    init_pair(3,COLOR_WHITE,COLOR_CYAN);
    init_pair(4,COLOR_WHITE,COLOR_YELLOW);
    init_pair(5,COLOR_WHITE,COLOR_MAGENTA);
    init_pair(6,COLOR_WHITE,COLOR_GREEN);
    init_pair(7,COLOR_WHITE,COLOR_BLUE);
}

void drawSpace3(WINDOW *menubar, int pair)
{
    wattron(menubar,COLOR_PAIR(pair));
    waddstr(menubar,"|         ");
    waddstr(menubar,"|_________");
    wattroff(menubar,COLOR_PAIR(pair));
}
void drawSpace4(WINDOW *menubar, int pair, string linea)
{
    wattron(menubar,COLOR_PAIR(pair));
    waddstr(menubar,linea.c_str());
    wattroff(menubar,COLOR_PAIR(pair));
}
void drawBoard(){
	init_curses();
	WINDOW *space;
	space=subwin(stdscr,4,10,0,0);drawSpace4(space, 2, "| GO -->  ");space=subwin(stdscr,4,10,1,0);drawSpace3(space, 2); //GO
    space=subwin(stdscr,4,10,0,10);drawSpace4(space, 0, "| Baltic  ");space=subwin(stdscr,4,10,1,10);drawSpace3(space, 2);//Baltic
    space=subwin(stdscr,4,10,0,20);drawSpace4(space, 2, "|Community");space=subwin(stdscr,4,10,1,20);drawSpace3(space, 2);//Chest
    space=subwin(stdscr,4,10,0,30);drawSpace4(space, 0, "|Medi. Av.");space=subwin(stdscr,4,10,1,30);drawSpace3(space, 2);//Mediterranean
    space=subwin(stdscr,4,10,0,40);drawSpace4(space, 2, "|  Tax    ");space=subwin(stdscr,4,10,1,40);drawSpace3(space, 2);//Tax
    space=subwin(stdscr,4,10,0,50);drawSpace4(space, 2, "| Reading ");space=subwin(stdscr,4,10,1,50);drawSpace3(space, 2);//reading railroad
    space=subwin(stdscr,4,10,0,60);drawSpace4(space, 3, "|Oriental ");space=subwin(stdscr,4,10,1,60);drawSpace3(space, 2);//Oriental
    space=subwin(stdscr,4,10,0,70);drawSpace4(space, 2, "| Chance  ");space=subwin(stdscr,4,10,1,70);drawSpace3(space, 2);//chance
    space=subwin(stdscr,4,10,0,80);drawSpace4(space, 3, "|Vermont  ");space=subwin(stdscr,4,10,1,80);drawSpace3(space, 2);//Vermont
    space=subwin(stdscr,4,10,0,90);drawSpace4(space, 3, "|Conn. Av.");space=subwin(stdscr,4,10,1,90);drawSpace3(space, 2);//Connecticut
    space=subwin(stdscr,4,10,0,100);drawSpace4(space, 2, "|  JAIL   ");space=subwin(stdscr,4,10,1,100);drawSpace3(space, 2);//Jail
    space=subwin(stdscr,4,10,3,100);drawSpace4(space, 5, "|ST Charle");space=subwin(stdscr,4,10,4,100);drawSpace3(space, 2);//ST. Charles
    space=subwin(stdscr,4,10,6,100);drawSpace4(space, 2, "| Electric");space=subwin(stdscr,4,10,7,100);drawSpace3(space, 2);//Electric
    space=subwin(stdscr,4,10,9,100);drawSpace4(space, 5, "|  States ");space=subwin(stdscr,4,10,10,100);drawSpace3(space, 2);//States
    space=subwin(stdscr,4,10,12,100);drawSpace4(space, 5, "|Virginia ");space=subwin(stdscr,4,10,13,100);drawSpace3(space, 2);//Virginia
    space=subwin(stdscr,4,10,15,100);drawSpace4(space, 2, "|Pens.Rail");space=subwin(stdscr,4,10,16,100);drawSpace3(space, 2);//Pensilvania
    space=subwin(stdscr,4,10,18,100);drawSpace4(space, 4, "|St. James");space=subwin(stdscr,4,10,19,100);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,21,100);drawSpace4(space, 2, "|  Chest  ");space=subwin(stdscr,4,10,22,100);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,24,100);drawSpace4(space, 4, "| Tennesse");space=subwin(stdscr,4,10,25,100);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,27,100);drawSpace4(space, 4, "| New York");space=subwin(stdscr,4,10,28,100);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,100);drawSpace4(space, 2, "|   FREE  ");space=subwin(stdscr,4,10,31,100);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,90);drawSpace4(space, 1, "|Kentucky ");space=subwin(stdscr,4,10,31,90);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,80);drawSpace4(space, 2, "| Chance  ");space=subwin(stdscr,4,10,31,80);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,70);drawSpace4(space, 1, "| Indiana ");space=subwin(stdscr,4,10,31,70);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,60);drawSpace4(space, 1, "| Illinois");space=subwin(stdscr,4,10,31,60);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,50);drawSpace4(space, 2, "| B. & O. ");space=subwin(stdscr,4,10,31,50);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,40);drawSpace4(space, 4, "|Atlantic ");space=subwin(stdscr,4,10,31,40);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,30);drawSpace4(space, 4, "| Ventnor ");space=subwin(stdscr,4,10,31,30);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,20);drawSpace4(space, 2, "|  Water  ");space=subwin(stdscr,4,10,31,20);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,10);drawSpace4(space, 4, "| Marvins ");space=subwin(stdscr,4,10,31,10);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,30,0);drawSpace4(space, 2, "|GOTO JAIL");space=subwin(stdscr,4,10,31,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,27,0);drawSpace4(space, 6, "| Pacific ");space=subwin(stdscr,4,10,28,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,24,0);drawSpace4(space, 6, "|N.Carolin");space=subwin(stdscr,4,10,25,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,21,0);drawSpace4(space, 2, "|  Chest  ");space=subwin(stdscr,4,10,22,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,18,0);drawSpace4(space, 6, "|Pensilvan");space=subwin(stdscr,4,10,19,0);drawSpace3(space, 2);
 	space=subwin(stdscr,4,10,15,0);drawSpace4(space, 2, "|ShortLine");space=subwin(stdscr,4,10,16,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,12,0);drawSpace4(space, 2, "| Chance  ");space=subwin(stdscr,4,10,13,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,9,0);drawSpace4(space, 7, "|ParkPlace");space=subwin(stdscr,4,10,10,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,6,0);drawSpace4(space, 2, "| Luxury  ");space=subwin(stdscr,4,10,7,0);drawSpace3(space, 2);
    space=subwin(stdscr,4,10,3,0);drawSpace4(space, 7, "|Boardwalk");space=subwin(stdscr,4,10,4,0);drawSpace3(space, 2);
}