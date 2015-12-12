#include <stdio.h>
#include <stdlib.h>

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
}

void generate(int g, int h, int w)
{
	int univ[h][w];

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			univ[y][x] = rand() % 2;
		}
	}

	while(g > 0)
	{
		// TODO

		print_matrix((int *)univ, h, w);
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
