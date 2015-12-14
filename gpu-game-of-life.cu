#include <stdio.h>
#include <stdlib.h>

__global__ void cell_kernel(int univ[], int h, int w)
{
	int id = __mul24(blockIdx.x, blockDim.x) + threadIdx.x;
	int num_cells = h * w;

	for (id; id < num_cells; id += blockDim.x * gridDim.x) 
	{
		unsigned x_pos = id % w;
		unsigned y_pos = id - x_pos;
		unsigned x_left = (x_pos + w - 1) % w;
		unsigned x_right = (x_pos + 1) % w;
		unsigned y_above = (y_pos + num_cells - w) % num_cells;
		unsigned y_below = (y_pos + num_cells) % num_cells;

		int alive = univ[x_left + y_above] + univ[x_pos + y_above] + univ[x_right + y_above] + univ[x_left + y_pos] + univ[x_right + y_pos] + univ[x_left + y_below] + univ[x_pos + y_below] + univ[x_right + y_below];

		new_univ[x_pos + y_pos] = alive == 3 || (alive == 2 && univ[x_pos + y_pos]) ? 1 : 0;
	}
}

void print_array(int univ[], int size)
{	
  printf("\n");

  for (int i = 0; i < size; i++)
  {
    printf("%d", univ[i]);
  }

  printf("\n");
}

void generate(int g, int h, int w)
{
	int size = h * w;
	int univ[size];
	
	for (int i = 0; i < size; i++) 
	{
		univ[i] = rand() % 2;
	}

	while(g > 0)
	{
		size_t t = (size) / 256;
		unsigned blocks_count = (unsigned)std::min((size_t)32768, t);

		d_ ;
		d_ ;

		cell_kernel<<<blocks_count, 256>>>( , unsigned(w), unsigned(h), );

		print_array(univ, size);
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
