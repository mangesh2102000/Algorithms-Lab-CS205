#include<stdio.h>

int maxi(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int dp[1001][1001];
int a[1001],b[1001],p[1001];
int random[1001][1001][5];

void solve(int s,int t,int f[])
{
	if(!dp[s][t])
		return;

	f[random[s][t][0]]++;

	solve(random[s][t][1],random[s][t][2],f);

	solve(random[s][t][3],random[s][t][4],f);
}

int main()
{
	int x,y,n,i,j,k;
	printf("Enter dimension of sheet : ");
	scanf("%d %d",&x,&y);

	printf("Enter the number of products : ");
	scanf("%d",&n);

	a[0] = b[0] = p[0] = 0;

	int counter=n+1;

	printf("Enter dimensions of all products and profits respectively : \n");
	for(i=1;i<n+1;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&p[i]);

		if(a[i]!=b[i])
		{
			a[counter]=b[i];
			b[counter]=a[i];
			p[counter]=p[i];
			counter++;
		}
	}

	n = counter - 1;

	for(i=0;i<x+1;i++)
	{
		for(j=0;j<y+1;j++)
		{
			dp[i][j]=0;
		}
	}

	int f[n+1];
	for(i=0;i<n+1;i++)
	{
		f[i]=0;
	}

	for(i=1;i<x+1;i++)
	{
		for(j=1;j<y+1;j++)
		{
			for(k=1;k<n+1;k++)
			{
				if(i-a[k]>=0 && j-b[k]>=0)
				{
					int q=p[k]+maxi(dp[i-a[k]][b[k]] + dp[i][j-b[k]],dp[i-a[k]][j]+dp[a[k]][j-b[k]]);
					if(q>dp[i][j])
					{				
						if(dp[i-a[k]][b[k]] + dp[i][j-b[k]]>dp[i-a[k]][j]+dp[a[k]][j-b[k]])
						{
							random[i][j][1]=i-a[k];
							random[i][j][2]=b[k];
							random[i][j][3]=i;
							random[i][j][4]=j-b[k];
						}
						else
						{
							random[i][j][1]=i-a[k];
							random[i][j][2]=j;
							random[i][j][3]=a[k];
							random[i][j][4]=j-b[k];							
						}

						dp[i][j]=q;
						random[i][j][0] = k;
					}
				}
			}
		}
	}

	solve(x,y,f);
	
	printf("Maximum Profit : %d\n",dp[x][y]);

	printf("Strategy of cutting cloth \n");

	for(i=1;i<n+1;i++)
	{
		if(f[i]!=0)
		{
			if(f[i]==1)
			printf("%d cloth of %d x %d \n",f[i],a[i],b[i]);
			else
			printf("%d cloths of %d x %d \n",f[i],a[i],b[i]);
		}
	}

	return 0;
}