#include <stdio.h>

int main()
{
	long double firstNumber = 2;
	long double secondNumber = 1;
	long double thirdNumber;
	
	int i;
	for (i = 2; i <= 100; i += 1)
	{
		thirdNumber = secondNumber + firstNumber;
		firstNumber = secondNumber;
		secondNumber = thirdNumber;
		printf("%Lf, ", thirdNumber);
	}
	
	return 0;
}
