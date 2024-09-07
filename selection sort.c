#include <stdio.h>
int main()
{
	 int a[20],i,j,k,temp,n;
	 
	 printf("Enter size of array :");
	 scanf("%d",&n);
	 
	 printf("\nEnter array element :");
	 for(i=0;i<n;i++)
	 {
	 	  scanf("%d",&a[i]);
	 }
	 for(i=1;i<n;i++)
	 {
	 	k=i;
	 	for(j=i+1;j<n;j++)
	 	{
	 	    if(a[j]<a[k])
			 {
			   k=j; 	
			 }	
		}
	        if(k!=i)
	      {
	        	temp=a[i];
	 	        a[i]=a[k];
	 	        a[k]=temp;
	      }
    }
 
 printf("\n\n\nsorting array element is :");
 for(j=0;j<n;j++)
 {
 	printf(" %d",a[j]);
 }
	
}
