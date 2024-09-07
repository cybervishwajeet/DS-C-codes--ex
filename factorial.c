#include<stdio.h>
unsigned long long int
factorial (unsigned int i)
{
	if(i<=1)
	{
		return 1;
	}
	return i*factorial(i-1);
}
int main()
{
	int i;
	printf("\n enter the number to find a factorial :");
	scanf("%d",&i);
	printf("\n factorial of %d is a %d",i,factorial(i));
	
	return 0;
}
