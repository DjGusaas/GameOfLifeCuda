#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_univ(int arr[], int size)
{
	printf("\n");

	for (int i = 0; i < size; i++) {
		if (i % 3 == 0 && i == size) {
			printf("\n");
			printf("%d", arr[i]);
		} else {
			printf("%d", arr[i]);
		}
	}

	printf("\n");
}

void generate(int g, int h, int w)
{
	int size = h * w;

	int univ[size];
	int new_univ[size];

	for (int i = 0; i < size; i++) {
		univ[i] = rand() % 2;
	}	

	printf("Initial universe:");
	print_univ(univ, size);

	while (g > 0){
		for (int i = 0; i < size; i++){
			int alive = 0;

			unsigned x = i % w;
			unsigned y = i - x;
			unsigned xl = (x + w - 1) % w;
			unsigned xr = (x + 1) % w;
			unsigned yu = (y + size - w) % size;
			unsigned yd = (y + size) % size;

			//alive = ;	

			new_univ[i] = (alive == 3 || (alive == 2 && univ[i]) ? 1 : 0);
		}			

		memcpy(univ, new_univ, size);
		print_univ(univ, size);
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
