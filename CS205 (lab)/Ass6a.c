#include<stdio.h>
#include<stdlib.h>

// Ratio (d/l) must be less than 1000000 for each job 

typedef struct{
	int d;
	int l;
	float r;
	int id;
} data;


int compare(const void * a, const void * b)
{
	data *A = (data *)a;
	data *B = (data *)b;
	
	if(A->r*1000==B->r*1000)
	{
		return A->id - B->id;	
	}	
	
	return (A->r*1000 - B->r*1000);
}


int main()
{
	int i,n,a,b;
	printf("Enter no. of jobs : ");
	scanf("%d",&n);
	
	data j[n];	
	
	printf("Enter loss per hour {l} : ");
		
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		j[i].l = a;
		j[i].id = i+1;
	}
	
	printf("Enter duration {d} : ");
		
	for(i=0;i<n;i++)
	{	
		scanf("%d",&b);
		j[i].d = b;		
	}
	
	for(i=0;i<n;i++)
	{
		if(j[i].l != 0)
		{
			j[i].r = (float)j[i].d/(float)j[i].l;
		}
		else
		{
			j[i].r = 1000000;	
		}	
	}
	
	qsort(j,n,sizeof(data),compare);
	printf("Output : ");
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		printf("%d, ",j[i].id);
		else
		printf("%d ",j[i].id);
	}
	printf("\n");
	
}
