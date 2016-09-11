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
void drawSpace1(WINDOW *, int);
void drawSpace2(WINDOW *, int);
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
	
	do{
		move(4,110);
		printw("WELCOME TO MONOPOLY");
		move(8,110);
		printw("NEW GAME --> TAP N");
		move(10,110);
		printw("LOAD GAME -> TAP L");
		move(12,110);
		printw("EXIT ------> TAP E");
		move(14,110);
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
				Jugador1=new Player("Juana",1500);
				Jugador2=new Player("Juanito",1500);
				mvprintw(18,80, "New game");
				initscr();
				start_color();
				drawBoard();
			}

			do {
				initscr();
				start_color();
				drawBoard();
				if(Jugador1 -> checkInJail())	//SI EL JUGADOR ESTA EN LA CARCEL
				{	
					mvprintw(4,10, "Player ","You are in jail you must ");
					mvprintw(5,10, "get out to throw the dice again");
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
						mvprintw(4,110, "Player %d",ControlTurno);
						mvprintw(4,110, Jugador1 -> getName().c_str());
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
							Jugador1 -> TurnControl(spaces);
							init_pair(1, COLOR_BLACK, COLOR_WHITE);
							attron(COLOR_PAIR(1));
							srand (time(NULL));
							drawDiceOne(dice1);
							drawDiceTwo(dice2);
							attroff(COLOR_PAIR(1));
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
								mvprintw(6,80,"Gracias por pagar tus impuestos de 200$!");
								Jugador1 -> setMoneyOwned(200);
								//TAXES
							} else if (Espacio ==30) {
								mvprintw(6,80,"Por ser muy Brayan ve directamente a la carcel!");
								Jugador1 -> TurnControl(-20);
								Jugador1 -> setInJail(true);
								//GO TO JAIL
							} else if (Espacio == 20 || Espacio == 10) {
								mvprintw(6,80,"Esta Casilla no hace absolutamente nada!");
								//VISIT JAIL,FREE SPACE NO HACEN NADA SOLO ES EL DIBUJO
							} else if(Espacio != 2 && Espacio != 7 && Espacio != 17 && Espacio != 22 && Espacio != 33 && Espacio != 36 && Espacio != 10 && Espacio != 38
								&& Espacio != 4 && Espacio != 20 && Espacio!=30){
								Espacio--;
								if (board.at(Espacio) -> getOwned()==false)
								{	
									
									if (Jugador1 -> getMoneyOwned() < board.at(Espacio) -> getPrice())
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
										Jugador1 -> setMoneyOwned(board.at(Espacio) -> getPrice());
										board.at(Espacio) -> setOwned(true);
										Jugador1 -> setProperties(board.at(Espacio));
										}
									}						
								}else {//CUANDO ALGUIEN TIENE LA PROPIEDAD
									if (Jugador1 -> validarProperties(board.at(Espacio) -> getTitle()))
									{	
										mvprintw(9,80,board.at(Espacio)->getTitle().c_str());
										mvprintw(8,80,"Esta Propiedad es tuya");	
									}else{//COBRARLE AL JUGADOR LA RENTA
										mvprintw(8,80,"Pagas la renta.");
										mvprintw(9,80,board.at(Espacio) -> getTitle().c_str());
										Jugador1 -> setMoneyOwned(board.at(Espacio) -> getRent());
									}
								}
							}
							echo();
							getch();
							cleanScreen();
						}else if(keyPlayer[0] == '2'){
							//Observar las propiedades
							mvprintw(16,80,Jugador1 -> getProperties().c_str());
						}else if(keyPlayer[0] == '3'){
							//Observar la Informacion del jugador
							mvprintw(15,80, Jugador1 -> toString().c_str());
						}else if(keyPlayer[0] == '4') {//Vender Propiedades
							int Espacio = Jugador1 -> getPosition() - 1;
							if (Jugador1 -> validarProperties(board.at(Espacio) -> getTitle())) {
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
											Jugador1 = Jugador1 -> removeProperty(Jugador1, board.at(Espacio));								
											Jugador1 -> setMoney_Owned((tryTemp -> getPrice()));
											Jugador2 -> setMoneyOwned(board.at(Espacio) -> getPrice());
											Jugador2 -> setProperties(board.at(Espacio));
											mvprintw(14, 80, "Your property has been sold! \n");
										} else if (toWhom[0] == '2')
										{
											Properties* lemmeTrySmth = Jugador1 -> mortgageProperty(board.at(Espacio));
											board.erase(board.begin() + Espacio);
											board.insert(board.begin() + Espacio, lemmeTrySmth);
											mvprintw(14, 80, "You have mortgaged your property!\n");
											
										} else if (toWhom[0] == '3') {
											int mortgageTax = (board.at(Espacio) -> getMortgage()) * 0.1;
											int mortgageDue = board.at(Espacio) -> getMortgage() + mortgageTax;
											if (Jugador1 -> getMoneyOwned() >= mortgageDue && board.at(Espacio) -> getMortgage() > 0)
											{
												Jugador1 -> payMortgage(board.at(Espacio), mortgageDue);
												board.at(Espacio) -> setMortgage(0);
												mvprintw(15, 80, "Mortgage has been lifted. \n");
											} else if (board.at(Espacio) -> getMortgage() == 0 && Jugador1 -> getMoneyOwned() >= mortgageDue)
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
											Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice()/2)); //gain half
											tryTemp -> setHouses(tryTemp -> getHouses() - 1);
										} else if (howmuch[0] == '2' && tryTemp -> getHouses() >= 2)
										{
											Jugador1 -> setMoney_Owned(tryTemp -> getHousePrice()); //for two you gain one
											tryTemp -> setHouses(tryTemp -> getHouses() - 2);
										} else if (howmuch[0] == '3' && tryTemp -> getHouses() >= 3)
										{
											Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice() + tryTemp -> getHousePrice() / 2)); //1 and a half
											tryTemp -> setHouses(tryTemp -> getHouses() - 3);
										} else if (howmuch[0] == '4' && tryTemp -> getHouses() >= 4)
										{
											Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice() * 2)); //2
											tryTemp -> setHouses(tryTemp -> getHouses() - 4);
										} else if (howmuch[0] == '5' && tryTemp -> getHouses() >= 5)
										{
											Jugador1 -> setMoney_Owned((tryTemp -> getHousePrice() * 2 + tryTemp -> getHousePrice() / 2)); //2 and a half
											tryTemp -> setHouses(tryTemp -> getHouses() - 5);
											tryTemp -> setHotels(0);
										}
									}
								}
							} else { //NOTHING
								mvprintw(8,80,"Esta propiedad no te pertenece.");
							}

							echo();
							getch();
							cleanScreen();
						}else if (keyPlayer[0] == '5')//Construir Casas
						{
							//hmmmm hello there, me distraigo rapido, entonces dejo comentado aqui pa saber que tengo que hacer eso bai <3
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
							ficheroSalida2.close();*FIN GUARDADO JUADOR 2/*/
						}
					} else {

					}
				}
			} while (true);
		}else if(key[0] == 'l' || key[0] == 'L'){
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
			myfile>>Nombre;
			myfile>>Temporal;
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
			/*yfile.open("./Jugador2.txt");
			myfile>>Nombre;
			myfile>>Temporal;
			J=Temporal.c_str();
			Dinero=atoi(J);
			myfile>>Temporal;
			J=Temporal.c_str();
			Posicion=atoi(J);
			Jugador2=new Player(Nombre,Dinero);
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
			myfile.close();*/
			mvprintw(16,80, "Load Game Succesful now get a new game to load your last game! ");	
		}
	} while(true);	
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
		init_pair(1,COLOR_BLUE,COLOR_WHITE);
		attron(COLOR_PAIR(1));
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
		attron(COLOR_PAIR(1));
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
		attroff(COLOR_PAIR(1));
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

