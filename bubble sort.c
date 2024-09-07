#include<stdio.h>
int main()
{
	int a[20],i,j,temp,n;
	
	printf("\n enter the size of array :");
	scanf("%d",&n);
	
	printf("\n enter array element :");
	for(i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	printf("\n array element after sorting :");
	for(i=0;i<n;i++)
	{
		printf("%d",&a[i]);
	}
	return 0;
}
