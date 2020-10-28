#include<stdio.h>

typedef struct{
	int idx;
	int roll_no;
	int d[10];
} student;

student B[1005];
int A[1005][1005];

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void count(int a[],int b)
{ 
	int tmp=b;
	while(tmp!=0)
	{
		a[tmp%10]++;
		tmp/=10;	
	}
}

int check(int i,int j)
{
	int k,sim=0;

	for(k=0;k<10;k++)
	{
		sim += min(B[i].d[k],B[j].d[k]);
	}

	if(sim>=3)
		return 1;
	else
		return 0;
}

int s,e,arr[1005];

void push(int x)
{
	if(e==1004)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		if(e==-1)
			s=e=0;
		else
			e++;
		arr[e]=x;
	}
}

int pop()
{
	if(s==-1 || s>e)
	{
		printf("Queue Underflow\n");
	}
	int x = arr[s];
	s++;
	return x;
}

int is_empty()
{
	if(s==-1 || s>e)
	{
		s=e=-1;
		return 1;
	}
	return 0;
}


void bfs(int s,int dist[],int n)
{
	int vis[1005],i;

	for(i=0;i<1005;i++)
	{
		vis[i]=0;
		dist[i]=1000000;
	}

	push(s);
	dist[s]=0;
	vis[s]=1;

	while(!is_empty())
	{
		int u = pop();
		for(i=1;i<=n;i++)
		{
			if(A[u][i]==1)
			{
				if(vis[i]==0)
				{
					dist[i] = 1 + dist[u];
					vis[i]=1;
					push(i);
				}
			}			
		}
	}
}

int main()
{
	int i,j,n,m,q;

	printf("Enter number of students : ");
	scanf("%d",&n);

	printf("Enter roll number of n students : \n");
	for(i=1;i<=n;i++)
	{
		B[i].idx = i;
		scanf("%d",&B[i].roll_no);
		count(B[i].d,B[i].roll_no);  
	}


	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(check(i,j))
					A[i][j]=1;
			}
		}
	}

	printf("Enter number of queries : ");
	scanf("%d",&m);

	while(m--)
	{
		int qt;
		printf("Enter query type : ");
		scanf("%d",&qt);
		if(qt==1)
		{
			int roll_nu,t,idx;
			printf("Enter roll number : ");
			scanf("%d",&roll_nu);
			printf("Enter at most hops(t) : ");
			scanf("%d",&t);

			for(i=1;i<=n;i++)
			{
				if(B[i].roll_no == roll_nu)
				{
					idx = i;
				}
			}

			int dist[1005];

			bfs(idx,dist,n);

			int nodes=0;
			for(i=1;i<=n;i++)
			{
				if(dist[i]<=t)
					nodes++;
			}

			printf("Number of nodes reachable from %d in at most t-hops : %d \n",roll_nu,nodes-1);

		}
		else
		{
			int roll_1,roll_2,idx1,idx2;
			printf("Enter roll number 1 : ");
			scanf("%d",&roll_1);
			printf("Enter roll number 2 : ");
			scanf("%d",&roll_2);

			for(i=1;i<=n;i++)
			{
				if(B[i].roll_no == roll_1)
				{
					idx1 = i;
				}

				if(B[i].roll_no == roll_2)
				{
					idx2 = i;
				}
			}

			int dist[1005];

			bfs(idx1,dist,n);

			if(dist[idx2]>=1000000)
				printf("Distance between %d and %d is infinite \n",roll_1,roll_2);
			else
				printf("Distance between %d and %d is %d \n",roll_1,roll_2,dist[idx2]);
		}
	}

	return 0;
}
