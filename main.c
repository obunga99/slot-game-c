#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int running = 1;
int playing = 0;
int bank = 500;
char grid[5][5];


static char inp_anlz(char inp);
static void make_space();
static void draw_grid();
char grid_anlz(char grid[5][5]);

int main()
{
	while(running == 1)
	{
		char inp;
		printf("You are here either you died or just got here.\n");
		printf("				what do you want to do?\n");
		printf("				[q]uit, [p]lay\n");
		scanf("%c", &inp);
		make_space();
		inp_anlz(inp);
		


	}
	return 0;
}



static char inp_anlz(char inp)
{
	switch(inp)
	{
		case 'q':
			printf("				exiting...\n");
			running = 0;
			break;

		case 'p':
			playing = 1;
			printf("				[s]pin, [q]uit\n");
			printf("				when you are out of balance you are out literaly, you get free 500 balance every new game.\n");
	
			while(playing==1)
			{
				char inp;
				scanf("%c", &inp);
				
				switch(inp)
				{
					case 'q':
						printf("				exiting to menu...\n");
						playing = 0;
						break;

					case 's':
						make_space();
						
						draw_grid();
						printf("				[s]pin or Enter to spin, [q]uit\n");
						printf("				when you are out of balance you are out literaly.\n");
	
						break;

					case '\n':
						make_space();
						
						draw_grid();
						printf("				[s]pin or Enter to spin, [q]uit\n");
						printf("				when you are out of balance you are out literaly.\n");
	
						break;
				}

				
			}
			break;

	}
}

static void make_space()
{
	for(int i = 0; i <= 100; i++)
	{
		printf("\n");
		printf("\n");
	}
}


static void draw_grid()
{
	int randInt;
	//a 4x4 grid where the game is played sort of
	char outcome[5] = {'G', 'A', 'B', 'S', '\0'};//the four outcomes for each of the slots on the grid
			//G for great, A for good, B for bad, S for shit
	grid[5][5] = '\0';
	
	for(int i = 0; i <= 3; i++)
	{
		for(int j = 0; j <= 3; j++)
		{
			randInt = (rand() % 4);
			grid[i][j] = outcome[randInt];
			
			switch(grid[i][j])
			{
				case 'G':
					bank = bank + 10;
					break;

				case 'A':
					bank = bank + 5;
					break;

				case 'B':
					bank = bank - 4;
					break;

				case 'S':
					bank = bank - 14;
					break;
			}

			if(bank <= 0)playing = 0;
				
		}
	}


	printf("				Balance: %d\n", bank);
	printf("				======================\n");
	printf("				|| %c || %c || %c || %c ||\n",grid[0][0], grid[1][0], grid[2][0], grid[3][0]);
	printf("				||====================\n");
	printf("				|| %c || %c || %c || %c ||\n",grid[0][1], grid[1][1], grid[2][1], grid[3][0]);
	printf("				||==================||\n");
	printf("				|| %c || %c || %c || %c ||\n",grid[0][2], grid[1][2], grid[2][2], grid[3][2]);
	printf("				======================\n");
       	printf("				|| %c || %c || %c || %c ||\n",grid[0][3], grid[1][3], grid[2][3], grid[3][3]);
	printf("				======================\n");
}

