#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	int x;
	int y;
}node;

int M[1005][1005];
int s=-1,e=-1;
node arr[1000005];
int vis[1005][1005],dist[1005][1005];
node parent[1005][1005];
char dir[1000005][2];
int fin_dist=0;

void push(node x)
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

node pop()
{
	if(s==-1 || s>e)
	{
		printf("Queue Underflow\n");
	}
	node x = arr[s];
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

int r[] = {-1,-1,-1,0,0,1,1,1};
int c[] = {-1,0,1,-1,1,-1,0,1};

void bfs(int sx,int sy,int n)
{
	int i,j;

	for(i=0;i<1005;i++)
	{
		for(j=0;j<1005;j++)
		{	
			vis[i][j]=0;
			dist[i][j]=1000000;			
		}
	}

	node tmp;
	tmp.x = sx;
	tmp.y = sy;

	push(tmp);	
	dist[sx][sy]=0;
	vis[sx][sy]=1;

	while(!is_empty())
	{		
		node tmp = pop();				
		for(i=0;i<8;i++)
		{
			node tmp1;
			tmp1.x = tmp.x + r[i];
			tmp1.y = tmp.y + c[i];			

			if( (tmp1.x>=0 && tmp1.x<n) && (tmp1.y>=0 && tmp1.y<n) && M[tmp1.x][tmp1.y]==1 && vis[tmp1.x][tmp1.y]==0 )
			{				
				parent[tmp1.x][tmp1.y]=tmp;
				dist[tmp1.x][tmp1.y] = 1 + dist[tmp.x][tmp.y];
				vis[tmp1.x][tmp1.y] = 1;
				push(tmp1);
			}
		}
	}
}

void fill_dir(int x,int y,int px,int py)
{	int i;
	for(i=0;i<8;i++)
	{
		node tmp1;
		tmp1.x = x + r[i];
		tmp1.y = y + c[i];

		if(tmp1.x == px && tmp1.y == py)
		{
			if(r[i]==-1 && c[i]==-1)
			{
				dir[fin_dist][0] = 'S';
				dir[fin_dist][1] = 'E'; 
			}
			else if(r[i]==-1 && c[i]==0)
			{
				dir[fin_dist][0] = 'D';
				dir[fin_dist][1] = ' '; 
			}
			else if(r[i]==-1 && c[i]==1)
			{
				dir[fin_dist][0] = 'S';
				dir[fin_dist][1] = 'W'; 
			}
			else if(r[i]==0 && c[i]==-1)
			{
				dir[fin_dist][0] = 'R';
				dir[fin_dist][1] = ' '; 
			}
			else if(r[i]==0 && c[i]==1)
			{
				dir[fin_dist][0] = 'L';
				dir[fin_dist][1] = ' '; 
			}
			else if(r[i]==1 && c[i]==-1)
			{
				dir[fin_dist][0] = 'N';
				dir[fin_dist][1] = 'E'; 
			}
			else if(r[i]==1 && c[i]==0)
			{
				dir[fin_dist][0] = 'U';
				dir[fin_dist][1] = ' '; 
			}
			else if(r[i]==1 && c[i]==1)
			{
				dir[fin_dist][0] = 'N';
				dir[fin_dist][1] = 'W'; 
			}

			break;
		}
	}	
	fin_dist++;
}

int main()
{
	/* Maze has 0-indexed co-ordinate system and top left corner of maze represents (0,0)*/
	int rows,sx,sy,dx,dy,kx,ky,i,j,check1=0,check2=0;
	printf("Enter the number of rows : ");
	scanf("%d",&rows);
	printf("Enter source : ");
	scanf("%d %d",&sx,&sy);
	printf("Enter destination : ");
	scanf("%d %d",&dx,&dy);
	printf("Enter key cell : ");
	scanf("%d %d",&kx,&ky);

	srand(time(0));

	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++)
		{
			M[i][j] = rand()%2;
		}
	}

	M[sx][sy] = M[dx][dy] = 1;
	M[kx][ky] = 1; 
	
	bfs(kx,ky,rows);
	int p=dx,q=dy;
	
	if(dist[dx][dy]<1000000)
	{
		check1=1;
		while(1)
		{
			if(p == kx && q == ky)
				break;			
			node tmp = parent[p][q];
			fill_dir(p,q,tmp.x,tmp.y);					
			p = tmp.x;
			q = tmp.y;		
		}
		
		bfs(sx,sy,rows);		
		p=kx,q=ky;
		if(dist[kx][ky]<1000000)
		{
			check2=1;
			while(1)
			{
				if(p == sx && q == sy)
					break;	
				node tmp = parent[p][q];
				fill_dir(p,q,tmp.x,tmp.y);							
				p = tmp.x;
				q = tmp.y;
			}
		}				
	}

	printf("Randomly Generated Maze : \n");
	M[kx][ky] = 2; 
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++)
		{
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}	
	
	if(check1 && check2)
	{
		printf("\nOutput Directions : ");
		for(i = fin_dist-1;i>=0;i--)
		{
			if(dir[i][1]==' ')
			printf("%c ",dir[i][0]);
			else
			printf("%c%c ",dir[i][0],dir[i][1]);
		}			
		printf("\nMinimum Distance Required is : %d \n",fin_dist);
	}
	else
	{
		printf("\nPath through key from source to destination does not exist \n");
	}			
	
	return 0;	
}

