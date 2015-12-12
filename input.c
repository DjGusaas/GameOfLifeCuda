#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_matrix(int *mat, int h, int w)
{
	printf("\n");
	
	for (int y = 0; y < h; y++) 	
	{
		for (int x = 0; x < w; x++)
		{
			printf("%d", *((mat + y * w) + x));
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
			mat[y][x] = rand() % 2;
		}
	}

	printf("Value at (0, 1) = %d\n", mat[0][1]);
	print_matrix((int *)mat, h, w);

	return 0;
}
