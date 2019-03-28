// This file contains screen functions. They are used to display sound levels
// on a putty screen as a bar chart

#include <stdio.h>
#include "screen.h"

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout); //output the escaoe sequense immediately
}

void setColors(short bg, short fg){
	printf("\033[%d;%d;1m", bg, fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}

void barChart(int db[]){
	int i, j;
	for(i=0; i<COL; i++){ //for 80 columns
		for(j=0; j<db[i]/3; j++){
			printf("\033[%d;%dH", 60-j, i+1);
			printf("%s", BAR);
		}
	}
}
