#include<stdio.h>

int G[1005][1005];
int len[1005];
int vis[1005];
int end_node = 0;

void dfs(int node)
{
	int i;
	vis[node]=1;
	for(i=0;i<len[node];i++)
	{
		if(vis[G[node][i]]==0)
		{
			dfs(G[node][i]);			
		}
	}
}

int main()
{
	/* Node Indexing starts from 0 */ 
	int i,n,m,u,v,check=1;

	printf("Enter no. of nodes : ");
	scanf("%d",&n);

	printf("Enter no. of edges : ");
	scanf("%d",&m);
	
	printf("Enter Edges in format : u v \n");
	
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		G[u][len[u]++] = v;		
	}

	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i);
			end_node=i;
		}
	}

	for(i=0;i<n;i++)
	{
		vis[i]=0;
	}

	dfs(end_node);

	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			check=0;
			break;
		}
	}

	if(check==1)
	{
		printf("\nCore Vertex is %d\n",end_node);
	}
	else
	{
		printf("None of the vertices is core vertex\n");
	}

	return 0;
}
