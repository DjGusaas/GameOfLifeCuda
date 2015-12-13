#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int *univ, int h, int w)
{
	printf("\n");

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			printf("%d", *((univ + y * w) + x));
		}

		printf("\n");
	}

	printf("\n");
}

void generate(int g, int h, int w)
{
	int univ[h][w];
	int alive;
	int size = h * w;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			univ[y][x] = rand() % 2;
		}
	}

	printf("Initial state:");
	print_matrix((int *)univ, h, w);

	int new_univ[h][w];

	while(g > 0)
	{
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < h; x++)
			{
				int x_left = ;
				int x_right = ;
				int y_up = ;
				int y_down ;

				alive = univ[y + 1][x - 1] + univ[y + 1][x] + univ[y + 1][x + 1] +
								univ[y][x - 1] + univ[y][x + 1] +
								univ[y - 1][x - 1] + univ[y + 1][x] + univ[y + 1][x + 1];

				new_univ[y][x] = 	(alive == 3 || ( alive == 2 && univ[y][x]) ? 1 : 0);
			}
		}
		
		printf("Generation %d", g);
		print_matrix((int *)new_univ, h, w);

		int i;
		for (i = 0; i < h; i++)
		{
			memcpy(&univ[i], &new_univ[i], sizeof(new_univ[i]));
		}

		print_matrix((int *)new_univ, h, w);
		g--;
	}
}

int main()
{
	int g, h, w;

	printf("Enter desired number of generations:\n");
	scanf("%d", &g);

	printf("Enter desired height of universe:\n");
	scanf("%d", &h);

	printf("Enter desired width of universe:\n");
	scanf("%d", &w);

	generate(g, h, w);
}
