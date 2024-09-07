#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
	
}node;
node* create(int n);
void print(node *Head);
void count(node *Head);
void search(node *Head);
int main()
{
    node *Head;
	Head=NULL;
	int N,ch;	
	printf("\n how much node linked list do you want to create :");
	scanf("%d",&N);
	Head=create(N);
	print(Head);
	printf("1.print a linked list!!");
	printf("2.count a element in linked list!!");
	printf("3.search a element in linked list!!");
	printf("4.thank you for using a software!!");
	do{
	printf("\n enter your choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:void print(node *Head);
		       break;
		case 2:void count(node *Head);
		       break;
		case 3:void search(node *Head);
		       break;
		case 4:printf("\nexit");
		       break;
		default:printf("\n invalid choice");
	}while(ch!=4)
    return 0;
}
node* create(int n)
{
	node *Head,*p;
	int x,i;
	
	printf("\n enter the data :");
	scanf("%d",&x);
	Head=(node*)malloc(sizeof(node));
	Head->data=x;
	Head->next=NULL;
	
    p=Head;
	for(i=2;i<=n;i++)
	{
		printf("\n enter the data :");
		scanf("%d",&x);
		p->next=(node*)malloc(sizeof(node));
		p=p->next;
		p->data=x;
		p->next=NULL;
	}
	printf("\n create a linked list successfully!!!");
	return (Head);
}
void print(node *Head)
{
    node *p;
    if(Head==NULL)
    {
    	printf("\nlinked list is empty!!!");
	}
	else
	{
		p=Head;
		printf("\nsingly linked list nodes :");
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->next;
		}
	}
}
void count(node *Head)
{ 
  node *p;
  int count=0;
  if(Head==NULL)
  {
  	printf("\sinngly linked list is empty!!!");
  }
  else
  {
  	p=Head;
  	printf("\nsingly linked list nodes :");
  	while(p!=NULL)
  	{
  		count++;
  		p=p->next;
	  }
	  printf("\n no. of nodes in singly linked list :%d",count);
  }
}
void search(node *Head)
{
	node *p;
	int key,flag=0;
	
	printf("\n enter the element to be search :");
	scanf("%d",&key);
	if(Head==NULL)
	{
		printf("\n singly linked list is empty !!!");
	}
	else
	{
		p=Head;
		
		orintf("\nsingly linked list nodes :");
		while(p!=NULL)
		{
			if(key==p->data)
			{
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag==1)
		{
			printf("\n element is found!!");
		}
		else
		{
			printf("\n element is not found !!");
		}
	}
}
