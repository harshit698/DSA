#include<stdio.h>
int a,b,temp,temp1,i;
int gcd(a,b){
	if (a>b)
	temp=a;
	else
	temp=b;
	for(i=1;i<=temp;i++)
	{
		if(a%i==0 && b%i==0)
		temp1=i;
	}
	return temp1;
	
}
int main()
{
	int x,y,r;
	printf("Enter first number");
	scanf("%d",&x);
	printf("Enter second number");
	scanf("%d",&y);
	r= gcd(x,y);
	printf("%d",r);
}
