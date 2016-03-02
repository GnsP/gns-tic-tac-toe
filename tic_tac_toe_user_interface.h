#ifndef TIC_TAC_TOE_USER_INTERFACE1_H
#define TIC_TAC_TOE_USER_INTERFACE1_H

#include "tic_tac_toe_game_core.h"
#include <assert.h>

void start_screen(SDL_Surface *Screen)
{
	static int cnt;
	if(cnt==0)
	{
		SDL_Surface * page_ = SDL_LoadBMP ("Images/bg_1.bmp");
		SDL_Surface *page = page_;

		SDL_Rect pageRect;
		pageRect.x=0;
		pageRect.y=0;

		SDL_Color col1 = {180,120,230};
		SDL_Color col2 = {220,180,80};
		SDL_Color col3 = {50,160,220};

		TTF_Font *f1_ = TTF_OpenFont("Fonts/GOUDYSTO.TTF",40);
		TTF_Font *f1 = f1_;

		TTF_Font *f2_ = TTF_OpenFont("Fonts/VINERITC.TTF",50);
		TTF_Font *f2 = f2_;

		TTF_Font *f3_ = TTF_OpenFont("Fonts/LCD.ttf",40);
		TTF_Font *f3 = f3_;

		SDL_Surface * Surf1_ = TTF_RenderText_Blended(f1, "TIC TAC TOE", col1);
		SDL_Surface * Surf2_ = TTF_RenderText_Blended(f2, "by Ganesh Prasad", col2);
		SDL_Surface * Surf3_ = TTF_RenderText_Blended(f3, "[ CLICK TO CONTINUE ]", col3);

		SDL_Surface *Surf1 = Surf1_;
		SDL_Surface *Surf2 = Surf2_;
		SDL_Surface *Surf3 = Surf3_;

		SDL_Rect R1,R2,R3;
		R1.x = 100;
		R1.y = 100;
		R2.x = 100;
		R2.y = 250;
		R3.x = 150;
		R3.y = 420;

		SDL_BlitSurface ( Surf1, 0, page, &R1 );
		SDL_BlitSurface ( Surf2, 0, page, &R2 );
		SDL_BlitSurface ( Surf3, 0, page, &R3 );

		SDL_BlitSurface ( page, 0, Screen, &pageRect );
		SDL_Flip ( Screen );


		SDL_FreeSurface(page_);
		SDL_FreeSurface(Surf1_);
		SDL_FreeSurface(Surf2_);
		SDL_FreeSurface(Surf3_);

		free(f1_);
		free(f2_);
		free(f3_);
	}
	cnt++;
}

void game()
{
	int p;
	static int count;

	atexit ( SDL_Quit );

	SDL_Surface *Screen_ = SDL_SetVideoMode ( 640, 480, 0, SDL_SWSURFACE|SDL_DOUBLEBUF );
	SDL_Surface *Screen = Screen_;
	SDL_WM_SetCaption ( "Gns TIC TAC TOE -- v.01.00", 0 );

	if(count==0)
	{
		start_screen(Screen);
		bool running = true;
		SDL_Event e;
		while ( running )
		{
			while(SDL_PollEvent(&e))
			{
				if ( e.type == SDL_QUIT ){
					SDL_FreeSurface(Screen_);
					SDL_Quit();
					exit( 0 );
				}
				if ( e.type == SDL_KEYUP || e.type == SDL_MOUSEBUTTONUP )
				{	running = false; break; }
			}
		}
	}
	p = 27 ;
	while(p==27)
	{
		initialise();
		p = play ( Screen );
	}

	SDL_FreeSurface(Screen_);
}


#endif
