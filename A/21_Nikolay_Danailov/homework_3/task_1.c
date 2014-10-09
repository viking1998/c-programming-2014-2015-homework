#include <stdio.h>

void PrintSmallLetters()
{
	int i;
	for (i = 97; i <= 122; i += 1)
	{
		printf("%c - %d\n", i, i);
	}
}

int main()
{
	PrintSmallLetters();
	return 0;
}
