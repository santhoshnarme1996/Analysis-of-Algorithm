#include<stdio.h>
void Mergesort(int,int);
void Merge(int,int,int);
void Quicksort(int,int);
int partition(int,int);
void swap(int,int);
int ar[50];
void main()
	{
		int i,beg,end,size,ch,ans;
		printf("\nEnter the size of the array to be sorted(Not more than 50):");
		scanf("%d",&size);
		printf("\nEnter the array elements one by one:\n");
		for(i=0;i<size;i++)
		{
			printf("A[%d] :",i);
			scanf("%d",&ar[i]);
		}
		do
		{
		printf("\nEnter the way you want to sort the array:\n1.Merge Sort\n2.Quick Sort\n\nEnter your option:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			Mergesort(0,size-1);
			printf("\nThe Sorted array is:\n");
			for(i=0;i<size;i++)
			{
				printf("%d\n",ar[i]);
			}
			break;

			case 2:
			Quicksort(0,size-1);
			printf("\nThe Sorted array is:\n");
			for(i=0;i<size;i++)
			{
				printf("%d\n",ar[i]);
			}
			break;

			default:
			printf("\nWrong choice is entered");
		}
			printf("\nDo you want to perform the process once more??(1/0)");
			scanf("%d",&ans);
	    }while(ans==1);
	}

void Mergesort(int l,int r)
{
	int mid;
	if(l<r)
	{
		mid=(l+r)/2;
		Mergesort(l,mid);
		Mergesort(mid+1,r);
		Merge(l,mid,r);
	}
}

void Merge(int l,int mid,int r)
{
	int i,j,k=l,n1,n2,L[20],R[20];
	n1=mid-l+1;
	n2=r-mid;
	for(i=0;i<n1;i++)
	{
		L[i]=ar[l+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=ar[mid+1+j];
	}
	i=0;
	j=0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			ar[k]=L[i];
			i++;
		}
		else
		{
			ar[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		ar[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		ar[k]=R[j];
		j++;
		k++;
	}

}

void Quicksort(int l,int r)
{
int pivot;
	if(l<r)
	{
		pivot=partition(l,r);
		Quicksort(l,pivot-1);
		Quicksort(pivot+1,r);
	}
}

int partition(int l, int r)
{
	int leftwall,pivot;
	pivot = ar[l];
    leftwall = l;
		for(int i=l+1;i<r;i++)
		{
			if (ar[i] < pivot)
			{
				leftwall = leftwall+1;
				swap(ar[i],ar[leftwall]);
			}
		}
				swap(ar[l],ar[leftwall]);
return leftwall;
}	

void swap(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
