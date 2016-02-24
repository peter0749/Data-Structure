#include <stdio.h>
#include <stdlib.h>

int fib(int m)
{
	if(m==0)	return 0;
	else if(m==1)	return 1;
	return fib(m-1) + fib (m-2);
}

int main(void)
{
	int num, i;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("fib(%d) = %d\n",i,fib(i));
	}

	return 0;
}
