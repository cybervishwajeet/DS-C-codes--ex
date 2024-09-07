#include<stdio.h>  
int main() 
{ 
int a[10],i,j,n,temp; 
 
printf("\nEnter size of array:"); 
scanf("%d",&n); 
printf("\nEnter array elements are:"); 
for(i=0;i<n;i++) 
  { 
  scanf("%d",&a[i]); 
  } 
       for(i=1;i<n;i++) 
       { 
         temp=a[i]; 
         for(j=i-1;j>=0 && a[j]>temp;j--) 
            { 
             a[j+1]=a[j]; 
            } 
      a[j+1]=temp; 
        }  
    printf("\n Sorted Array Elements are:"); 
     for(i=0;i<n;i++) 
       { 
         printf("%d\t",a[i]); 
        } 
  return 0;
  
}
