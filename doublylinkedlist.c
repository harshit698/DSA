#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev,*next;
} *temp,*temp1,*new1;

struct node *start=NULL;
int count=0,pos,i;


void create()
{
	new1= (struct node *) malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&new1->data);
	new1->next=NULL;
	new1->prev=NULL;
	count++;
}

void insertatbeg()
{
	create();
	if(start==NULL)
	{
		start=new1;
	}
	else
	{
		temp=start;
		new1->next=temp;
		temp->prev=new1;
		start=new1;
	}
}

void insertatend()
{
	create();
	if(start==NULL)
	{
		start=new1;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
			temp=temp->next;
			
		//temp is last
		new1->prev=temp;
		temp->next=new1;
	}
	
}

void insertatmiddle()
{
	if(start==NULL)
	{
		printf("\nNo Element is present to insert in middle..\n");
		return ;
	}
	printf("\nEnter the position in which you want to enter: ");
	scanf("%d",&pos);
	if(pos==0 || pos==1 || pos>count)
	{
		printf("\nPlease! Enter a valid position..");
		return;
	}
	temp=start;
	create();
	for(i=0;i<pos-1;i++)
		temp=temp->next;
	new1->next=temp;
	new1->prev = temp->prev;
	temp->prev->next = new1;
	temp->prev = new1;
}


void deleteatbeg()
{
	if(start==NULL)
	{
		printf("\nToo less element to delete");
		return;
	}
	temp=start;
	start=temp->next;
	//start->prev=NULL;
	//printf("%s",start);==null
	printf("\n Deleted element is %d\n",temp->data);
	count--;
}

void deleteatend()
{
	if(count==0)
	{
		printf("\nToo less element to delete");
		return ;
	}
	temp=start;
	if(temp->next==NULL)
	{
		printf("\nDeleted element is %d\n",temp->data);
		start=NULL;
		count--;
		return;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	//temp is last now;
	temp->prev->next = NULL;
	printf("\n Deleted element is %d\n",temp->data);
	count--;
}

void deleteatmiddle()
{
	if(start==NULL)
	{
		printf("\nNo Element to delete");
		return ;
	}
	printf("\nEnter the position of node you want to delete: ");
	scanf("%d",&pos);
	if(pos<2 || pos>count)
	{
		printf("\nEnter a valid position..");
		return ;
	}
	temp=start;
	for(i=0;i<pos-1;i++)
		temp=temp->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	printf("\nDeleted element is %d...",temp->data);
	count--;
	free(temp);
}

void display()
{
	if(count==0)
	{
		printf("\nNo data to display..\n");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("[%d]<-->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	

}

int main()
{
	int ch=1;
	while(ch!=8)
	{
		printf("\n1.Insert at beg.\n");
		printf("2.Insert at end.\n");
		printf("3.Insert at middle.\n");
		printf("4.Delete from beg.\n");
		printf("5.Delte from end.\n");
		printf("6.Delete from middle\n");
		printf("7.Display\n\n");
		
		printf("Enter your choice: ");
		
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertatbeg();
				break;
			case 2:
				insertatend();
				break;
			case 3:
				insertatmiddle();
				break;
			case 4:
				deleteatbeg();
				break;
			case 5:
				deleteatend();
				break;
			case 6:
				deleteatmiddle();
				break;
			case 7:
				display();
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
	

 



