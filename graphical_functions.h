#ifndef GRAPHICAL_FUNCTIONS_H
#define GRAPHICAL_FUNCTIONS_H

int matrix_make();//assumes initscr raw noecho

int numbers_set(int numarr[4][4]);//sets numbers from array into matrix//assumes initscr raw noecho

int rand_int_mersenne_twister(int to, int from );

int empty_cell(int y, int x);

int fill_cell(int num, int y, int x);

int insert_new_number(int numarr[4][4], int empty_spaces);

#endif
