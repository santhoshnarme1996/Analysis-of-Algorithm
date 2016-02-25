#include<stdio.h>
#include<math.h>
long int mult(long int x, long int y, int n);
long int lpart(long int, int);
long int rpart(long int, int);
void main()
{
	long int s1,s2,a,b,c,d,prod;
	int m,n,c1=0,c2=0;
	printf("\nEnter the first number:");
	scanf("%ld",&a);
	printf("\nEnter the second number:");
	scanf("%ld",&b);
	c=a;
	d=b;
	while(c!=0)
	{
		c=c/10;
		c1++;
	}
	while(d!=0)
	{
		d=d/10;
		c2++;
	}
	
	if(c1==c2)
	n=c1;
	else if(c1>c2)
	n=c1;
	else
	n=c2;
	if (n%2!=0)
	{
		n = n +1;
	}
	
	printf("\nn: %d\n",n);
	prod=mult(a,b,n);
	printf("\nThe product is: %ld\n",prod);
}
	 	

long int mult(long int X, long int Y, int n)
{
	long int A,B,C,D,m1,m2,m3;
	int m,a;
	if(n<=2)
	return(X*Y);
	else 
	{
		if (n%2==0)
			m=n/2;
		else
			m=(n+1)/2;
	
		a=pow(10,m);
		
		A=X/a;
		B=X%a;
		C=Y/a;
		D=Y%a;
		printf("A = %ld\tB= %ld\tC= %ld\tD= %ld\t",A,B,C,D);
		m1=mult(A,C,m);
		m2=mult(B,D,m);
		m3=mult((A-B),(D-C),m);
		return((m1*(pow(10,n)))+m2+((m3+m2+m1)*(pow(10,m))));
	}
}
	
		
	
