#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 8

int queue[MAX],front=-1,rear=-1,flag=1;

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
	if(flag==1)
	{
		printf("\nWriting process starts...\n");
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
	else
	{
		printf("\nBurning process is going on.. First stop burning\n");
		return;
	}
}

void dequeue()
{
	if(flag==2)
	{
		printf("\nBurning process starts..\n");
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
	else
	{
		printf("\nWriting process is going on.. First stop writing to burn\n\n");
		return;
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
		printf("4.Stop Writing\n");
		printf("5.Stop Burning\n");
		printf("6.Show last data\n");
		printf("7.Show first data which is going to burn\n");
		printf("8.Show Position of last data\n");
		printf("9.Show Position of first data which is going to burn\n");
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
			{
				flag=2;
				printf("\nWriting process stopped..\n");
				break;
			}
			case 5:
			{
				flag=1;
				printf("\nBurning process stopped..\n");
				break;
			}
			case 6:
			{
				if(isempty())
				{
					printf("\nToo less Data..\n");
					break;
				}
				printf("\nIt is : %d\n",queue[rear-1]);
				break;	
			}
			case 7:
			{
				if(isempty())
				{
					printf("\nToo less Data..\n");
					break;
				}
				printf("\nIt is : %d\n",queue[front]);
				break;
			}
			case 8:
				printf("%d\n",rear-1);
				break;
			case 9:
				printf("%d\n",front);
				break;
		}
		if(rear==MAX-1)
		{
			printf("\nDisc is full, you can't enter more data");
			printf("\nDisc burning starts\n\n Disc BURNED.");
			rear=-1;
			front=-1;
		}

	}
	while(ch!=10);
}




