#include<stdio.h>
#include<stdlib.h>

void flip_array(int a[],int start,int end)
{
	int i,j;
	int b[end-start+1];
	for(i=0;i<(end-start+1);i++)
	{
		b[i]=a[start+i];
	}
	for(i=start,j=0;i<=end;i++)
	{
		a[i] = b[end-start+j];
		j--;
	}
}

int solve(int a[],int n)
{
	if(n==1)
		return 0;

	int pos=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]>a[pos])
			pos=i;
	}

	if(pos==n-1)
	{
		return solve(a,n-1);
	}
	else
	{
		if(pos!=0)
		{				
			flip_array(a,0,pos);
			flip_array(a,0,n-1);
			return 2+solve(a,n-1);
		}
		else
		{
			flip_array(a,0,n-1);
			return 1+solve(a,n-1);
		}
	}

}

int main()
{
	int i,n;	
	printf("Enter the size of array : ");
	scanf("%d",&n);

	int a[n];
	printf("Enter array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	int min_no_of_flips = solve(a,n);

	printf("Min. no. of Flips req. : %d\n",min_no_of_flips);

	printf("Sorted array is : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}