#include<stdio.h>
#include<conio.h>

int queue[22];
int support[20];
int front=-1,rear=-1,suprear=-1,supfront=-1;

void enqueue(int age)
{
	if(rear==-1)
	{
		front=0;
		rear=0;
	}	
	queue[rear++]=age;
	
}

void enqsupp(int age)
{
	if(suprear==-1)
	{
		suprear=0;
		supfront=0;
	}
	support[suprear++]=age;
}


int main()
{
	int age,i,n,adult=0,young=0,temp,youngs=0,adults=0;
	char res,res2;
	
	do
	{
	
		printf("\nEnter the number of persons: ");
		scanf("%d",&n);
		
		if((rear+n)>20)
		{
			printf("\nQueue limit has bee exceeded\n");
			temp = rear+n-20;
			printf("\n2 members are extra. So, these many members want to wait?(Y) or you all want to wait?(N)\n");
			scanf("%c",&res);
			//res = getch();
			if(res=='y' || res=='Y')
			{
				// Also , left i.e (n-temp) users are need to be inserted in the main queue..
				for(i=0;i<n-temp;i++)
				{
					printf("\nEnter the age: ");
					scanf("%d",&age);
					if(age>0 && age<18)
						young++;
					else if(age>18 && age<70)
						adult++;
					else
						printf("\nThis age is not allowed..");
					enqueue(age);
				}
				//left extra members are inserted inside supporting queue...
				for(i=0;i<temp;i++)
				{
					printf("\nEnter the age: ");
					scanf("%d",&age);
					if(age>0 && age<18)
						youngs++;
					else if(age>18 && age<70)
						adults++;
					else
						printf("\nThis age is not allowed..");
					enqsupp(age);
				}
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				printf("\nEnter the age: ");
				scanf("%d",&age);
				if(age>0 && age<18)
					young++;
				else if(age>18 && age<70)
					adult++;
				else
					printf("\nThis age is not allowed..");
				enqueue(age);
			}
		
		}
		if(rear==20)
		{
			printf("\nNumber of young entered is %d and number of adults entered is %d\n",young,adult);
			rear=-1;
			front=-1;
			young=0;
			adult=0;
		}
		printf("Do you want to continue?(Y or N)\n");
		res2= getch();
	}
	while(res2=='y' || res2=='Y');
	return 0;
	
}
