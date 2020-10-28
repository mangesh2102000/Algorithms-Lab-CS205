#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int d;
	int m;
	int y;
} date;

int compare(const void * a, const void * b)
{
	date  *A = (date *)a;
    date  *B = (date *)b;

    if(B->y == A->y)
    {
    	if(B->m == A->m)
    	{
    		return (A->d - B->d);
    	}
    	return (A->m - B->m);
    }
    return (A->y - B->y); 
}

int main()
{
	int n;
	printf("Enter the total number of elements : ");
	scanf("%d",&n);

	date a[n];	
	char x[8];
	
	int tmp=n,i=0;
	while(tmp--)
	{		
		printf("Enter date %d : ",i+1);
		scanf("%s",x);
		a[i].d = (x[0]-'0')*10 + (x[1]-'0');
		a[i].m = (x[2]-'0')*10 + (x[3]-'0');
		a[i].y = (x[4]-'0')*1000 + (x[5]-'0')*100 + (x[6]-'0')*10 + (x[7]-'0');
		i++;
	}

	printf("Sorted List of Dates is as follows : \n");

	qsort(a,n,sizeof(date),compare);

	for(int i=0;i<n;i++)
	{
		printf("%d : %d-%d-%d \n",i+1,a[i].d,a[i].m,a[i].y);
	}
		
	return 0;
}