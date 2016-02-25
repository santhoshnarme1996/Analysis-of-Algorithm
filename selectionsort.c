#include<stdio.h>
void selectionsort(int ar[],int n);
void main()
{
	int ar[20],i,size;
	printf("\nEnter the size of the array:");
	scanf("%d",&size);
	printf("\nEnter the array elements one by one:");
	for(i=0;i<size;i++)
	{
		printf("\nA[%d] :",i);
		scanf("%d",&ar[i]);
	}
	selectionsort(ar,size);
	printf("\nThe Sorted array is:\n");
			for(i=0;i<size;i++)
			{
				printf("%d\n",ar[i]);
			}
}

void selectionsort(int ar[],int n)
{
	int index,i,j,temp;
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(ar[index]>ar[j])
			{
				temp=ar[index];
				ar[index]=ar[j];
				ar[j]=temp;
		    }
	    }
	}
}
