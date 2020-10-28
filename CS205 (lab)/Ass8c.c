#include<stdio.h>

int G[1005][1005];
int len[1005];
int vis[1005];

void dfs(int source,int dest)
{
	int i;
	vis[source]=1;
	if(vis[dest]==1)
		return;
	for(i=0;i<len[source];i++)
	{
		if(vis[G[source][i]]==0)
		{
			dfs(G[source][i],dest);
		}
	}
}

int min(int x,int y)
{
	if(x<y)
		return x;
	return y;
}

int result(int a,int b)
{
	memset(vis,0,sizeof(vis));
	dfs(a,b);
	if(vis[b]==1)
	return a;

	memset(vis,0,sizeof(vis));
	dfs(b,a);
	if(vis[a]==1)
	return b;

	return min(a,b);
}

int main()
{
	/* Assumed winner as per problem statement 
	i.e For a pair (A,B) - A will be the winner */

	int p,n,i,j,u,v,q,a,b;

	printf("Enter total no. of players : ");
	scanf("%d",&p);

	printf("Enter size of array of pairs : "); 
	scanf("%d",&n);

	printf("Enter all (n) pairs (format - u v) : \n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&u);
		scanf("%d",&v);
		G[u][len[u]++]=v;
	}

	printf("Enter no. of queries : ");
	scanf("%d",&q);

	printf("Query format : a b \n");

	for(i=0;i<q;i++)
	{
		printf("Query %d : ",i+1);
		scanf("%d",&a);
		scanf("%d",&b);
		printf("Winner is %d \n",result(a,b));
	}
}
