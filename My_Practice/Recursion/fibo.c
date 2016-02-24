#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int i;
	long long int fn,f1 = 1,f2 = 0;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("f(%d) = ",i);
		if(i==0)	printf("0");
		else if(i==1)	printf("1");
		else
		{
			fn = f1 + f2;
			f2 = f1;
			f1 = fn;
			printf("%lld",fn);
		}
		printf("\n");
	}

	return 0;
}
