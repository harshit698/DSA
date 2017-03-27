//Stack using   linked list or dynamic implementation of stack...


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};

struct node *start= NULL;
struct node *new1, *temp;

//In stack we have to push from beginning as backtracing is not possible
// SO problem while deletion as well as displaying data.

void push()
{
	//insert from beginning..
	new1 = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&new1->data);
	new1->next=NULL;
	if(start==NULL)
	{
		start=new1;
		return;
	}
	temp=start;
	new1->next=temp;
	start=new1;	
}

void pop()
{
	//remove from beginning..
	if(start==NULL)
	{
		printf("\nToo less element to delete\n");
		return;
	}
	temp=start;
	printf("\nDeleted element is %d\n",temp->data);
	start = temp->next;
	free(temp);
	
}

void display()
{
	if(start==NULL)
	{
		printf("\nStack is empty\n");
		return;
	}	
	temp=start;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

int main()
{
	printf("\\\\\\\\\\\\\Dynamic Implementation of queue\\\\\\\\\\\\\\\\\\\n\n\n\n");
	int ch;
	char res;
	do
	{
		printf("\n\n1.Push\n");
		printf("2.pop\n");
		printf("3.Display\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
		}
		printf("\nDo you want to continue?(Y or N)");
		res = getch();
		
		
	}
	while(res=='y' || res=='Y');
	return 0;

}


