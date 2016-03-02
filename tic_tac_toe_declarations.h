#ifndef TIC_TAC_TOE_DECLARATIONS_H
#define TIC_TAC_TOE_DECLARATIONS_H


#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>

#define X 1
#define O -1
#define E 0
#define MAT(i,j) i*3+j

int GameMode = 1;

int mat[9]={0,0,0,0,0,0,0,0,0};
char up,down,left,right,enter;

int randomizer(int range_min,int range_max)
{
	int temp,diff;
	srand(time(NULL));
	diff=range_max-range_min;
	temp=rand()%diff+range_min;
	return temp;
}


int player_assign()
{
	int temp;
	temp=randomizer(0,2);
	if(temp==0)
		return O;
	else
		return X;
}



SDL_Color X_col = {20,60,150};
SDL_Color O_col = {150,60,20};
	
TTF_Font *f; // = TTF_OpenFont("Fonts/VINERITC.TTF",80);
SDL_Surface * xSurf; // = TTF_RenderText_Blended(f, "X", X_col);
SDL_Surface * oSurf; // = TTF_RenderText_Blended(f, "O", O_col);


void display(int selected, SDL_Surface *Screen)
{
	int i,j;
	SDL_Surface *Board = SDL_LoadBMP("Images/board.bmp");
	SDL_Rect boardRect;
	boardRect.x=160;
	boardRect.y=80;
	
    
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(MAT(i,j)==selected)
				boxRGBA ( Board, i*105+5,j*105+5, (i+1)*105+5, (j+1)*105+5, 255, 255, 150, 255 );
			else
				boxRGBA ( Board, i*105+5,j*105+5, (i+1)*105+5, (j+1)*105+5, 255, 255, 255, 180 );
				
			if( mat[MAT(i,j)] == X )
			{
				SDL_Rect temp;
				temp.x = i*105+15;
				temp.y = j*105+15;
				
				SDL_BlitSurface ( xSurf, 0, Board, &temp );
			}
			
			if( mat[MAT(i,j)] == O )
			{
				SDL_Rect temp;
				temp.x = i*105+15;
				temp.y = j*105+15;
				
				SDL_BlitSurface ( oSurf, 0, Board, &temp );
			}
		}
	}
	SDL_BlitSurface ( Board, 0, Screen, &boardRect );
	SDL_Flip ( Screen );

	// free the memory allocated within this function
	SDL_FreeSurface(Board);
}

#endif
