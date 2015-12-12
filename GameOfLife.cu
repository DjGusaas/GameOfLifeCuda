#include <stdio.h>
#include <stdlib.h>

__global__ void cell()
{
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	
	// TODO
}

void print_matrix(int *univ, int h, int w)
{
	// http://www.geeksforgeeks.org/pass-2d-array-parameter-c/
	// Credit to the above for demonstrating how to pass around 2d arrays
	
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
	
	for (int y = 0; y < 3; y++) 
	{
		for (int x = 0; x < 3; x++) 
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
