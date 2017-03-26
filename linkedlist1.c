// Linked list.

#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *new1;
int noe=0;

void insertatbeg()
{
	if(start==NULL)
	{
		start = new1;
		start->next=NULL;
	}
	else
	{
		new1->next = start;
		start=new1;
	}
};

void insertatend()
{
	struct node *temp;
	if(start==NULL)
	{
		new1->next=NULL;
		start=new1;
	}
	else
	{
		new1->next=NULL;
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = new1;
			
	}
};

void insertatmid()
{
	struct node *temp,*prev;
	int pos,i;
	if(start==NULL)
	{
		printf("\nThere are no elements present in list to insert in middle..\n");
		return;
	}
	printf("\nEnter the position in which you want to enter: ");
	scanf("%d",&pos);
	if(pos==1 || pos==0 || pos>=noe)
	{
		printf("\nPlease Enter a valid position\n");
		return;
	}
	temp=start;
	for(i=0;i<pos-1;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	new1->next=temp;
	prev->next=new1;
	
};

void deletefrombeg()
{
	struct node *temp;
	if(start==NULL)
		printf("\nList is Empty!!\n");
	else
	{
		temp=start;
		start= temp->next;
		printf("\nDeleted element is : %d\n",temp->data);
		free(temp);
	}
};

void deletefromend()
{
	struct node *temp=start;
	if(start==NULL)
		printf("\nToo less element to Delete!");
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		printf("Delted Element is : %d\n",temp->next->data);
		temp->next=NULL;
	}
	 
};

void deletefrommid()
{
	struct node *temp, *prev;
	int i, pos;
	if(start==NULL)
	{
		printf("\nToo less data to delete\n");
		return;
	}
	printf("\nEnter the node position to delete: ");
	scanf("%d",&pos);
	if(pos==1 || pos==0 || pos>noe)
	{
		printf("\nPlease Enter Valid POsition\n");
		return ;
	}
	temp = start;
	for(i=0;i<pos-1;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next = temp->next;
	printf("\n Deleted element is %d\n",temp->data);
	free(temp);
};

void display()
{
	struct node *temp1;
	if(start==NULL)
		printf("\nList is Empty\n");
	else
	{
		for(temp1=start;temp1!=NULL;temp1=temp1->next)
			printf("%d-->",temp1->data);
		printf("NULL\n");
	}
}; 

int main()
{
	int ch1 , ch2 , ch3;
	char ch4;
	printf("//////////////////////LINKED LIST IMPLEMENTATION///////////////////////\n\n\n");
	
	do{
		printf("\n1.Insert Data\n");
		printf("2.Delete Data\n");
		printf("3.Display\n");
		printf("Enter your choice:- ");
		scanf("%d",&ch1);
		
		switch(ch1)
		{
			case 1:
				{
					noe++;
					printf("\nEnter the data: ");
					new1 = (struct node *) malloc(sizeof(struct node));
					scanf("%d",&new1->data);
					printf("\n1.Insert at Beginning\n");
					printf("2.Insert at End\n");
					printf("3.Insert at Middle\n");
					printf("\nEnter your choice:- ");
					scanf("%d",&ch2);
					
					switch(ch2)
					{
						case 1:
							insertatbeg();
							break;
						case 2:
							insertatend();
							break;
						case 3:
							insertatmid();
							break;
						default:
							exit(0);
					}
					break;
				}
			case 2:
				{
					printf("\n1.Delete from Front\n");
					printf("2.Delete from End\n");
					printf("3.Delete from Middle\n");
					printf("Enter your choice:- ");
					scanf("%d",&ch3);
					
					switch(ch3)
					{
						case 1:
							deletefrombeg();
							break;
						case 2:
							deletefromend();
							break;
						case 3:
							deletefrommid();
							break;
						default:
							exit(0);
					}
					break;
				}
			case 3:
				{
					display();
					break;
				}
			default:
				exit(0);
		
		}
		printf("\nWant to continue?Y or N \n");
		ch4 = getch();
		
	}
	while(ch4=='y' || ch4=='Y');
	return 0;
	
}
