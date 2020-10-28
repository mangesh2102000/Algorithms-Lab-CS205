#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i=0,x;
	printf("Enter the total number of integers to be read : ");
	scanf("%d",&n);
	int a[n];
	while(n--)
	{
		printf("Give next element as input : ");
		scanf("%d",&x);
		if(i==0)
		{
			printf("Median after first element : ");
			printf("%d\n",x);
			a[i] = x;
		}
		else
		{
			int pos=0; 

			int lo=0,hi=i+1,mid=lo+(hi-lo)/2,j;

			while(lo<=hi)
			{
				mid=lo+(hi-lo)/2;

				if(x>a[mid])
				{
					lo = mid+1;
				}
				else
				{
					pos=mid;
					hi = mid-1;
				}
			}

			if(a[pos]<x)
				pos++;

			for(j=i+1;j>pos;j--)
			{
				a[j]=a[j-1];
			}
			a[pos]=x;

			if((i+1)%2==0)
			{
				printf("Median after first %d elements : ",i+1);
				printf("%.2f\n",(a[(i+1)/2] + a[(i+1)/2 - 1])/2.0);
			}
			else
			{
				printf("Median after first %d elements : ",i+1);
				printf("%d\n",a[(i+1)/2]);
			}

		}
		i++;
	}
	return 0;
}