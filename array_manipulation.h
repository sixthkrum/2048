int components_move_up(int numarr[4][4]);//moves components up until they reach the boundary or they touch another component uppermost components are moved first and empty spaces have zeros in them if two similar components touch then the bottom most one dissapears and the uppermost one is doubled

int components_move_down(int numarr[4][4]);

int components_move_left(int numarr[4][4]);

int components_move_right(int numarr[4][4]);

int check_if_possible_to_move(int numarr[4][4]);//only runs if empty_spaces is equal to zero otherwise does not run
