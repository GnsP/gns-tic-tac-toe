#ifndef TIC_TAC_TOE_GAME_CORE1_H
#define TIC_TAC_TOE_GAME_CORE1_H

#include "tic_tac_toe_human_player.h"
#include "tic_tac_toe_computer_move.h"


int play( SDL_Surface *Screen)
{
	int player_sign,winner,flag,res = 0;
	char p;

	SDL_Surface *page_1 = SDL_LoadBMP ( "Images/bg_1.bmp" );
	SDL_Rect page1_Rect;
	page1_Rect.x=0;
	page1_Rect.y=0;

	SDL_Color col1 = {180,120,230};
	//SDL_Color col2 = {220,180,80};
	//SDL_Color col3 = {50,160,220};
	
	//------------------------------
	
	TTF_Font *f1 = TTF_OpenFont("Fonts/RAVIE.TTF",40);
	SDL_Surface * Surf1 = TTF_RenderText_Blended(f1, "Select Game Mode :", col1);
	SDL_Surface * Surf2 = SDL_LoadBMP ( "Images/practice.bmp");
	SDL_Surface * Surf3 = SDL_LoadBMP ( "Images/challenge.bmp");


	SDL_Rect R1,R2,R3;
	R1.x = 50;
	R1.y = 100;
	R2.x = 140;
	R2.y = 350;
	R3.x = 350;
	R3.y = 350;

	SDL_BlitSurface ( Surf1, 0, page_1, &R1 );
	SDL_BlitSurface ( Surf2, 0, page_1, &R2 );
	SDL_BlitSurface ( Surf3, 0, page_1, &R3 );

	SDL_BlitSurface ( page_1, 0, Screen, &page1_Rect );
	SDL_Flip ( Screen );

    bool pageRunning = true;
    SDL_Event e;
    int x,y;
	while ( pageRunning )
	{
		while ( SDL_PollEvent ( &e ))
		{
			SDL_GetMouseState ( &x, &y );

			if ( e.type == SDL_QUIT )
				exit (0);
			if ( e.type == SDL_MOUSEBUTTONUP )
			{
				if ( x > 140 && y > 350 && x < 290 && y < 430 )
				{
					pageRunning = false;
					GameMode = 1;
					break;
				}

				if ( x > 350 && y > 350 && x < 500 && y < 430 )
				{
					pageRunning = false;
					GameMode = 0 ;
					break;
				}
			}
		}
	}
	
	//------------------------------
	SDL_FreeSurface(page_1);
	SDL_FreeSurface(Surf1);
	SDL_FreeSurface(Surf2);
	SDL_FreeSurface(Surf3);

	page_1 = SDL_LoadBMP ( "Images/bg_1.bmp" );
	
	f1 = TTF_OpenFont("Fonts/RAVIE.TTF",40);
	Surf1 = TTF_RenderText_Blended(f1, "What will you take ?", col1);
	Surf2 = SDL_LoadBMP ( "Images/X.bmp");
	Surf3 = SDL_LoadBMP ( "Images/O.bmp");

	R1.x = 50;
	R1.y = 100;
	R2.x = 140;
	R2.y = 350;
	R3.x = 350;
	R3.y = 350;

	SDL_BlitSurface ( Surf1, 0, page_1, &R1 );
	SDL_BlitSurface ( Surf2, 0, page_1, &R2 );
	SDL_BlitSurface ( Surf3, 0, page_1, &R3 );

	SDL_BlitSurface ( page_1, 0, Screen, &page1_Rect );
	SDL_Flip ( Screen );

    pageRunning = true;
	while ( pageRunning )
	{
		while ( SDL_PollEvent ( &e ))
		{
			SDL_GetMouseState ( &x, &y );

			if ( e.type == SDL_QUIT )
				exit (0);
			if ( e.type == SDL_MOUSEBUTTONUP )
			{
				if ( x > 140 && y > 350 && x < 290 && y < 430 )
				{
					pageRunning = false;
					p = 'P';
					player_sign = X;
					break;
				}

				if ( x > 350 && y > 350 && x < 500 && y < 430 )
				{
					pageRunning = false;
					p = 'C';
					player_sign = O;
					break;
				}
			}
		}
	}
	display (9, Screen) ;
	if(p=='P')
	{
		player_move(X, Screen);
		flag=1;
	}
	else
	{
		computer_move(O,Screen);
		flag=1;
	}
	winner=check();
	while(winner==0)
	{
		if(flag%2==0)
		{
			if(p=='P') player_move(player_sign, Screen);
			else computer_move(player_sign,Screen);
		}
		else
		{
			if(p=='P') computer_move(player_sign,Screen);
			else player_move(player_sign, Screen);
		}
		winner=check();
		flag++;
		if(flag==9)
		{
			winner=100;
			break;
		}
	}
	display(9, Screen);

	SDL_FreeSurface(page_1);
	SDL_FreeSurface(Surf1);
	SDL_FreeSurface(Surf2);

	page_1 = SDL_LoadBMP ( "Images/bg_1.bmp" );
	page1_Rect.x=0;
	page1_Rect.y=0;
	f1 = TTF_OpenFont("Fonts/GOUDYSTO.TTF",25);

	if(winner==player_sign)
		Surf1 = TTF_RenderText_Blended(f1, "CONGRATS ! YOU WON !!!", col1);
	else if(winner==100)
		Surf1 = TTF_RenderText_Blended(f1, "OOPS ... GAME DRAW !!!", col1);
	else
		Surf1 = TTF_RenderText_Blended(f1, "SORRY ! COMPUTER WINS !", col1);
	R1.x = 50;
	R1.y = 220;

	Surf2 = SDL_LoadBMP ( "Images/play_again.bmp" );
	R2.x = 170;
	R2.y = 300;

	SDL_BlitSurface ( Surf1, 0, page_1, &R1 );
	SDL_BlitSurface ( Surf2, 0, page_1, &R2 );

	SDL_BlitSurface ( page_1, 0, Screen, &page1_Rect );
	SDL_Flip ( Screen );

	pageRunning = true;
	while ( pageRunning )
	{
		while ( SDL_PollEvent ( &e ))
		{
			SDL_GetMouseState ( &x, &y );

			if ( e.type == SDL_QUIT )
				exit (0);
			if ( e.type == SDL_MOUSEBUTTONUP )
			{
				if ( x > 170 && y > 300 && x < 470 && y < 420 )
				{
					res = 27;
					pageRunning = false;
					break;
				}
			}
		}
	}

	// free allocated memory
	SDL_FreeSurface(page_1);
	free(f1);
	SDL_FreeSurface(Surf1);
	SDL_FreeSurface(Surf2);
	SDL_FreeSurface(Surf3);

	return res;
}

void initialise()
{
	int i;
	for(i=0;i<9;i++)
		mat[i] = 0;
}

#endif

