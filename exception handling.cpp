#include<iostream>
using namespace std;

float div(int x, int y)
{
	if(y==0)
	{
		throw"attempt to devide by 0";
	}
	return(x/y);
}
int main()
{
	int i,j;
	float k;
	
	i=25;
	j=0;
	k=0;
	
	try
	{
		k=div(i,j);
		cout<<k<<endl;
		
	}
	catch( const char *ptr)
	{
		cout<<ptr<<endl;
		
	}
}
