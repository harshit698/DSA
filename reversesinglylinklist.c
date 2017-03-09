// REVERSING A SINGLY LINKED LIST...

#include<stdio.h>
#include<stdlib.h>

int n;
struct node{
	int data;
	struct node *next;
};

//First I have to create a list in order to reverse it.
struct node *start = NULL ;
struct node *new1,*temp , *temp1;
int i;

void create(int n)
{
	
	for(i=0;i<n;i++)
	{
	
		new1 = (struct node *)malloc(sizeof(struct node));
		
		printf("\nInsert the data: ");
		scanf("%d",&new1->data);
		new1->next = NULL;
		
		if(start==NULL)
		{
			start = new1;
			
			temp1 = start;
		}
		else
		{
			//temp = new1;
			//new1.next = NULL;
			temp1->next = new1;
			temp1 = new1;
		}
	}
	//Let's see our created linked list.
	temp = start;
	printf("\nList is:\n");
	while(temp!=NULL)
	{
		printf("[%d]-->",temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

int main()
{
	int n,num;
	struct node *prev ,*head , *next;
	char k;
	head = start;
	do
	{
		printf("\nFirst create a linked list\n");
		printf("\nEnter the number of items you want to enter: ");	
		scanf("%d",&num);
		
		create(num);
		//Now that list is created , we need to reverse it.
		head = start;
		prev = NULL;
		
		while(head!=NULL)
		{
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		
		//Now , we reversed the linked list, we need to print it.
		temp = temp1;
		printf("\n\n\nList after reversing:\n");
		while(temp!=NULL)
		{
			printf("[%d]-->",temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
		
		printf("\nDo you want to continue?(Y/N) ");
		k = getch();
		
		
	}
	while(k=='Y' || k=='y');
	return 0;

	
}

