#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//24-hour format

typedef struct{
	int sim;
	float ti;
	char pat[100];
	int vis;
} ioigod;

ioigod arr[1000];

int compare(const void * a, const void * b)
{
	ioigod  *A = (ioigod *)a;
    ioigod  *B = (ioigod *)b;

    if(B->sim == A->sim)
    {
    	return ((A->ti*(1000)) - (B->ti*(1000)) );
    }


    return (B->sim - A->sim); 
}

int main()
{	
	printf("Doctor Name : ");
	char name_doctor[100];
	scanf("%s",name_doctor);
	int n,k;
	printf("Number of Patients (n) : ");
	scanf("%d",&n);
	printf("Number of Patients before 8 am (k) : ");
	scanf("%d",&k);

	char patient_name[n][100];
	float time[n]; 
	int cnt[n][26];
	int doc_cnt[26];
	int similar[n];

	for(int i=0;i<26;i++)
	{
		doc_cnt[i]=0;	
	} 

	for(int i=0;i<n;i++)
	{
		similar[i]=0;
		for(int j=0;j<26;j++)
		{
			cnt[i][j]=0;	
		}
	} 


	for(int i=0;name_doctor[i]!='\0';i++)
	{
		if(name_doctor[i]>='A' && name_doctor[i]<='Z')
		{	
			doc_cnt[name_doctor[i]-'A']=1;
		}
		else
		{
			doc_cnt[name_doctor[i]-'a']=1;
		}
	}   

	int count=0,tmp=k;
	while(tmp--)
	{	
		scanf("%s",patient_name[count]);
		scanf("%f",&time[count]);

		for(int j=0;patient_name[count][j]!='\0';j++)
		{
			if(patient_name[count][j]>='A' && patient_name[count][j]<='Z')
			{	
				cnt[count][patient_name[count][j]-'A']=1;
			}
			else
			{
				cnt[count][patient_name[count][j]-'a']=1;
			}
		}

		for(int k=0;k<26;k++)
		{
			if(doc_cnt[k]==1 && cnt[count][k]==1)
			{
				similar[count]++;
			}
		}

		count++;
	}

	for(int i=0;i<k;i++)
	{
		arr[i].sim = similar[i];
		arr[i].ti = time[i];
		strcpy(arr[i].pat,patient_name[i]);
		arr[i].vis = 0;
	}

	qsort(arr, count, sizeof(ioigod), compare);

	/*for(int i=0;i<k;i++)
	{
		printf("%d %f %s \n",arr[i].sim,arr[i].ti,arr[i].pat);
	}*/

	int x,printing = 0;	

	while(1)
	{
		if(printing==n)
		{
			break;
		}

		int check = 1;

		for(int j=0;j<n;j++)
		{
			if(arr[j].vis==0)
			{
				if(arr[j].ti*1000 > 12000)
				{
					check = 0;	
				}

				if(check == 1)
				{
					printf("List %d : %s, %f am \n",printing+1,arr[j].pat,arr[j].ti);
					
				}
				else
				{			
					printf("List %d : %s, %f pm \n",printing+1,arr[j].pat,arr[j].ti);
				}

				arr[j].vis=1;
				printing++;
				break;
			}				
		}	

		if(count<n)
		{
			printf("Are there more patients?(0/1) : ");
			scanf("%d",&x);
			if(x==0)
			{
				
			}
			else
			{
				printf("Input number of patients: ");
				int m,tmp1;
				scanf("%d",&m);
				tmp1=m;
				while(tmp1--)
				{
					scanf("%s",patient_name[count]);
					scanf("%f",&time[count]);

					for(int l=0;patient_name[count][l]!='\0';l++)
					{
						if(patient_name[count][l]>='A' && patient_name[count][l]<='Z')
						{	
							cnt[count][patient_name[count][l]-'A']=1;
						}
						else
						{
							cnt[count][patient_name[count][l]-'a']=1;
						}
					}

					for(int k=0;k<26;k++)
					{
						if(doc_cnt[k]==1 && cnt[count][k]==1)
						{
							similar[count]++;
						}
					}

					arr[count].sim = similar[count];
					arr[count].ti = time[count];
					strcpy(arr[count].pat,patient_name[count]);
					arr[count].vis = 0;
					count++;
				}
				qsort(arr, count, sizeof(ioigod), compare);				
			}
		}			

	}

	return 0;
}
