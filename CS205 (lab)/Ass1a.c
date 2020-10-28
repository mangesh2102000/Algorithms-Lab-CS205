#include<stdio.h>
#include<stdlib.h>


int valid(int idx,int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(abs(arr[i]-idx)==0 || abs(arr[i]-idx)==1)
		{
			return 0;
		}
	}

	return 1;
}


int solve(int arr[],int n,int idx,int size)
{
	int curr_arr[n],i;

	if(idx==n+1 && size!=0)
	{
		for(int i=0;i<size;i++)
		{
			printf("EV%d ",arr[i]);
		}
		printf("\n");
		return 1;
	}

	if(idx==n+1 && size==0)
		return 0;

	if(valid(idx,arr,size))
	{		
		for(i=0;i<size;i++)
		{
			curr_arr[i] = arr[i];
		}
		curr_arr[i] = idx;
		return solve(curr_arr,n,idx+1,size+1)+solve(arr,n,idx+1,size);
	}
	else
	{
		return solve(arr,n,idx+1,size);
	}

}

int main()
{	
	int n;
	printf("Enter a number\n");
	scanf("%d",&n);

	int arr[n];

	int ans = solve(arr,n,1,0);

	printf("Number of ways a compatible project group can be chosen is: ");
	printf("%d ",ans);	

	return 0;
}
