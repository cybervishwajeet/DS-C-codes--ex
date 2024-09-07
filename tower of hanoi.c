#include<stdio.h> 
int toH(int n,char rodA,char rodC,char rodB)
{
	if(n==1)
	{
		printf("\nmove disk 1 from rod %c to rod %c ",rodA,rodC );
		return;
	}
	toH(n-1,rodA,rodB,rodC);
	
	printf("\nmove disk %d from rod %c to rod %c ",n,rodA,rodC);
	toH(n-1,rodB,rodC,rodA);
}
int main ()
{
int no_of_disks;

printf("\nenter the number of disks :");
scanf("%d",&no_of_disks);
toH(no_of_disks,'A','C','B');	

return 0;
}
