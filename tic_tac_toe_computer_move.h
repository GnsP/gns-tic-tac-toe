#ifndef TIC_TAC_TOE_COMPUTER_MOVE1_H
#define TIC_TAC_TOE_COMPUTER_MOVE1_H

#include "tic_tac_toe_declarations.h"

void comp_place(int cmp_sign,int i)
{
	int row,col;
	if(mat[4] == 0 )
	{
		mat[4] = cmp_sign ;
		return;
	}

	if(i==0||i==1||i==2)
	{
		row=i;
		for(col=0;col<3;col++)
		{
			if(mat[MAT(row,col)]==0)
			{
				mat[MAT(row,col)]=cmp_sign;
				break;
			}
		}
	}
	else if(i==3||i==4||i==5)
	{
		col=i-3;
		for(row=0;row<3;row++)
		{
			if(mat[MAT(row,col)]==0)
			{
				mat[MAT(row,col)]=cmp_sign;
				break;
			}
		}
	}
	else if(i==6)
	{
		if(mat[0]==0)
		{
			mat[0]=cmp_sign;
		}
		else if(mat[4]==0)
		{
			mat[4]=cmp_sign;
		}
		else
		{
			mat[8]=cmp_sign;
		}
	}
	else
	{
		if(mat[2]==0)
		{
			mat[2]=cmp_sign;
		}
		else if(mat[4]==0)
		{
			mat[4]=cmp_sign;
		}
		else
		{
			mat[6]=cmp_sign;
		}
	}
}


void computer_move_practice(int player_sign)
{
	int computer_sign;
	int i,j,count,flag;
	int value[8];
	count=0;
	flag=0;
	computer_sign=(player_sign==X)?O:X;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(mat[MAT(i,j)]!=0)
				count++;
		}
	}
	if(count>=0)
	{
		value[0]=mat[0]+mat[1]+mat[2];
		value[1]=mat[3]+mat[4]+mat[5];
		value[2]=mat[6]+mat[7]+mat[8];
		value[3]=mat[0]+mat[3]+mat[6];
		value[4]=mat[1]+mat[4]+mat[7];
		value[5]=mat[2]+mat[5]+mat[8];
		value[6]=mat[0]+mat[4]+mat[8];
		value[7]=mat[2]+mat[4]+mat[6];
		/*::::::::::::::::::::::::::::::::::::*/
		/*------------------------------------*/
		int q, indices[8];
		q = 0;
		while( q < 8 ){
			indices[q] = q;
			q++;
		}

		while(flag==0)
		{
			for(i=0;i<8;i++)
			{
				if(value[indices[i]]==2*computer_sign&&flag==0)
				{
					comp_place(computer_sign,indices[i]);
					flag=1;
				}
				else
					continue;
			}
			if(flag==0)
			{
				for(i=0;i<8;i++)
				{
					if(value[indices[i]]==2*player_sign&&flag==0)
					{
						comp_place(computer_sign,indices[i]);
						flag=1;
					}
				}
			}
			if(flag==0)
			{
				for(i=0;i<8;i++)
				{
					if(value[indices[i]]==player_sign+computer_sign&&flag==0)
					{
						comp_place(computer_sign,indices[i]);
						flag=1;
					}
				}
			}
			if(flag==0)
			{
				for(i=0;i<8;i++)
				{
					if(value[indices[i]]==computer_sign&&flag==0)
					{
						comp_place(computer_sign,indices[i]);
						flag=1;
					}
				}
			}
			if(flag==0)
			{
				for(i=0;i<8;i++)
				{
					if(value[indices[i]]==player_sign&&flag==0)
					{
						comp_place(computer_sign,indices[i]);
						flag=1;
					}
				}
			}
			if(flag==0)
			{
				if(count==0)
				{
					i=randomizer(0,9);
					j=randomizer(0,9);
					mat[MAT(i,j)]=computer_sign;
					flag=1;
				}
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(mat[MAT(i,j)]==0&&flag==0)
						{
							mat[MAT(i,j)]=computer_sign;
							flag=1;
						}
					}
				}
			}
		}
	}
	else
	{
		i=randomizer(0,9);
		j=randomizer(0,9);
		mat[MAT(i,j)]=computer_sign;
		flag=1;
	}
}

int check()
{
	int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	for(int i=0;i<8;i++)
		if(mat[wins[i][0]]!=0 && mat[wins[i][0]] == mat[wins[i][1]] && mat[wins[i][0]] == mat[wins[i][2]] ) return mat[wins[i][0]] ;
	return 0;
}

int minimax ( int player_sign )
{
	int winner = check();
	if ( winner != 0)
		return winner * player_sign;
	int move = -1;
	int score = -2;
	for ( int i =0; i<9; i++)
	{
		if ( mat [i] == 0 )
		{
			mat[i] = player_sign;
			int thisScore = -minimax (player_sign*(-1));
			if ( thisScore > score )
			{
				score = thisScore;
				move = i;
			}
			mat [i] = 0;
		}
	}
	if(  move == -1 ) return 0;
	return score;
}

void computer_move_challenge ( int player_sign )
{
	int move = -1;
	int score = -2;

	int computer_sign;
	computer_sign=(player_sign==X)?O:X;

	for ( int i=0; i < 9; i++)
	{
		if ( mat [i] == 0 )
		{
			mat [i] = computer_sign;
			int temp_score = -minimax ( player_sign );
			mat [i] = 0;
			if ( temp_score > score )
			{
				score = temp_score;
				move = i;
			}
		}
	}
	mat [move] = computer_sign;
}

void computer_move ( int player_sign, SDL_Surface * Screen )
{
	if( GameMode ) computer_move_practice ( player_sign );
	else computer_move_challenge ( player_sign );
	display ( 9, Screen );
}




#endif
