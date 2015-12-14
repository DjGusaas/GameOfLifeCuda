#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_array(int univ[], int size)
{	
  printf("\n");

  for (int i = 0; i < size; i++)
  {
    printf("%d", univ[i]);
  }

  printf("\n");
}

int main()
{
	int w, h, size;

	printf("Enter desired height of 2d array:\n");   
	scanf("%d", &w);

	printf("Enter desired width of 2d array:\n");
	scanf("%d", &h);

	size = w * h;
	int mat[size];

	for (int i = 0; i < size; i++)
 	{
		mat[i] = rand() % 2;
	}

	printf("Value at (0, 1) = %d\n", mat[1]);
	print_array(mat, size);

	return 0;
}
