#include<stdio.h>
#include<conio.h>
#include<ctype.h>

char oprstack[50];     //stack1
int evalstack[50];   //stack2
int top1=-1,top2=-1;

void pushopr(char k)
{
	oprstack[++top1]=k;
}

void pusheval(int k)
{
	evalstack[++top2]=k;
}

char popopr()
{
	return(oprstack[top1--]);
	
}

int pr(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		
		case '*':
		case '/':
			return 3;
			
		case ')':
			return 0;
			
			
	}
}







int main()
{
	
	char infix[50],k;
	char ch;
	int i=0,c;
	
	printf("        PREFIX   EVALUATOR     \n\n\n\n");
	printf("Enter the expression: \n");
	scanf("%s",infix);                                      //we can convert string to integer with either "atoi(n)"  or  x-'0'.
	strrev(infix);
	
	
	while((ch=infix[i++])!='\0')
	{
		if(ch==')')
			pushopr(ch);
			
		else if(isdigit(ch))
		{
			pusheval(ch-'0');
		}
			
		else if(ch=='(')
		{
			while(oprstack[top1]!=')')
			{
				k = popopr();    
				
				if(k=='+')
				{
					c=evalstack[top2] + evalstack[top2-1];
					top2--;
					printf("%d",c);
					evalstack[top2]=c;
				}
				else if(k=='-')
				{
					c=evalstack[top2] - evalstack[top2-1];
					top2--;
					evalstack[top2]=c;
				}
				else if(k=='*')
				{
					c=evalstack[top2] * evalstack[top2-1];
					top2--;
					evalstack[top2]=c;
				}
				else if(k=='/')
				{
					c=evalstack[top2] / evalstack[top2-1];
					top2--;
					evalstack[top2]=c;
				}
				
			}
			k=popopr();
		}
		else
		{
			if(top1==-1)
			{
				pushopr(ch);
			}
	
			else
			{
				if(pr(oprstack[top1])>pr(ch))
				{
					k=popopr();
				
					if(k=='+')
					{
						c=evalstack[top2] + evalstack[top2-1];
						top2--;
						printf("\n inside block c is : %d\n",c);
						evalstack[top2]=c;
					}
					else if(k=='-')
					{
						c=evalstack[top2] - evalstack[top2-1];
						top2--;
						evalstack[top2]=c;
					}
					else if(k=='*')
					{
						c=evalstack[top2] * evalstack[top2-1];
						top2--;
						evalstack[top2]=c;
					}
					else if(k=='/')
					{
						c=evalstack[top2] / evalstack[top2-1];
						top2--;
						evalstack[top2]=c;
					}
				
			    }
			    pushopr(ch);
				
			}
		
			
		}
	}
	if(top1!=-1)
	{
		while(top1!=-1)
		{
			k=popopr();
			if(k=='+')
			{
				c=evalstack[top2] + evalstack[top2-1];
				top2--;
				printf("\n inside block c is : %d\n",c);
				evalstack[top2]=c;
			}
			else if(k=='-')
			{
				c=evalstack[top2] - evalstack[top2-1];
				top2--;
				evalstack[top2]=c;
			}
			else if(k=='*')
			{
				c=evalstack[top2] * evalstack[top2-1];
				top2--;
				evalstack[top2]=c;
			}
			else if(k=='/')
			{
				c=evalstack[top2] / evalstack[top2-1];
				top2--;
				evalstack[top2]=c;
			}
			
		}
	}
	
	printf("\nOutput is : %d",evalstack[top2]);
	
	
	return 0;
}
