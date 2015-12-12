#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_matrix(int *mat, int h, int w)
{
	printf("\n");
	
	for (int x = 0; x < w; x++) 	
	{
		for (int y = 0; y < h; y++)
		{
			printf("%d", *((mat + x * h) + y));
		}

		printf("\n");
	}
}

int main()
{
	int w, h;

	printf("Enter desired width of 2d array:\n");   
	scanf("%d", &w);

	printf("Enter desired height of 2d array:\n");
	scanf("%d", &h);

	int mat[w][h];

	for (int x = 0; x < w; x++)
 	{
		for (int y = 0; y < h; y++)
	 	{
			mat[x][y] = rand() % 2;
		}
	}

	printf("Value at (0, 1) = %d\n", mat[0][1]);
	print_matrix((int *)mat, h, w);

	return 0;
}
