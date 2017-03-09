 //SORTING A LINKED LIST..

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;

int main()
{
	int i,num;
	struct node *temp, *new1 , *temp1,*j;
	char k;
	printf("\nFirst create a list..\n");
	printf("\nEnter the number of elements you want to enter: ");
	scanf("%d",&num);
		
	for(i=0;i<num;i++)
	{
		new1 = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter element %d: ",i+1);
		scanf("%d",&new1->data);
		new1->next=NULL;
			
		if(start == NULL)
		{
			start = new1;
			temp1 = start;	
		}
		else
		{
			temp1->next = new1;
			temp1= new1;
		}
	}
		
	temp =start;
	while(temp!=NULL)
	{
		printf("[%d]-->",temp->data);
		temp = temp->next;
		
	}
	printf("NULL\n");
	printf("\n\n");
	

	
	
	//Now we have created list , we need to reverse it.
	
	for(i=1;i<num;i++)
	{
		for(j=start;j->next!=NULL;j=j->next)
		{
			if(j->data > j->next->data)
			{
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
	//Now, list is sorted. we will print it.
	printf("\nAfter sorting..\n\n");
	temp =start;
	while(temp!=NULL)
	{
		printf("[%d]-->",temp->data);
		temp = temp->next;
		
	}
	printf("NULL\n");
	printf("\n\n");
	
	
	
		
	return 0;
}

	
	


