#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair

vector < pair < int,pair<int,int> > > edges;
vector < pair < int,pair<int,int> > > ans;
int n,k;
int rep[100005];

int findset(int a)
{
	while(a!=rep[a])
	{
		rep[a]=rep[rep[a]];
		a = rep[a];
	}
	return a;	
}

int unite_sets(int x,int y)
{
	int a = findset(x),b = findset(y);
	rep[a]=rep[b];
}

int main()
{
	int v1,v2,w,i,j;
	cout << "Enter no. of towers : ";
	cin >> n;
	cout << "Enter no. of roads that are feasible : ";
	cin >> k;

	cout << "Enter roads in format : v1 v2 w \n";
	for(i=0;i<k;i++)
	{
		cin >> v1 >> v2 >> w;
		edges.push_back(mp(w,mp(v1,v2)));
	}	

	sort(edges.begin(),edges.end());

	for(i=0;i<=n;i++)
	{
		rep[i]=i;
	}

	int totalcost=0;
	for(i=0;i<edges.size();i++)
	{
		v1 = edges[i].S.F;
		v2 = edges[i].S.S;
		w = edges[i].F;

		int cmp1=findset(v1),cmp2=findset(v2);
		if(cmp1!=cmp2)
		{
			totalcost += w;
			ans.push_back(mp(w,mp(v1,v2)));
			unite_sets(v1,v2);			
		}
	}

	cout << "Total cost of building all the roads : " << totalcost << "\n";
	cout << "No. of roads that will be constructed : " << ans.size() << "\n";
	for(i=0;i<ans.size();i++)
	{
		cout << ans[i].S.F << " " << ans[i].S.S << " " << ans[i].F << "\n";
	}

} 