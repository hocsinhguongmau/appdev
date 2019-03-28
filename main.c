#include <stdio.h>
#include <stdlib.h> //for random number
#include "screen.h"

int main(){
	int dec[COL]; //80 pieces of sound decibels
	for(int i=0; i<COL; i++){
		dec[i] = rand()%70+30;
	}
	clearScreen();
	setColors(CYAN, bg(YELLOW));
	barChart(dec);
	resetColors();
	getchar();
}
