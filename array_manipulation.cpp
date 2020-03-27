#include "array_manipulation.h"

int components_move_up(int numarr[4][4])//moves components up until they reach the boundary or they touch another component uppermost components are moved first and empty spaces have zeros in them if two similar components touch then the bottom most one dissapears and the uppermost one is doubled

{

int i0;
int i1;
unsigned int lastnum;
unsigned int shiftcounter;
bool did_we_move = 0;

for(i0 = 0; i0 < 4; i0 ++)

{

lastnum = 0;
shiftcounter = 1;

for(i1 = 0; i1 < 4; i1 ++)

{

if(numarr[i1][i0] == 0)

{

shiftcounter ++;

}

else

{

if(numarr[i1][i0] == lastnum)

{

did_we_move = 1;
numarr[i1][i0] = 0;
numarr[i1 - shiftcounter][i0] = 2 * numarr[i1 - shiftcounter][i0];
lastnum = 0;
shiftcounter ++;

}

else if(shiftcounter == 1)

{

lastnum = numarr[i1][i0];

}

else if(shiftcounter != 1)

{

did_we_move = 1;
lastnum = numarr[i1][i0];
numarr[i1 - shiftcounter + 1][i0] = numarr[i1][i0];
numarr[i1][i0] = 0;

}

}

}

}

return did_we_move;

}

int components_move_down(int numarr[4][4])

{

int i0;
int i1;
unsigned int lastnum;
unsigned int shiftcounter;
bool did_we_move = 0;

for(i0 = 0; i0 < 4; i0 ++)

{

lastnum = 0;
shiftcounter = 1;

for(i1 = 3; i1 >= 0; i1 --)

{

if(numarr[i1][i0] == 0)

{

shiftcounter ++;

}

else

{

if(numarr[i1][i0] == lastnum)

{

did_we_move = 1;
numarr[i1][i0] = 0;
numarr[i1 + shiftcounter][i0] = 2 * numarr[i1 + shiftcounter][i0];
lastnum = 0;
shiftcounter ++;

}

else if(shiftcounter == 1)

{

lastnum = numarr[i1][i0];

}

else if(shiftcounter != 1)

{

did_we_move = 1;
lastnum = numarr[i1][i0];
numarr[i1 + shiftcounter - 1][i0] = numarr[i1][i0];
numarr[i1][i0] = 0;

}

}

}

}

return did_we_move;

}

int components_move_left(int numarr[4][4])

{

int i0;
int i1;
unsigned int lastnum;
unsigned int shiftcounter;
bool did_we_move = 0;

for(i0 = 0; i0 < 4; i0 ++)

{

lastnum = 0;
shiftcounter = 1;

for(i1 = 0; i1 < 4; i1 ++)

{

if(numarr[i0][i1] == 0)

{

shiftcounter ++;

}

else

{

if(numarr[i0][i1] == lastnum)

{

did_we_move = 1;
numarr[i0][i1] = 0;
numarr[i0][i1 - shiftcounter] = 2 * numarr[i0][i1 - shiftcounter];
lastnum = 0;
shiftcounter ++;

}

else if(shiftcounter == 1)

{

lastnum = numarr[i0][i1];

}

else if(shiftcounter != 1)

{

did_we_move = 1;
lastnum = numarr[i0][i1];
numarr[i0][i1 - shiftcounter + 1] = numarr[i0][i1];
numarr[i0][i1] = 0;

}

}

}

}

return did_we_move;

}

int components_move_right(int numarr[4][4])

{

int i0;
int i1;
unsigned int lastnum;
unsigned int shiftcounter;
bool did_we_move = 0;

for(i0 = 0; i0 < 4; i0 ++)

{

lastnum = 0;
shiftcounter = 1;

for(i1 = 3; i1 >= 0; i1 --)

{

if(numarr[i0][i1] == 0)

{

shiftcounter ++;

}

else

{

if(numarr[i0][i1] == lastnum)

{

did_we_move = 1;
numarr[i0][i1] = 0;
numarr[i0][i1 + shiftcounter] = 2 * numarr[i0][i1 + shiftcounter];
lastnum = 0;
shiftcounter ++;

}

else if(shiftcounter == 1)

{

lastnum = numarr[i0][i1];

}

else if(shiftcounter != 1)

{

did_we_move = 1;
lastnum = numarr[i0][i1];
numarr[i0][i1 + shiftcounter - 1] = numarr[i0][i1];
numarr[i0][i1] = 0;

}

}

}

}

return did_we_move;

}

int check_if_possible_to_move(int numarr[4][4])//only runs if empty_spaces is equal to zero otherwise does not run

{

int i0;
int i1;
unsigned int lastnum = 0;
bool possible_to_move = 0;

for(i0 = 0; i0 < 4; i0 ++)//from up to down check

{

lastnum = 0;

for(i1 = 0; i1 < 4; i1 ++)

{

if(numarr[i1][i0] == lastnum)

{

possible_to_move = 1;
return possible_to_move;

}

lastnum = numarr[i1][i0];

}

}

for(i0 = 0; i0 < 4; i0 ++)//from down to up check

{

lastnum = 0;

for(i1 = 3; i1 >= 0; i1 --)

{

if(numarr[i1][i0] == lastnum)

{

possible_to_move = 1;
return possible_to_move;

}

lastnum = numarr[i1][i0];

}

}

for(i0 = 0; i0 < 4; i0 ++)//left to right

{

lastnum = 0;

for(i1 = 0; i1 < 4; i1 ++)

{

if(numarr[i0][i1] == lastnum)

{

possible_to_move = 1;
return possible_to_move;

}

lastnum = numarr[i0][i1];

}

}

for(i0 = 0; i0 < 4; i0 ++)//right to left

{

lastnum = 0;

for(i1 = 3; i1 >= 0; i1 --)

{

if(numarr[i0][i1] == lastnum)

{

possible_to_move = 1;
return possible_to_move;

}

lastnum = numarr[i0][i1];

}

}

return possible_to_move;

}
