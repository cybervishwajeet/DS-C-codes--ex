#include<stdio.h>
int main()
{
	int n;
	char a,b,c;
	
	printf("\n enter the number of discs :");
	scanf("%d",&n);
	
	printf("\n tower of hanoi of %d disc\n",n);
	tower(n,'a','b','c');
}
void tower(int n,char beg, char aux, char end)
{
	if(n<0)
	{
		printf("\n invalid ");
	}
	else if (n==1)
	{
		printf("\n tower of hanoi %c to %c",beg,end);
	}
	else
	{
		tower(n-1,beg,end,aux);
		tower(1,beg,aux,end);
		tower(n-1,aux,beg,end);
	}
}
