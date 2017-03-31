// insertion sort implementation
// each time a data from unsorted array will be put in it's correct position in sorted array.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int i,j,n,arr[20],ele,temp;
	char res;
	printf("\nIMPLEMENTATION   OF   SELECTION  SORT\n\n");
	do
	{
		printf("\nEnter number of data: ");
		scanf("%d",&n);
		if(n<2)
		{
			printf("\nYou can't sort a array if it has less than 1 element..\n");
		}
		else
		{
			printf("\nEnter the elements: \n");
			for(i=0;i<n;i++)
			{
				scanf("%d",&arr[i]);
			}
		
			//sorting
			for(i=1;i<n;i++)
			{
				ele = arr[i];
				for(j=0;j<i;j++)
				{
					if(ele<arr[j])
					{
						temp = arr[j];
						arr[j] = ele;
						ele = temp;
					}
				}
				arr[i]=ele;
			}
			// sorted now print
			for(i=0;i<n;i++)
			{
				printf("%d\t",arr[i]);
			}

		}
		printf("\n\nDo you want to sort more dataset?(Y or N)");
		res = getch();
		
	}
	while(res=='y' || res=='Y');
	return 0;
}
