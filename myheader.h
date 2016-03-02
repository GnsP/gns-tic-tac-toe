#ifndef MY_HEADER_H
#define MY_HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
//#include <conio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>


void spause()
{
	printf("\n\nPress any key to continue...");
	getche();
	printf("\n");
}
void spause_c(char *message)
{
	printf("\n\n%s",message);
	getche();
	printf("\n");
}

int randomizer(int range_min,int range_max)
{
	int temp,diff;
	srand(time(NULL));
	diff=range_max-range_min;
	temp=rand()%diff+range_min;
	return temp;
}




#endif
