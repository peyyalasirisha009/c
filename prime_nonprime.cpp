#include<stdio.h>
int main()
{
	int i,j,min,max,count=0;
	printf("enter range between prime no:");
	scanf("%d%d",&min,&max);
	for(i=min;i<=max;i++)
	{
		count=0;
		for(j=i;j<=i;j++)
		{
			if(i%j==0)
			count++;
		}
		if (count==2)
		printf("%d ",i);
	}
}