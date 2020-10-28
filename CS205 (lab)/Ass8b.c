#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,m,r,u,v;
int G[2005][2005];
int vis[2005];
int len[2005];
double val[2005];

void dfs(int node)
{
	vis[node]=1;
	int i;
	for(i=0;i<len[node];i++)
	{
		val[G[node][i]] += (double)val[node]/len[node];	
		
		if(vis[G[node][i]]==0)
		{
			dfs(G[node][i]);
		}
	}
}

int main()
{
	int i,j;
	printf("Enter no. of islands : ");
	scanf("%d",&n);
	printf("Enter no. of one-way bridges : ");
	scanf("%d",&m);
	printf("Enter the index of island you are initially on : ");
	scanf("%d",&r);

	printf("Enter Edges in format : u v \n");
	
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		G[u][len[u]++] = v;
	}

	val[r]=(double)1.0;
	dfs(r);

	double max_stuck=0;

	for(i=1;i<=n;i++)
	{
		if(val[i]>max_stuck && len[i]==0 && vis[i])
		{
			max_stuck = val[i];
		}
	}
	
	printf("\nIndex(s) of island(s) that you are most likely to get stuck on : ");

	for(i=1;i<=n;i++)
	{
		if(fabs(val[i]-max_stuck)<=0.000000001 && len[i]==0 && vis[i])
		{
			printf("%d ",i);
		}
	}
	printf("\n");

	return 0;
}
