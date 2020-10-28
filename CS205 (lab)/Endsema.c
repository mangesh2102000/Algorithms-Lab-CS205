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

int root[1005];
int printsets[1005][1005];
int len[1005];

void makeset()
{
	int i;
	for(i=1;i<=v;i++)
	{
		root[i] = i;
	}
}

int findset(int i)
{
	while(i!=root[i])
	{
		root[i] = root[root[i]];
		i = root[i];
	}
	return i;
}

void union_set(int a,int b)
{
	int x=findset(a),y=findset(b);
	root[x]=root[y];
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
	}	
	
	makeset();
	
	for(i=1;i<=e;i++)
	{
		int u,v;
		u = edge[i].idx1;
		v = edge[i].idx2;
		
		if(findset(u)!=findset(v))
		{
			union_set(u,v);
		}
	}
	
	
	for(i=1;i<=v;i++)
	{
		int p = findset(i);
		printsets[p][len[p]] = i;
		len[p]++;
	}
	
	printf("Output : \n");
	
	for(i=1;i<=v;i++)
	{
		if(len[i]!=0)
		{
			cnt++;
			printf("Table no. %d : ",cnt);
			for(j=0;j<len[i];j++)
			{
				printf("%s ",data[printsets[i][j]].name);
			}
			printf("\n");
		}
	}	
	
	printf("Total number of tables : %d\n",cnt);
	
	return 0;	 
}
