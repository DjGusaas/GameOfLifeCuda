#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

void print_matrix(void *m, int h, int w)
{
	printf("\n");

	int (*mat)[w] = m;
	
	for (int y = 0; y < h; y++) 	
	{
		for (int x = 0; x < w; x++)
		{
			printf("%d", mat[y][x]);
		}

		printf("\n");
	}
}

int main()
{
	int h, w;

	printf("Enter desired height of 2d array:\n");   
	scanf("%d", &h);

	printf("Enter desired width of 2d array:\n");
	scanf("%d", &w);

	int mat[h][w];

	for (int y = 0; y < h; y++)
 	{
		for (int x = 0; x < w; x++)
	 	{
			mat[y][x] = 0;
		}
	}

	printf("Value at (0, 1) = %d\n", mat[0][1]);
	print_matrix(mat, h, w);

	return 0;
}
