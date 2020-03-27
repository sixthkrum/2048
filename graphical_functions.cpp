#include<random>
#include<iostream>
#include "graphical_functions.h"
#include<ncurses.h>

int matrix_make()//assumes initscr raw noecho

{

int i0;
int i1;

for(i0 = 0; i0 < 12; i0 = i0 + 3)//dist b/w top of blocks is 3 and we need to do this operation 4 times hence the 3 * 4 = 12 changing the value of i0 here allows me to not change the value in the loop and makes for less number of operations

{

for(i1 = 0; i1 < 29; i1 ++)//block width is 7 and there are 4 blocks but there is a line at the end of the last block so we add another dash for that line hence the 7 * 4 + 1

{

mvprintw(i0 , i1 , "-");

}

for(i1 = 0; i1 < 5; i1 ++)//there are 4 blocks and the spacing is done through the multiplier in the mv function

{

mvprintw(i0 + 1 , i1 * 7 , "|");

}


for(i1 = 0; i1 < 29; i1 ++)// same as the first loop but this one is here so that i dont have to write another loop outside the nest to close off the box, this gives us double lines in the middle rows seperations

{

mvprintw(i0 + 2 , i1 , "-");//i0 iteration done for spacing in conjuction with the explanation in the top loop

}

}

refresh();

return 1;

}


int empty_cell(int y, int x)

{

mvprintw(y * 3 + 1 , x * 7 + 1 , "     ");

return 1;

}


int fill_cell(int num, int y, int x)

{

mvprintw(y * 3 + 1 , x * 7 + 1 , "%d" , num);

return 1;

}


int numbers_set(int numarr[4][4])//sets numbers from array into matrix//assumes initscr raw noecho

{

int i0;
int i1;
int empty_spaces;
empty_spaces = 0;

for(i0 = 0; i0 < 4; i0 ++)

{

for(i1 = 0; i1 < 4; i1 ++)

{

empty_cell ( i0 , i1 );

if(numarr[i0][i1] != 0)

{

fill_cell ( numarr[i0][i1] , i0 , i1 );

}

else

{

empty_spaces ++;

}

}

}

refresh();

return empty_spaces;

}

//slow method for the sake of completion


int rand_int_mersenne_twister(int to, int from = 1)

{

int rand;
std::random_device rd{};
std::mt19937 engine{rd()};
std::uniform_real_distribution<float> dist{from, to};
rand = dist(engine);

return rand;

}

int insert_new_number(int numarr[4][4], int empty_spaces)

{

int position;
int new_int;
int i0;
int i1;
position = rand_int_mersenne_twister(empty_spaces);

if(rand_int_mersenne_twister(100) <= 10)

{

new_int = 4;

}

else

{

new_int = 2;

}

for(i0 = 0; i0 < 4; i0 ++)

{

for(i1 = 0; i1 < 4; i1 ++)

{

if(numarr[i0][i1] == 0)

{

position --;

if(position == 0)

{

numarr[i0][i1] = new_int;
fill_cell(numarr[i0][i1] , i0 , i1);

}

}

}

}

return 1;

}
