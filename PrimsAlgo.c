#include<stdio.h>
int i,G[20][20],n;
int min=32767;
void Prim(int G[20][20],int n);
void main()
{
	int i,j;
	printf("\nEnter the no.of vertices in the graph:");
	scanf("%d",&n);
	printf("\nEnter the vertices cost one by one:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("G[%d][%d]:",i+1,j+1);
			scanf("%d",&G[i][j]);
		}
	}
	Prim(G,n);
}

void Prim(int G[20][20],int n)
{
	int i,t[n],TotalCost=0,v1,v2,j,k;
	for(i=0;i<n;i++)
	t[i]=0;
	t[0]=1;
	for(k=1;k<n;k++)
	{
	min=32767;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(G[i][j]>0 && t[i]!=t[j])
				{
					if(G[i][j]<min)
					{
						min=G[i][j];
						v1=i;
						v2=j;
					}
				}
			}
		}
		printf("%d, %d, %d",v1,v2,min);
		t[v1]=1;
		t[v2]=1;
		TotalCost=TotalCost+min;
	}
	printf("\nTotal Cost = %d",TotalCost);
}
