#include <stdio.h>
#include <stdlib.h>
#include <math.h>

__global__ void cell()
{
	int id = blockIdx.x * blockDim.x + threadIdx.x;
	
	// TODO
}

void generate(int g)
{
	int univ[][];
	
	for () {
		
	}

	while(g > 0)
	{

		g--;
	}
}

int main()
{
	int g;

	printf("Enter desired number of generations:\n");
	scanf("%d", &g);
	generate(g);
}
