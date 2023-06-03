#ifndef __TICTAC__H__
#define __TICTAC__H__

/*Prototype de fonctions*/


typedef enum{

false,true

}BOOL;

void initialize();
void gamedisplay();
int COUNT_ARR();
int player_move1();
int player_move2();
void game_against_ordi1();
void game_against_ordi1();
int computer_move();
int check(int x,int y);
int check_winner();




#endif