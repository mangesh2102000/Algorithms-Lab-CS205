#include <stdio.h>
#include <stdlib.h>

int valid(int c)
{
    if(c>1)
    {
        return 1;
    }
    
    return 0;
}

void print(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(i==size-1)
        {
            if(arr[i]==-1)
            printf("left\n");
            else if(arr[i]==1)
            printf("down\n");
        }
        else
        {
            if(arr[i]==-1)
            printf("left ");
            else if(arr[i]==1)
            printf("down ");
        }
    }
}

int solve(int arr[],int size,int x,int y)
{
    int ans1=0;
    
    if(x==1&&y==1)
    {
        print(arr,size);
        return 1;
    }
    
    if(valid(x)==1)
    {
        arr[size] = -1;
        ans1 += solve(arr,size+1,x-1,y);
    }
    
    if(valid(y)==1)
    {
        arr[size] = 1;
        ans1 += solve(arr,size+1,x,y-1);
    }
    
    return ans1;
}

int main()
{
    int x,y,n;
    scanf("%d %d",&x,&y);
    
    n = x+y;
    int arr[n];
    
    int ans = solve(arr,0,x,y);
    printf("Total number of ways = %d",ans);
		
    return 0;
}


