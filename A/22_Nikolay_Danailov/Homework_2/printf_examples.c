#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int randomInt = rand();
	printf("Random integer number: %d\n", randomInt);
	return 0;
}
