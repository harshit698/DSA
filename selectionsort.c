// selection sorting in c;
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int arr[10],n,i,j,min,t;
	char res;
	printf("\nSELECTION  SORT IMPLEMENTATION...\n\n\n\n\n");
	do
	{
		printf("\nEnter the number of data : ");
		scanf("%d",&n);
		if(n<=1)
		{
			printf("\nYou don't have to sort an array if it has less than 1 data...\n");

		}
		else
		{
			printf("\nEnter the numbers...\n");
			for(i=0;i<n;i++)
			{
				scanf("%d",&arr[i]);
			}
			// sorting .
		
			for(i=0;i<n;i++)
			{
				min = arr[i];
				for(j=i;j<n;j++)
				{
					if(min>arr[j])
					{
						t=arr[j];
						arr[j]=min;
						min = t;
						//arr[i] = arr[j]
					}
				
				}
				arr[i]=min;
			}
			//array is sorted ,now we have to print..
		
			printf("\nElements in array(after sorting) are: \n");
			for(i=0;i<n;i++)
				printf("%d\t",arr[i]);

		}
					
		printf("\n\nDo you want to sort another dataset?(Y or N)");
		res = getch();
	}
	while(res=='y' || res=='Y');
	return 0;

}
