#ifndef TIC_TAC_TOE_HUMAN_PLAYER1_H
#define TIC_TAC_TOE_HUMAN_PLAYER1_H

#include "tic_tac_toe_declarations.h"

int place(int plc,int sign)
{
	if(mat[plc]==0)
	{
		mat[plc]=sign;
		return 1;
	}
	else
		return 0;
}

void player_move( int player_sign , SDL_Surface * Screen)
{
	int x,y, flag;

	SDL_Event e;
	bool loop = true ;
	while ( loop )
	{
		while ( SDL_PollEvent ( &e ) )
		{
			SDL_GetMouseState ( &x, &y );
			x = x - 160;
			y = y - 80;
			int sqr = MAT ( x/105, y/105 );
			display ( sqr, Screen );
			if ( e.type == SDL_QUIT ) exit(0);
			if ( e.type == SDL_MOUSEBUTTONUP )
			{
				flag = place ( sqr, player_sign );
				if ( flag == 1 ){ loop = false ; break; }
			}
		}
	}

}

#endif



