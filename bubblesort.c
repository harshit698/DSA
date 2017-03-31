#include<stdio.h>
#include<conio.h>

int arr[50];

void buublesort(int* , int  );

int main()
{
	int ch, i , j , n;
	char k;
	printf("  BUBBLE SORT IMPLEMENTATION!!\n\n\n\n");
	
	do
	{
		printf("\nEnter the numbers of elements you want to enter : ");
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			printf("\nEnter element %d : ",i+1);
			scanf("%d",&arr[i]);
		}
		
		//Now we have array , we have to sort it now.
		
		bubblesort(arr , n);
		
		//Now the array is sorted, we have to show the output.
		printf("\nElements in sorted order are : \n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\n Do you want to continue?(Y/N) ");
		k=getch();
		
	}
	while((k=='y' || k=='Y'));
	
	
}

void bubblesort(int *arr , int n)
{
	//we have unsorted array with us and we are going to use buuble sort algorithm.
	int j,i,temp;
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}
