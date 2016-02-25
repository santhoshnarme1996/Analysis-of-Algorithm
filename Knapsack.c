#include<stdio.h>
void Knapsack(int n,float u,float wt[],float pr[],float rat[],float srat[]);
float pr[30],wt[30];
float rat[30],srat[30];
float u;

void main()
{
	int m,n,i,j,index;
	float r,s,temp;
	printf("\nEnter the limit of the sack:");
	scanf("%f",&u);
	printf("\nEnter the no. of objects:");
	scanf("%d",&n);
	printf("\nEnter the weight and the profit of the objects one by one:");
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter the weight:");
		scanf("%f",&wt[i]);
		printf("\nEnter the profit:");
		scanf("%f",&pr[i]);
		rat[i]=pr[i]/wt[i];
		srat[i]=pr[i]/wt[i];
	}
	
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(srat[index]<srat[j])
			{
				temp=srat[index];
				srat[index]=srat[j];
				srat[j]=temp;
		    }
	    }
	}
	
	Knapsack(n,u,wt,pr,rat,srat);
}

void Knapsack(int n,float u,float wt[],float pr[],float rat[],float srat[])
{
	int i,j,k;
	float x[30],TotalProfit=0.0,q;
	for(i=0;i<30;i++)
	x[i]=0.0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			{
				if(rat[j]==srat[i])
				k=j;
			}
			
		if(wt[k]>u)
		{
		
			x[i]=u/wt[k];
			TotalProfit = TotalProfit + (x[i] * pr[k]);
			printf("\n\nRatio : %.2f",srat[i]);
			printf("\nProfit : %.2f",pr[k]);
			printf("\nWeight : %.2f",wt[k]);
			printf("\nRatio of weight chosen : %.2f",x[i]);
			printf("\n");
			break;
		}
		
		else
		{
			x[i]=1.0;
			u=u-wt[k];
			printf("\n\nRatio : %.2f",srat[i]);
			printf("\nProfit : %.2f",pr[k]);
			printf("\nWeight : %.2f",wt[k]);
			printf("\nRatio of weight chosen : %.2f",x[i]);
			printf("\n");
			TotalProfit = TotalProfit + (x[i] * pr[k]);
		}
	}
	printf("\nThe total profit is : %.2f\n",TotalProfit);
}
			
		

