
#include "tic_tac_toe_user_interface.h"

int main(int argc, char *argv[])
{
	SDL_Init ( SDL_INIT_EVERYTHING );
	TTF_Init();

	f = TTF_OpenFont("Fonts/VINERITC.TTF",80);
	xSurf = TTF_RenderText_Blended(f, "X", X_col);
	oSurf = TTF_RenderText_Blended(f, "O", O_col);
	
	game();
	
	SDL_FreeSurface(xSurf);
	SDL_FreeSurface(oSurf);
	free(f);
}


