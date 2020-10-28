#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[100];
	int idx;
} node;

typedef struct{
	char name1[100];
	char name2[100];
	int idx1;
	int idx2;
} conn;

int v,e;
node data[1005];
conn edge[1005];

int level[1005];
int G[1005][1005];
int len[1005];
int vis[1005];

int queue[1005];
int f=-1,r=-1;

void push(int a)
{
	if(f==-1)
		f=0;
			
	r++;
	queue[r]=a;
}

int pop()
{
	int a=queue[f];
	f++;
	return a;
}

int is_empty()
{
	if(f>r || f==-1)
		return 1;
		
	return 0; 
}

void bfs(int s)
{
	int i,j;	
	push(s);
	level[s]=0;	
	while(!is_empty())
	{
		int x = pop();
		
		if(vis[x]==1)
		continue;
		
		for(i=0;i<len[x];i++)
		{
			if(vis[G[x][i]]==0)
			{
				if(level[x]==0)
				level[G[x][i]]=1;
				else
				level[G[x][i]]=0;				
				push(G[x][i]);
			}
		}		
		vis[x]=1;	
	}
}

int main()
{
	int i,j,cnt=0;
	printf("Enter the number of guests : ");
	scanf("%d",&v);
	
	printf("Enter details about nodes : ( format - mangesh ) \n");
	for(i=1;i<=v;i++)
	{
		scanf("%s",data[i].name);
		data[i].idx = i;
	}
	
	printf("Enter the number of edges : ");
	scanf("%d",&e);
	
	printf("Enter details about edges : ( format - mangesh abhijeet ) \n");
	for(i=1;i<=e;i++)
	{
		scanf("%s",edge[i].name1);
		scanf("%s",edge[i].name2);	
		
		for(j=1;j<=v;j++)
		{
			if(strcmp(edge[i].name1,data[j].name)==0)
			{
				edge[i].idx1 = j;
			}
			
			if(strcmp(edge[i].name2,data[j].name)==0)
			{
				edge[i].idx2 = j;
			}
		}
		
		G[edge[i].idx1][len[edge[i].idx1]]=edge[i].idx2;
		len[edge[i].idx1]++;
		G[edge[i].idx2][len[edge[i].idx2]]=edge[i].idx1;
		len[edge[i].idx2]++;
	}	
	
	for(i=1;i<=v;i++)
	{
		if(vis[i]==0)
		{
			bfs(i);
		}
	}
	
	printf("Output : \n");
	
	for(i=1;i<=e;i++)
	{
		
		int u=edge[i].idx1,v=edge[i].idx2;		
		
		if(level[u]==level[v])
		{
			printf("False\n");
			return 0;
		}
	}
	
	printf("True\n");
	printf("Table no. 1 : ");
	for(i=1;i<=v;i++)
	{
		if(level[i])
			printf("%s ",data[i].name);
	}
	printf("\n");
	
	printf("Table no. 2 : ");
	for(i=1;i<=v;i++)
	{
		if(!level[i])
			printf("%s ",data[i].name);
	}
	printf("\n");	
	
	return 0;	 
}
