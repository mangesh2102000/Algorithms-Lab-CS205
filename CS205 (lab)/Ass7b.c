#include<stdio.h>

int G[1005][1005];
int GT[1005][1005];

int stack[1005],f,m;
int vis[1005];

void push(int x)
{
	if(f==1005)
	{
		printf("Stack Overflow\n");
	}
	stack[f]=x;
	f++;
}

void dfs(int node,int n)
{
	int i;
	vis[node]=1;

	for(i=1;i<=n;i++)
	{
		if(G[node][i]==1 && vis[i]==0)
		{
			dfs(i,n);
		}
	}
	push(node);
}

void dfst(int node,int n)
{
	printf("%d ",node);
	int i;
	vis[node]=1;

	for(i=1;i<=n;i++)
	{
		if(GT[node][i]==1 && vis[i]==0)
		{
			dfst(i,n);
		}
	}
}


int main()
{
	int n,e,u,v,i,j;
	printf("Enter no. of nodes : ");
	scanf("%d",&n);
	printf("Enter no. of edges : ");
	scanf("%d",&e);

	for(i=0;i<e;i++)
	{
		printf("Enter edge %d : ",i+1);
		scanf("%d %d",&u,&v);
		G[u][v]=1;
		GT[v][u]=1;
	}

	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			dfs(i,n);
		}
	}

	for(i=1;i<=n;i++)
	{
		vis[i]=0;
	}

	printf("\nStrongly Connected Components are as follows : \n");
	for(i=f-1;i>=0;i--)
	{
		if(vis[stack[i]]==0)
		{
			printf("SCC %d : ",m+1);
			dfst(stack[i],n);
			printf("\n");
			m++;
		}
	}

	printf("Total Number of Strongly Connected Components : %d \n",m);

	return 0;
}