int drawCard(){ //Recibe la posicion en el vector, si valor<40 el valor retornado será la nueva posicion,
						 //Si valor es mayor a 50 se trata de dinero sumado o restado
	int randCard = rand() % 15;
	int valor = 0;
	string linea[8];
    linea[0] = "**************************\n";
    linea[2] = "*                        *\n";
    linea[6] = "*                        *\n";
    linea[7] = "************************** \n";
   	init_color(COLOR_RED, 230, 95, 0);
    init_pair(1,COLOR_BLACK,COLOR_RED);
    if (randCard == 1){
    	linea[3] = "*                        *\n";
    	linea[4] = "*    You Inherit $100    *\n";
    	linea[5] = "*                        *\n";
    	valor = 100;
    }else if (randCard == 2){
    	linea[3] = "*  You have won second   *\n";
    	linea[4] = "*   price in a beauty    *\n";
    	linea[5] = "*   contest collet $50   *\n";
    	valor = 50;
    }else if (randCard == 3){
    	linea[3] = "*      Bank error        *\n";
    	linea[4] = "*     in your favor      *\n";
    	linea[5] = "*     collect $200       *\n";
    	valor = 200;
    } else if (randCard == 4){
    	linea[3] = "*        Receive         *\n";
    	linea[4] = "*     for services       *\n";
    	linea[5] = "*          $45           *\n";
    	valor = 45;
    }else if (randCard == 5){
    	linea[3] = "*         Life           *\n";
    	linea[4] = "*    insurance mature    *\n";
    	linea[5] = "*      collect $100      *\n";
    	valor = 100;
    }else if (randCard == 6){
    	linea[3] = "*     Bank pays you      *\n";
    	linea[4] = "*      dividends of      *\n";
    	linea[5] = "*          $50           *\n";
    	valor = 50;
    }else if (randCard == 7){
    	linea[3] = "*           Pay          *\n";
    	linea[4] = "*        poor tax        *\n";
    	linea[5] = "*         of $50         *\n";
    	valor = -50;
    }else if (randCard == 8){
    	linea[3] = "*           Pay          *\n";
    	linea[4] = "*         Hospital       *\n";
    	linea[5] = "*           $100         *\n";
    	valor = -100;
    }else if (randCard == 9){
    	linea[3] = "*           Pay          *\n";
    	linea[4] = "*      for services      *\n";
    	linea[5] = "*           $50          *\n";
    	valor = -50;
    }else if (randCard == 10){
    	linea[3] = "*        GO TO JAIL      *\n";
    	linea[4] = "*    do not pass GO      *\n";
    	linea[5] = "*  do not collect $200   *\n";
    	valor = 10;
    }else if (randCard == 11){
    	linea[3] = "*           GO           *\n";
    	linea[4] = "*          BACK          *\n";
    	linea[5] = "*        3 spaces        *\n";
    	valor = -3;
    }else if (randCard == 12){
    	linea[3] = "*       Pay 150 for      *\n";
    	linea[4] = "*          for bad       *\n";
    	linea[5] = "*      	  president      *\n";
    	valor = -150;
    }else if (randCard == 13){
    	linea[3] = "*           GO           *\n";
    	linea[4] = "*          BACK          *\n";
    	linea[5] = "*        5 spaces        *\n";
    	valor = -5;
    }
    else if (randCard == 18){
    	linea[3] = "*       Advance to       *\n";
    	linea[4] = "*        Illinois        *\n";
    	linea[5] = "*         Avenue         *\n";
    	valor = 24;
    }else if (randCard == 15){
    	linea[3] = "*        Go take        *\n";
    	linea[4] = "*       a walk advance  *\n";
    	linea[5] = "*       3 spaces        *\n";
    	valor = 3;
    }
    attron(COLOR_PAIR(1));
    for (int i = 0; i < 8; i++)
    {
    	mvprintw(i+10,20,linea[i].c_str());
	}    
   	attroff(COLOR_PAIR(2));
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
	mvprintw(6,80, "1- Pay 50$ to get out");
	//mvprintw(7,80, "2- Try to get pairs on the dice to get free");
	mvprintw(9,80, "2- Try to get pairs on the dice to get free");
	mvprintw(10,80, "-->");
	getstr(keyPlayer);
	//getch();
	do{
		if(keyPlayer[0] =='1'){
			mvprintw(12,80, "You pay 50$");
			return false;			
		}else if(keyPlayer[0] =='2'){
			drawDiceOne(D1);
			drawDiceTwo(D2);
			getch();
			mvprintw(12,80, "Dices");
			if(D1==D2){
				mvprintw(12,80, "The dices favour you!");				
				return false;
			}else{
				mvprintw(12,80, "The dices don't favour you, stay in jail.");
				return true;
			}
		}
	}while(keyPlayer[0]!=1&&keyPlayer[0]!=2);
		
}
void init_curses()
{
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    init_pair(4,COLOR_BLACK,COLOR_WHITE);
    init_pair(5,COLOR_WHITE,COLOR_YELLOW);
    init_pair(6,COLOR_BLACK,COLOR_BLACK);

    curs_set(0);
    keypad(stdscr,TRUE);
}
void drawSpace1(WINDOW *menubar, int pair)
{
    wattron(menubar,COLOR_PAIR(pair));
    waddstr(menubar,"|-----|");
    waddstr(menubar,"|     |");
    waddstr(menubar,"|     |");
    waddstr(menubar,"|     |");
    waddstr(menubar,"|_____|");
    wattroff(menubar,COLOR_PAIR(pair));
}
void drawSpace2(WINDOW *menubar, int pair){

    wattron(menubar,COLOR_PAIR(pair));
    waddstr(menubar,"|-|");
    waddstr(menubar,"| |");
    waddstr(menubar,"| |");
    waddstr(menubar,"| |");
    waddstr(menubar,"|_|");
    wattroff(menubar,COLOR_PAIR(pair));
}
void drawSpace3(WINDOW *menubar, int pair)
{

    wattron(menubar,COLOR_PAIR(pair));
    waddstr(menubar,"|         ");
    waddstr(menubar,"|         ");
    waddstr(menubar,"|         ");
    waddstr(menubar,"          ");
    wattroff(menubar,COLOR_PAIR(pair));
}
void drawSpace4(WINDOW *menubar, int pair)
{
    wattron(menubar,COLOR_PAIR(pair));
    waddstr(menubar,"          ");
    wattroff(menubar,COLOR_PAIR(pair));
}
void drawBoard(){
	init_curses();
	WINDOW **space[10];
    int pair;
    for (int i = 0; i < 10; i++)
    {
    	space[i] = new WINDOW*[10];

    }
    init_curses();
    int altura=4, ancho=7, x=0, y=0, m=0;
   

    for (int i = 0; i < 10; i++)
    {
    	for (int j = 0; j < 10; j++)
    	{
    		if ((i>=1&&j>=1)&&(i<=8&&j<=8))
    		{
    			space[i][j]=subwin(stdscr,altura,ancho,x,y);
    			y = y+7;
    			drawSpace1(space[i][j], 6);
    			space[i][j]=subwin(stdscr,altura,3,x,y);
    			drawSpace2(space[i][j], 6);
    			y = y+3;    	
    		}else if(i==0  && j==0){
				space[i][j]=subwin(stdscr,1,10,x,m);
    			drawSpace3(space[i][j],4);
   				 space[i][j]=subwin(stdscr,3,10,1,m);
    			drawSpace3(space[i][j],4);
    			m = m+10;

			}
    		else if(i==0  && j>=0){
				space[i][j]=subwin(stdscr,1,10,x,m);
    			drawSpace3(space[i][j],5);
   				 space[i][j]=subwin(stdscr,3,10,1,m);
    			drawSpace3(space[i][j],4);
    			m = m+10;

			}	
			else if(i==9  && j>=0){
				space[i][j]=subwin(stdscr,1,10,36,m);
    			drawSpace3(space[i][j],5);
   				 space[i][j]=subwin(stdscr,3,10,37,m);
    			drawSpace3(space[i][j],4);
    			m = m+10;

			}	
    		else{
    			space[i][j]=subwin(stdscr,altura,ancho,x,y);
    			y = y+7;
    			drawSpace1(space[i][j], 4);
    			space[i][j]=subwin(stdscr,altura,3,x,y);
    			drawSpace2(space[i][j], 5);
    			y = y+3;    	
    		}
    			
    	}
    	y =0;
    	m=0;
    	x = x+4;
    	
    }
    

    refresh();
}