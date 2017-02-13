#include<stdio.h>
#include<string.h>
#define MAX 50

int ftop=-1,btop=-1;

char fstack[MAX][20];
char bstack[MAX][20];


void forward()
{
	if(isemptyb())
	{
		printf("Enter URL:  ");
		scanf("%s",&fstack[++ftop]);
	}
	else
	{
		fstack[++ftop][20]=bstack[btop--][20];
		printf("Curernt url is : %s",fstack[ftop]);
	}
	
}

void back()
{
	bstack[++btop][20]=fstack[ftop--][20];
	printf("Current URL is: %s",fstack[ftop]);
	
}

void fdisplay()
{
	if(isemptyf())
		printf("\nOOps!! No URL ahead!!\n\n");
	else
	{
		int i;
		for(i=0;i<=ftop;i++)
		printf("%s",fstack[ftop]);
	}

}

void bdisplay()
{
	if(isemptyb())
		printf("\nOOps!! No URL Back!!\n\n");
	else
	{
		int i;
		for(i=0;i<=btop;i++)
		printf("%s",bstack[btop]);
	}

}

int isemptyf()
{
	if(ftop==-1)
	return 1;
	else
	return 0;
}

int isemptyb()
{
	if(btop==-1)
	return 1;
	else
	return 0;
}

void main()
{
	int j=0,ch=1;
	while(ch!=12)
	{
		if(j==0)
		{
			printf("\nEnter URL:  ");
			scanf("%s",fstack[++ftop]);
			j=1;
			printf("\n\nYou can't move Back. Move forward.\n\n");
		}
		else
		{
			printf("\n\n1.Forward\n");
			printf("2.Back\n");
			printf("3.Display Forward Urls\n");
			printf("4.Display Backward Urls\n");
			printf("5.Close\n");
			printf("\nEnter your choice:  ",&ch);
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					forward();
					break;
				case 2:
					back();
					break;
				case 3:
					fdisplay();
					break;
				case 4:
					bdisplay();
					break;
				case 5:
					exit(1);
				
			}
		}
		
	}

}
