#include <stdio.h>

int main()
{
int a1,a2,b;
a1=2;
printf("%i, " ,a1);
a2=1;
printf("%i, " ,a2);
b=0;
while(b<98){
a1=a2+a1;
a2=a1+a2;
printf("%i, " ,a1);
printf("%i, " ,a2);
b++;
}

return 0;
}
