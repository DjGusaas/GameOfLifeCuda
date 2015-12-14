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
			for (int x = 0; x < w; x++)
			{
				int l_l = univ[y + 1][x - 1];
				int l_m = univ[y + 1][x];
				int l_r = univ[y + 1][x + 1];
				int l = univ[y][x - 1];
				int r = univ[y][x + 1];
				int u_l = univ[y - 1][x - 1];
				int u_m = univ[y - 1][x];
				int u_r = univ[y - 1][x + 1];

				if(l_l != 0 && l_l != 1){
					l_l = 0;
				}
				if(l_m != 0 && l_m != 1){
					l_m = 0;
				}
				if(l_r != 0 && l_r != 1){
					l_r = 0;
				}
				if(l != 0 && l != 1){
					l = 0;
				}
				if(r != 0 && r != 1){
					r = 0;
				}
				if(u_l != 0 && u_l != 1){
					u_l = 0;
				}
				if(u_m != 0 && u_m != 1){
					u_m = 0;
				}
				if(u_r != 0 && u_r != 1){
					u_r = 0;
				}
				printf("Indivicuial postitions(%d, %d, %d, %d, %d, %d, %d, %d)\n", l_l, l_m, l_r, l, r, u_l, u_m, u_r);
				alive = l_l + l_m + l_r + l + r + u_l + u_m + u_r;

				printf("Alive pos(%d, %d): %d\n", y, x, alive);

				new_univ[y][x] = (alive == 3 || ( alive == 2 && univ[y][x]) ? 1 : 0);
			}
		}
		
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				univ[y][x] = new_univ[y][x];
			}
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
