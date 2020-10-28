#include<stdio.h>

#define ll long long int

ll dp[50];

ll solve(ll n)
{
	if(dp[n]!=0)
		return dp[n];
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;

	dp[n] = solve(n-1)+(n-1)*solve(n-2);

	return dp[n];
}

int main()
{
	ll n,ans;
	printf("Enter total number of banks : ");
	scanf("%lld",&n);

	ans = solve(n);
	printf("No of Combinations possible is : %lld \n",ans);
	
}
