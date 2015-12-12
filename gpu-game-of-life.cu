#include <stdio.h>
#include <stdlib.h>

__global__ void cell(int *univ, int h, int w)
{
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	int num_cells = h * w;
	// declare univ

	for (id; id < num_cells; id += blockDim.x * gridDim.x) 
	{
		int x_pos = id % w;
		int y_pos = id - x_pos;
		int x_left = (x + w - 1) % w;
		int x_right = (x + 1) % w;
		int y_above = (y_pos + num_cells - w) % num_cells;
		int y_below = (y_pos + num_cells) % num_cells;

		int alive = univ[y_above][x_left] + univ[y_above][x_pos] + univ[y_above][x_right] +
								univ[y_pos][x_left] + univ[y_pos][x_right] +
								univ[y_below][x_left] + univ[y_below][x_pos] + univ[y_below][x_right];

		new_univ[y_pos][x_pos] = alive == 3 || (alive == 2 && univ[y_pos][x_pos]) ? 1 : 0;
	}
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
