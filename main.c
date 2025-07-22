#include <stdio.h>

int running = 1;
int playing = 0;

static void make_space()
{
	for(int i = 0; i <= 100; i++)
	{
		printf("\n");
		printf("\n");
	}
}

static void make_bspace()
{
	for(int i = 0; i <= 20; i++)
	{
		printf("\n");
	}
}


static char inp_anlz(char inp)
{
	switch(inp)
	{
		case 'q':
			printf("				exiting...\n");
			make_bspace();
			running = 0;
			break;

		case 'p':
			playing = 1;
			while(playing==1)
			{
				char inp;
				printf("				[s]pin, [q]uit\n");
				printf("				when you are out of balance you are out literaly.\n");
				scanf("%c", &inp);
				
				switch(inp)
				{
					case 'q':
						printf("				exiting to menu...\n");
						playing = 0;
						break;
				}

				make_space();
				make_bspace();
			}
			break;

	}
}

int main()
{
	while(running == 1)
	{
		char inp;
		printf("				what do you want to do?\n");
		printf("				[q]uit, [p]lay\n");
		scanf("%c", &inp);
		make_space();
		make_bspace();
		inp_anlz(inp);
		


	}
	return 0;
}
