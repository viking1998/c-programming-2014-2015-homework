#include <stdio.h>
#include <time.h>
const int RandMax = 2000000000;

double randfrom(double min, double max) 
{
	srand(time(NULL));
    	double range = (max - min); 
    	double divider = RandMax / range;
    	return min + (rand() / divider);
}

int main()
{
	printf("Random integer number: %lf\n", randfrom(1l, RandMax));
	return 0;
}

