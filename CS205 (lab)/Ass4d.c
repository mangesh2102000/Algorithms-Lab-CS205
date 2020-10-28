#include<stdio.h>
#include<stdlib.h>

int q;

int compare(const void * a, const void * b)
{
     return (*(int *) a - *(int *) b);
}

int select_by_parts(int arr[],int start,int end)
{
	int i,l,r,siz;

	if(end-start+1 <= 5)
	{
	   siz = end-start+1;
       qsort(arr+start,siz,sizeof(int),compare);
       return arr[start + (end-start+1)/2];
   	}
   	int med[(end+1)/5];
	for(i=0;i<(end+1)/5;i++)
	{
		l = 5*i;
		r = l+4;
		if(r>end)
		{
			r=end;
		}
		med[i] = select_by_parts(arr,l,r);
	}
	return select_by_parts(med,0,(end+1)/5 - 1);
}

void solve(int y[],int n,int k)
{
	int M = select_by_parts(y,0,n-1);
	int i=0,lc=0,rc=0,eq=0;

	for(i=0;i<n;i++)
	{
		if(y[i]<M)
		{
			lc++;
		}
		else if(y[i]>M)
		{
			rc++;
		}
		else
		{
			eq++;
		}		
	}

	int l[lc],r[rc],e[eq],j=0,c=0,c1=0;
	for(i=0;i<n;i++)
	{
		if(y[i]<M)
		{
			l[j]=y[i];
			j++;
		}
		else if(y[i]>M)
		{
			r[c]=y[i];
			c++;
		}
		else
		{
			e[c1]=y[i];
			c1++;
		}
	}
	
	if(k <= lc)
	{
		solve(l,lc,k);		
	}
	else if(k > lc+eq)
	{
		solve(r,rc,k-(lc+eq));
	}
	else if(k>lc && k<=lc+eq)
	{
		q = M;
	}
}
	

int main()
{
	int n,i,a,b,ans;
	printf("Enter the total number of computers : ");
	scanf("%d",&n);
	int y[n];
	printf("Enter the positions of computers in coordinate system (Format : x y (for each computer)) \n");
	for(i=0;i<n;i++)
	{
		printf("Enter (x,y) for Computer %d : ",i+1);
		scanf("%d %d",&a,&b);
		y[i] = b;
	}

	if(n%2==1)
	{
		solve(y,n,n/2+1);
		ans = q;
	}
	else
	{		
		solve(y,n,n/2);
		ans = q;
	}
	printf("Line should be at y = %d \n",ans);
	return 0;
}
