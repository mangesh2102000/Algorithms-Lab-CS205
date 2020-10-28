	#include<stdio.h>
	#include<stdlib.h>
	
	int solve(int arr[],int n,int size)
	{
		int i,ans1;
		if(n==0)
		{
			for(i=0;i<size;i++)
			{
				if(i==size-1)
				{
					printf("%d\n",arr[i]);	
				}
				else
				{
					printf("%d,",arr[i]);
				}
			}
			return 1;
		}
		
		if(n<0)
		{
			return 0;
		}
		
		arr[size]=1;
		ans1 = solve(arr,n-1,size+1);
		
		arr[size]=2;
		ans1 += solve(arr,n-2,size+1);
		
		arr[size]=3;
		ans1 += solve(arr,n-3,size+1);
		
		return ans1;
	}
	
	int main()
	{
		int n;
		scanf("%d",&n);
		
		int arr[n];
		
		int ans = solve(arr,n,0);
		
		printf("Total number of ways=%d\n",ans);
	}
