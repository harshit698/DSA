#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
	char code[100];
	int i=0,flag=2,top=-1;
	char stack[50];
	printf("Enter the code snippet:\n");
	scanf("%[^?]s",code);
	while(code[i]!='\0')
	{
		if(code[i]=='('||code[i]=='['||code[i]=='{')
		{
			stack[++top]=code[i];
			i++;
		}
		else if(code[i]==')'||code[i]==']'||code[i]=='}')
		{
			if(code[i]==')')
			{
				if(stack[top]=='(')
				{
					top--;
				    flag=2;
				    i++;
				}
				else
				{
					flag=3;
					i++;
					break;
				}
			}
			else if(code[i]=='}')
			{
				if(stack[top]=='{')
				{
					top--;
				    flag=2;
				    i++;
				}
				else
				{
					flag=3;
					i++;
					break;
				}
			}
			else if(code[i]==']')
			{
				if(stack[top]=='[')
				{
					top--;
				    flag=2;
				    i++;
				}
				else
				{
					flag=3;
					i++;
					break;
				}
			}
		}
		else
		i++;
	}
	if(flag==2)
	printf("Everything is correct.");
	else if(flag==3)
	printf("Unbalalnced expression.\n");
}
