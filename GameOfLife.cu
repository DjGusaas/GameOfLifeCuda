#include <stdio.h>
#include <stdlib.h>
#include <math.h>

__global__ void cell()
{
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	
	// TODO
}

void generate(int g, int h, int w)
{
	int univ[h][w];
	
	for (int y = 0; y < 3; y++) 
	{
		for (int x = 0; x < 3; x++) 
		{
			univ[y][x] = ;
		}
	}

	while(g > 0)
	{
		// TODO
		g--;
	}
}

int main()
{
	int g, h, w;

	// Should be using fgets instead of scanf 
	printf("Enter desired number of generations:\n");
	scanf("%d", &g);

	printf("Enter desired height of universe:\n");
	scanf("%d", &h);

	printf("Enter desired width of universe:\n");
	scanf("%d", &w);

	generate(g, h, w);
}
