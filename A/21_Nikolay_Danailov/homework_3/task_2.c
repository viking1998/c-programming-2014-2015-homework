#include <stdio.h>

int main()
{
	double firstNumber = 2;
	double secondNumber = 1;
	double thirdNumber;
	
	int i;
	for (i = 2; i <= 100; i += 1)
	{
		thirdNumber = secondNumber + firstNumber;
		firstNumber = secondNumber;
		secondNumber = thirdNumber;
		printf("%.0lf, ", thirdNumber);
	}
	
	return 0;
}
