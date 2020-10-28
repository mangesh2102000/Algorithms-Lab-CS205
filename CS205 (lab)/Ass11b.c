#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int g[13][13],res_g[13][13];
int vis[13];
int queue[105];
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
    if(f>r)
      f=r=-1;
    return a;
}

int is_empty()
{
    if(f==-1 || f>r)
      return 1;
    return 0;
}

int min(int a,int b)
{
    if(a<b)
      return a;
    return b;  
}

int aug_path(int s,int t,int parent[])
{
    f=r=-1;
    int i,j;
    for(i=0; i<13; i++)
    {
        vis[i]=0;
    }

    push(s);
    vis[s]=1;
    parent[s]=-1;

    while(!is_empty())
    {
        int x=pop();

        for(i=0; i<13; i++)
        {
            if(vis[i]==0 && res_g[x][i]>0)
            {              
                push(i);
                parent[i]=x;
                vis[i]=1;
            }
        }
    }

    return (vis[t]==1);
}

int max_cells(int s,int t)
{
    int i,j,max_flow=0;
    for(i=0; i<13; i++)
    {
        for(j=0; j<13; j++)
        {
            res_g[i][j]=g[i][j];
        }
    }

    int parent[13];

    while( aug_path(s,t,parent) )
    {
        int inc=1e9;;
        
        for(i=t;i!=s;i=parent[i])
        {
              inc = min(inc, res_g[parent[i]][i]);
        }

        for(i=t ;i!=s;i=parent[i])
        {
            res_g[parent[i]][i]-=inc;
            res_g[i][parent[i]]+=inc;
        }
        max_flow += inc;
    }

    return max_flow;
}


int main()
{
  int a,s=0,t=12;

  g[s][1]=g[s][2]=g[s][3]=g[s][4]=18;

  printf("Exclusive zone of cell tower A : ");
  scanf("%d",&a);
  g[1][t]=a;

  printf("Exclusive zone of cell tower B : ");
  scanf("%d",&a);
  g[2][t]=a;

  printf("Exclusive zone of cell tower C : ");
  scanf("%d",&a);
  g[3][t]=a;

  printf("Exclusive zone of cell tower D : ");
  scanf("%d",&a);
  g[4][t]=a;

  printf("Shared Zone of A & B : ");
  scanf("%d",&a);
  g[5][t]=g[1][5]=g[2][5]=a;

  printf("Shared Zone of A & D : ");
  scanf("%d",&a);
  g[6][t]=g[1][6]=g[4][6]=a;

  printf("Shared Zone of A & B & D : ");
  scanf("%d",&a);
  g[7][t]=g[1][7]=g[2][7]=g[4][7]=a;

  printf("Shared Zone of B & C : ");
  scanf("%d",&a);
  g[8][t]=g[2][8]=g[3][8]=a;

  printf("Shared Zone of B & D : ");
  scanf("%d",&a);
  g[9][t]=g[2][9]=g[4][9]=a;

  printf("Shared Zone of B & C & D : ");
  scanf("%d",&a);
  g[10][t]=g[2][10]=g[3][10]=g[4][10]=a;

  printf("Shared Zone of C & D : ");
  scanf("%d",&a);
  g[11][t]=g[3][11]=g[4][11]=a;

  int ans = max_cells(0,12);
  
  printf("\nNumber of maximum cell phone which can be satisfied : %d\n",ans);

  printf("Possible distribution of satisfied devices across zones : \n");

  printf("Exclusive zone of cell tower A => %d\n",res_g[t][1]);

  printf("Exclusive zone of cell tower B => %d\n",res_g[t][2]);

  printf("Exclusive zone of cell tower C => %d\n",res_g[t][3]);

  printf("Exclusive zone of cell tower D => %d\n",res_g[t][4]);

  printf("Shared Zone of A & B => Contribution of A : %d and Contribution of B : %d\n",res_g[5][1],res_g[5][2]);

  printf("Shared Zone of A & D => Contribution of A : %d and Contribution of D : %d\n",res_g[6][1],res_g[6][4]);

  printf("Shared Zone of A & B & D => Contribution of A : %d and Contribution of B : %d and Contribution of D : %d\n",res_g[7][1],res_g[7][2],res_g[7][4]);
  
  printf("Shared Zone of B & C => Contribution of B : %d and Contribution of C : %d\n",res_g[8][2],res_g[8][3]);
  
  printf("Shared Zone of B & D => Contribution of B : %d and Contribution of D : %d\n",res_g[9][2],res_g[9][4]);
  
  printf("Shared Zone of B & C & D => Contribution of B : %d and Contribution of C : %d Contribution of D : %d \n",res_g[10][2],res_g[10][3],res_g[10][4]);
  
  printf("Shared Zone of C & D => Contribution of C : %d and Contribution of D : %d\n",res_g[11][3],res_g[11][4]);
  
  return 0;
} 
