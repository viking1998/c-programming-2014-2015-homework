#include <stdio.h>

int main ()
{
	long long unsigned int a=2;
	long long unsigned int b=1;
	long long unsigned int c;
	int i;
	for (i=1; i<=93; i++)
	{
		c=a+b;
		printf("%llu, ",a);
		a=b;
		b=c;		
	}
	// chislata sa mnogo golemi i poradi tazi prichina gi izpisvam taka.
	printf("44140595050111976643, ");
	printf("71420983074726546239, ");
	printf("115561578124838522882, ");
	printf("186982561199565069121, ");
	printf("302544139324403592003, ");
	printf("489526700523968661124, ");
	printf("792070839848372253127, ");
	return 0;
}
