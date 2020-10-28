#include<bits/stdc++.h>
using namespace std;

/* Maximum DNA seq. length allowed is 1000*/

int dp[1001][1001];
void initialize()
{
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<1001;j++)
		{
			dp[i][j]=-1;
		}
	}
}

int solve(string s1,string s2,int l1,int l2)
{
	if(l1==0 && l2==0)
	{
		return 0;
	}
	else if(l1==0 && l2!=0)
	{
		return l2;
	}
	else if(l2==0 && l1!=0)
	{
		return l1;
	}

	if(s1[l1-1]==s2[l2-1])
	{
		int var;
		if(dp[l1-1][l2-1]!=-1)
		{	
			var = dp[l1-1][l2-1];
		}
		else
		{
			var = solve(s1,s2,l1-1,l2-1);
			dp[l1-1][l2-1]=var;
		}
		return var;
	}
	else
	{
		int x,y,z;
		
		if(dp[l1-1][l2-1]!=-1)
		{	
			x = dp[l1-1][l2-1];
		}
		else
		{
			x = solve(s1,s2,l1-1,l2-1);
			dp[l1-1][l2-1]=x;
		}
				
		if(dp[l1][l2-1]!=-1)
		{	
			y = dp[l1][l2-1];
		}
		else
		{
			y = solve(s1,s2,l1,l2-1);
			dp[l1][l2-1]=y;
		}
			
		if(dp[l1-1][l2]!=-1)
		{	
			z = dp[l1-1][l2];
		}
		else
		{
			z = solve(s1,s2,l1-1,l2);
			dp[l1-1][l2]=z;
		}
		return 1+min(x,min(y,z));
	}
	return -1;
}



int main()
{
	string s1,s2;
	cout << "Enter gene1 = ";
	cin >> s1;
	cout << "Enter gene2 = ";
	cin >> s2;

	initialize();
	int l1=s1.length(),l2=s2.length();

	int ans = solve(s1,s2,l1,l2);
	cout << "Similarity : ";
	cout << (l1+l2-ans) << "\n";
	cout << "Total number of operations required = ";
	cout << ans << "\n";
	return 0;
}
