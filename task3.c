#include<stdio.h>
#include<ctype.h>
#include<string.h>


void main()
{
	char code[100];          //code array will hold the code snippet;
	int i=0,flag=2,top=-1;
	char stack[50];            //stack array if for storing brackets(symbols);
	
	
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
		else   //this condition is for all characters except brackets.
		i++;
	}
	if(top!=-1)  //finally, stack holding symbols must be empty for balancing all symbols;
		flag=3;
		
	if(flag==2)
		printf("Everything is correct.");
	else if(flag==3)
		printf("Unbalalnced expression.\n");
}
