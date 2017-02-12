// Static implementation of queue using array.

#include<stdio.h>
#define MAX 100


int queue[MAX];
int rear=-1 , front =0;

int isempty()
{
	if(rear<front)
		return 1;
	else
		return 0;
}

int isfull()
{
	if(front==MAX-1)
		return 1;
	else
		return 0;
}

void display()
{
	int i;
	if(isempty())
		printf("\nOOPS!! queue is empty\n.");
	else
	{
		printf("\nElement in stacks are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}	
	}
	
}

void Enqueue(int x)
{
	if(isfull())
		printf("OOPS!!! Queue is full.\n\n");
	else
	{
		queue[++rear]=x;
	}
}

void dequeue()
{
	if(isempty())
		printf("OOPs!! queue is empty\n\n");
	else
	{
		printf("Deleted element is:  %d\n\n",queue[front]);
		front++;
	}

}

int main()
{
	int x,j=0,ch=1,num;
	
	printf(" STATIC IMPLEMENTATION OF QUEUE USING ARRAY	\n\n");
	while(ch!=12)
	{
		if(j==0)                   //Because, first operation can only be insertion.
		{
			printf("Enter first element in queue: \n");
			scanf("%d",&num);
			Enqueue(num);	
			j=1;
			printf("\n\nNow choose:\n");
		}
		else
		{
			printf("\n\n1.Insert Element\n");
			printf("2.Delete Element\n");
			printf("3.See Elements\n");
			printf("4.EXIT\n\n");
			printf("Enter your choice:\n");
			scanf("%d",&ch);
			printf("\n");
			
			switch(ch)
			{
				case 1:
					printf("\nEnter the element you wnat to enter:\n");
					scanf("%d",&num);
					Enqueue(num);
					break;
				case 2:
					dequeue();
					break;
				case 3:
					
					display();
					break;
				case 4:
					exit(0);
				
					
			}
		}
	}
}
