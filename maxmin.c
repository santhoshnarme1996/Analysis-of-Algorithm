#include<stdio.h>
void maxmin(int p,int q);//function for maximum and minimum
int a[10],min,max;

void main()
{
	int i,size,p,q;
	printf("\nEnter the size of the array:");
	scanf("%d",&size);
	printf("\nEnter the array elements one by one:");
	for(i=0;i<size;i++)//Input of the array elements
	{
		printf("\nA[%d] :",i);
		scanf("%d",&a[i]);
	}
	p=0;
	q=size-1;

	maxmin(p,q);
	printf("\nThe hghest element is %d and the least element is %d",max,min);//Displaying the result
}

void maxmin(int p,int q)
{
	int mid,min_old,max_old,i,j;
    if(i==j)    
		{
  			min=max=a[i];
 		}

	else if (i==j-1)   
 		{
   			if(a[i]<a[j])
	  		{
	   			min=a[i];
	   			max=a[j];
	  		}
			else             
			{ 
   				min=a[j];
   				max=a[i];
  			}
		}

 	else
 	{
   		mid=(i+j)/2;
		maxmin(i,mid);
   		min_old=min;
   		max_old=max;
 		maxmin(mid+1,j);

   		if(min_old<min)
     		min=min_old;

   		if(max_old>max)
     		max=max_old;
 	}
} 
