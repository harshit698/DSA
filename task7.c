#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 20

int queue[MAX],front=-1,rear=-1;

int isfull()
{
	if(front!=-1 && rear==front)
		return 1;
	else
		return 0;	
}

int isempty()
{
	if(rear==-1)
		return 1;
	else
		return 0;
}

void enqueue()
{
	if(isfull())
	{
		printf("\nQueue is full\n");
		return;
	}
	int data;
	printf("\nEnter the data: ");
	scanf("%d",&data);
	
	if(rear==-1)
	{
		front=0;
		rear=0;
	}
	queue[rear]=data;
	rear=(rear+1)%MAX;
}

void dequeue()
{
	if(isempty())
		printf("\nQueue is empty\n");
	else
	{
		printf("\n Deleted element is %d",queue[front]);
		front=(front+1)%MAX;
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
	}
}

void display()
{
	int i;
	if(isempty())
		printf("\nQueue is empty\n");
	else if(front<rear)
	{
		for(i=front;i<rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
	else
	{
		for(i=0;i<rear;i++)
			printf("%d\n",queue[i]);
		for(i=front;i<MAX;i++)
			printf("%d",queue[i]);
	}
}

int main()
{
	char res;
	int ch=1;
	do
	{
		printf("\n1.Insert data\n");
		printf("2.Burn data\n");
		printf("3.Display\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				enqueue();
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
	while(ch!=5);
}




