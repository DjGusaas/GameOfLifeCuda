#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int arr[], int size)
{
	printf("\n");

	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}

	printf("\n");
}

void generate(int g, int h, int w)
{
	int size = h * w;

	int univ[size];
	int new_univ[size];

	for (int i = 0; i < size; i++)
	{
		univ[i] = rand() % 2;
	}

	printf("Initial universe:");
	print_array(univ, size);

	while(g > 0)
	{
		for (int i = 0; i < size; i++)
		{
			int alive = 0

			unsigned x_pos = i % w;
			unsigned y_pos = i - x_pos;
			unsigned x_left = (x_pos + w - 1) % w;
			unsigned x_right = (x_pos + 1) % w;
			unsigned y_above = (y_pos + size - w) % size;
			unsigned y_below = (y_pos + size) % size;

			alive = ;	

			new_univ[i] = (alive == 3 || (alive == 2 && univ[i]) ? 1 : 0);
		}			

		memcpy(univ, new_univ, size);
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

	return 0;
}
