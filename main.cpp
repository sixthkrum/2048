#include<iostream>

#include<ncurses.h>

#include<unistd.h>

#include"graphical_functions.h"

#include"array_manipulation.h"

int main()

{

initscr();
raw();
curs_set(0);
noecho();
keypad(stdscr , 1);
attron(A_BOLD);
int c;
matrix_make();
int numarr[4][4] = {{0 , 0 , 0 , 0} , {0 , 0 , 0 , 0} , {0 , 0 , 0 , 0} , {0 , 0 , 0 , 0}}; 
int empty_spaces = 16;//full array size as we need a location to put our random number in and in the beginning we have akll the spots available but could be anything if we call numbers_set at the beginning of the loop
bool did_we_move = TRUE;
bool possible_to_move = TRUE;

while(possible_to_move)

{

if(did_we_move == TRUE)

{

empty_spaces = numbers_set(numarr);
insert_new_number(numarr , empty_spaces);
empty_spaces --;

}

if(empty_spaces == 0  && !check_if_possible_to_move(numarr))

{

possible_to_move = FALSE;

}

c = wgetch(stdscr);

switch (c)

{

case KEY_UP : 
did_we_move = components_move_up(numarr);
break;

case KEY_DOWN : 
did_we_move = components_move_down(numarr);
break;

case KEY_LEFT : 
did_we_move = components_move_left(numarr);
break;

case KEY_RIGHT : 
did_we_move = components_move_right(numarr);
break;

case 113 :
endwin();
exit(0);
break;

default :
break;

}

}

mvprintw(13 , 10 ,"GAME OVER");
getch();
endwin();

return 1;

}
