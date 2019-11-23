#include <stdio.h>
#include <stdlib.h> 

typedef struct point_2d {
	int x;
	int y;
	// I have to ignore this 
	// Color col;
}point_2d;

void main() 
{
	point_2d* data[5];

	for(int i = 0; i < 5; i++) 
	{
		point_2d *tmp = (point_2d *)malloc(sizeof(point_2d)); 
		tmp->x = i;
		tmp->y = i * i;
		data[i] = tmp;
	}

	for(int i = 0; i < 5; i++)
	{
		printf("Point #%d: %d, %d\n", i, data[i]->x, data[i]->y);
	}
}