#include<stdio.h>
void main()
{
	int Physics,Chemistry,Maths,Total;
	float avg;
	printf("enter the Physics marks");
	scanf("%d",&Physics);
	printf("enter the Chemistry marks");
	scanf("%d",&Chemistry);
	printf("enter the Maths marks");
	scanf("%d",&Maths);
	Total=Physics+Chemistry+Maths;
	avg=(Total)/3;
	if(avg>50)
	printf("the grade is pass");
	else 
	printf("the grade if fail");
	
}