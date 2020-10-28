#include<bits/stdc++.h>
using namespace std;

int main()
{
	int A[101][10001];
	for(int i=0;i<101;i++)
	{
	    for(int j=0;j<10001;j++)
	    {
	        A[i][j]=0;
	    }
	}
    int n,M,T=0;
    cout << "Enter number of houses(n) : ";
    cin >> n;
    cout << "Enter profit bound(M) : ";
    cin >> M;
    int p[n+1];
    srand (time(NULL));
    for(int i=1;i<=n;i++)   
    {
        p[i] = rand() % M + 1;
        T += p[i];
    } 
    
    for(int j=0;j<=T;j++)
    {
        A[0][j]=0;
    }
    
    for(int i=1;i<=n;i++)
    {
	    for(int j=1;j<=T;j++)
        {
             A[i][p[i]]=2;
             
				if(A[i-1][j]!=0)
				A[i][j]=1;
				else if( j-p[i]>=0 && A[i-1][j-p[i]]!=0)
				A[i][j]=2;
				else
				A[i][j]=0;
        }
    }
    
    int s1,s2,tmp1,tmp2,diff=1000000,ans=0;
    for(int i=1;i<=T;i++)
    {
        tmp1 = i;
        tmp2 = T-tmp1;
        
        if(A[n][tmp1]==0 || A[n][tmp2]==0)
        {
            
        }
        else
        {
            if(abs(tmp1-2*tmp2)<=diff)
            {
                s1=tmp1;
                s2=tmp2;
                diff=abs(tmp1-2*tmp2);
                ans=tmp1-2*tmp2;
            }
        }
    }
    
    int tmp=s1;
    set <int> h1,h2;
    int i=n;
    while(A[i][tmp]!=0)
    {
        if(A[i][tmp]==2)
        {
            h1.insert(i-1);
            tmp = tmp - p[i];
        }
        i--;
    }
    
    for(int i=0;i<n;i++)
    {
        if(h1.find(i)==h1.end())
        {
            h2.insert(i);
        }
    }
    
    cout << "Enter number of houses (n) : " << n << "\n";
    cout << "Enter profit bound(M) : " << M << "\n";
    cout << "Profits are ";
    for(int i=1;i<=n;i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
    
    cout << "Profit for first son : " << s1 << "\n";
    cout << "Profit for second son : "<< s2 << "\n";
    
    cout << "Imbalance (S1-2*S2) : " << ans << "\n";
    
    cout << "First son gets houses : ";
    
    set <int> :: iterator it;
    
    for(it=h1.begin();it!=h1.end();it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Second son gets houses : ";
    
    for(it=h2.begin();it!=h2.end();it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

