#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g[1005][1005];
int m,n,curr;

typedef struct{
	char na[100];
	int q;
	int l;
	int r;
} item;

typedef struct{
	char na[100];
	int q;
	char it[100][100];
} customer;

item dish[1005];
customer person[1005];
int linked[1005];

int match_possible(int i,int linked[],int vis[])
{
	int j;
	for(j=0;j<curr;j++)
	{
		if(g[i][j] && vis[j]==0)
		{
			vis[j]=1;
			if(linked[j]<0 || match_possible(linked[j],linked,vis))
			{
				linked[j] = i;
				return 1;
			}
		}
	}	
	return 0;
}

int maxapp()
{
	int i,j;
	for(i=0;i<curr;i++)
	{
		linked[i] = -1;
	}

	int ans=0;
	for(i=0;i<n;i++)
	{
		int vis[curr];
		for(j=0;j<curr;j++)
		{
			vis[j] = 0;
		}

		if(match_possible(i,linked,vis))
			ans++;
	}
	
	
	return ans;
}

int find_dish(int x)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(x >= dish[i].l && x <= dish[i].r )
			return i;
	}
}

int main()
{
	int i,j,k,x;
	
	printf("Note : While providing any strings such as name of person, name of item if there is a space in the name of single entity please replace it with  _ \n");

	printf("Number of items prepared by Angeethi : ");
	scanf("%d",&m);
	
	printf("Enter details of items (Example Format : Paneer_Pasinda 5) : \n");
	for(i=0;i<m;i++)
	{
		scanf("%s",dish[i].na);
		scanf("%d",&dish[i].q);
		dish[i].l = curr;
		dish[i].r = curr+dish[i].q-1;
		curr+=dish[i].q;
	}

	printf("Number of customers : ");
	scanf("%d",&n);
	printf("Enter details of choices (Example Format : Sourav 2 Paneer_Pasinda Paneer_tikka) : \n");
	for(i=0;i<n;i++)
	{
		scanf("%s",person[i].na);
		scanf("%d",&person[i].q);
		for(j=0;j<person[i].q;j++)
		{
			scanf("%s",person[i].it[j]);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<person[i].q;j++)
		{
			for(k=0;k<m;k++)
			{				
				if(strcmp(dish[k].na,person[i].it[j])==0)
				{					
					for(x=dish[k].l;x<=dish[k].r;x++)
					{
						g[i][x] = 1;
					}
				}
			}
		}
	}

	int p = maxapp();
	
	printf("Number of customer satisfied (P) : %d \n",p);
	printf("Customers which are satisfied along with delivered item : \n");
	for(i=0;i<curr;i++)
	{
		if(linked[i]!=-1)
		{
			int tmp1 = find_dish(i);
			printf("%s, %s \n",person[linked[i]].na,dish[tmp1].na);
		}
	}

	return 0;	
}
