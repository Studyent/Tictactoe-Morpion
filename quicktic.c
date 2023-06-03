#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "TICTAC.h"





char game[3][3];
char name1[10];
char name2[10];
short option;

typedef struct Player{

short posx;
short posy;

char name[10];
short turn;
}Player;

Player player1;
Player player2;







void initialize(){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            game[i][j] = ' ';
        }
    }
}

// A revoir, erreur lorsque le tableau est plein.
int COUNT_ARR(){
    int count = 9;
    for (int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(game[i][j] != ' '){
                count--;
        }
    }
}
return count;
}

int player_move1(){
    int x,y;
    printf("line 1-3\n");
    scanf("%d",&x);
    x--;
    printf("column 1-3\n");
    scanf("%d",&y);
    y--;
 while((x<0 || y<0) || (x>3 || y>3) || (check(x,y) == 1)){
    printf("Either line or column is out of range\n");
    printf("Correct coordinate needs to be input\n");
    printf("line 1-3\n");
    scanf("%d",&x);
    x--;
    
    printf("column 1-3\n");
    scanf("%d",&y);
    y--;

 }
printf("\n");
player2.posx = x;
player2.posy = y;

game[x][y] = '0';

}

int player_move2(){
    int x,y;
    printf("line 1-3\n");
    scanf("%d",&x);
    x--;
    printf("column 1-3\n");
    scanf("%d",&y);
    y--;
 while((x<0 || y<0) || (x>3 || y>3) || (check(x,y) == 1)){
    printf("Either line or column is out of range\n");
    printf("Correct coordinate needs to be input\n");
    printf("line 1-3\n");
    scanf("%d",&x);
    x--;
    
    printf("column 1-3\n");
    scanf("%d",&y);
    y--;

 }
printf("\n");
player2.posx = x;
player2.posy = y;


game[x][y] = 'X';


}

int check(int x, int y){

int a = x;
    int b = y;

        if(game[a][b] != ' '){
            printf("espace occupe\n");
            return 1;
        }

return 0;
}

int computer_move(){
 int x,y;
 time_t t;
 srand(time(&t));

do{
x = rand() %3;
y = rand() %3;
}while(check(x,y) == 1);

game[x][y] = 'X';

}

int check_winner(){
for(int i = 0; i < 3; i++){
    if((game[i][0] == game[i][1]) && (game[i][0] == game[i][2])){
        return game[i][0];
    }
}
for(int i = 0; i < 3; i++){
    if((game[0][i] == game[1][i]) && (game[0][i] == game[2][i])){
        return game[i][0];
    }
}
if((game[0][0] == game[1][1]) && (game[0][0] == game[2][2])){
        return game[0][0];
    }
if((game[0][2] == game[1][1]) && (game[0][2] == game[3][0])){
        return game[0][2];
    }

return ' ';
}


// && ((x && y)) > 0 

void gamedisplay(){

printf("To play tic tac toe nothing is easier, input a value for the line/column between 1-3\n");
printf("If you manage to get a full line/column/diagonal you win!\n");



printf("-----TIC TAC TOE-----\n");
printf("| %c | %c | %c |\n",game[0][0],game[0][1],game[0][2]);
printf("| %c | %c | %c |\n",game[1][0],game[1][1],game[1][2]);
printf("| %c | %c | %c |\n",game[2][0],game[2][1],game[2][2]);
printf("-------------------\n");

}

void game_against_ordi1(){
initialize();
char Gagnant = ' ';
while(Gagnant == ' '){
//game[0][0] =  '0';




gamedisplay();
player_move1();
Gagnant = check_winner();
if(Gagnant != ' '){
    printf("Vous gagnez contre le joueur ORDI, quel talent ! \n");

    break;
}
if(COUNT_ARR() == 0){
    printf("Dommage ! \n");

    break;
}

computer_move();
Gagnant = check_winner();
if(Gagnant != ' '){
    printf("Le gagnant est joueur: ORDI, tu es nulle vraiment\n");
    break;
    
}
if(COUNT_ARR() == 0){
    printf("Dommage ! \n");

    break;
}
};
}

void game_against_ordi2(){
initialize();
char Gagnant = ' ';
short tour = 0;


while(Gagnant == ' '){
//game[0][0] =  '0';




gamedisplay();
tour += 1;
printf("Turn: %d\n",tour);
printf("Player : %s your turn !\n",name1);
player_move1();

Gagnant = check_winner();
if(Gagnant != ' '){
    printf("Gagnant:%s ! \n",name1);

    break;
}

if(COUNT_ARR() == 0){
    printf("Dommage ! \n");

    break;
}
gamedisplay();
printf("Player : %s your turn !\n",name2);
player_move2();

Gagnant = check_winner();
if(Gagnant != ' '){
    printf("Le gagnant est joueur: %s, tu es nulle vraiment\n",name2);  
    

    break;
    
}
if(COUNT_ARR() == 0){
    printf("Dommage ! \n");

    break;
}
};
}

// This function is built to record the 2 players game;





void record_game(struct Player*player,int tour){

FILE *record = NULL; 
    record = fopen("test.txt", "a+");
    if(record == NULL){
        printf("Can't open test.txt");
    }
        player->turn = tour;
        fprintf(record,"Info joueur: \n");
        fprintf(record,"\tNom: %s\n",player->name);
        fprintf(record,"\tTour: %d\n",player->turn);
        fprintf(record,"\tLigne X: [%d]\n",player->posx);
        fprintf(record,"\tColonne Y: [%d]\n",player->posy);

fclose(record);
  
}



int main(int argc, char **argv){
/*
I thought about implementing a stack for the players, but for a simple game,
like that it would be a waste of memory.

Player player1;
Player player2;
*/

// use of a switch to determine against who the player shall play

printf("Welcome to MORPION\n");
printf("---Please select your opponent---\n");
printf("\n");
printf("##########################\n");
printf("##------OPPONENTS------ ##\n");
printf("##----1: COMPUTER AI----##\n");
printf("##----2: TWO PLAYERS----##\n");
printf("##########################\n");
printf("Input your choice:\t");
scanf("%d",&option);
printf("\n");

switch(option){
    case 1:
    game_against_ordi1();
    break;
    case 2:
    
    printf("Enter the name of player 1:\n");
    scanf("%s",&name1);
    strcpy(player1.name,name1);
    printf("Enter the name of player 2:\n");
    scanf("%s",&name2);
    strcpy(player2.name,name2);
    game_against_ordi2();
    break;

default:
printf("Didnt understand try again\n");
exit(1);
}




    return 0;
}