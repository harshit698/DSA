#include<stdio.h>
#define MAX 20


int ftop=-1, btop=MAX/2-1;
int stack[MAX][20];

int isemptyb()
{
	if(btop==MAX/2-1)
		return 1;
	else
		return 0;
}

void bdisp()
{
	int i;
	for(i=0;i<=btop;i++)
		printf("%s\n",stack[btop]);
}

void forward()
{
	if(btop==MAX/2-1)
	{
		printf("Enter URL:\n");
		scanf("%s",stack[++ftop]);
	}
	else
	{
		stack[++ftop][20]=stack[btop--][20];
		printf("Current URL is : %s\n\n",stack[ftop]);
	}
	
}

void backward()
{
	stack[++btop][20]=stack[ftop--][20];
	printf("Current URL is : %s\n\n",stack[ftop]);
	
}


void main()
{
	
	int ch,j=0;
	
	while(1)
		{
			
			if(j==0)
			{
				printf("Enter URL:\n");
				scanf("%s",stack[++ftop]);
				j=1;
				printf("\nYou can't Go back Move forward\n\n");
			}
			else
			{
				printf("1. Forward\n");
				printf("2. Backward\n");
				printf("3. Display Back URLs\n");
				printf("4. Close\n");
				printf("\nEnter your choice:\n");
				scanf("%d",&ch);
		
				switch(ch)
				{
					case 3:
						bdisp();
						break;
					case 4:
						exit(0);
					case 1:
						forward();
						break;
					case 2:
						backward();
						break;
				}
			}
		}
		
}
