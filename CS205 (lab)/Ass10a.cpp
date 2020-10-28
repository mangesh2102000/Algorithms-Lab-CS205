#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

pair < string , string > input[1005];
int a[1005][26];

vector < pair < pair<int,int> , int > > edges;  

int dist[1005];
int parent[1005];

int main()
{
	int n,i,j,k;
	string s1,s2;
	printf("Enter no. of regions : ");
	cin >> n;
	printf("Enter the details of the regions : \n");
	for(i=0;i<n;i++)
	{
		cin >> s1 >> s2;		
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		input[i].first = s1;
		input[i].second = s2;
		for(j=0;j<s1.length();j++)
		{
			a[i][s1[j]-'a']++;
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(j!=i)
			{
				int cnt=0;
				for(k=0;k<26;k++)
				{
					cnt += min(a[i][k],a[j][k]);
				}

				if(cnt>=2)
				{
					string c1,c2,r1,r2;
					c1 = input[i].second;
					c2 = input[j].second;
					r1 = input[i].first;
					r2 = input[j].first;
					int l1,l2;
					l1 = r1.length();
					l2 = r2.length();
					
					if(r1[cnt-1]<r2[cnt-1])
					{
						if(c1==c2)
						{
							edges.pb(mp(mp(i,j),-1*(l1+l2)));
						}
						else
						{
							string cmp1="green",cmp2="blue";
							if(c1==cmp1 && c2==cmp2)
							{
								edges.pb(mp(mp(i,j),2*(l1+l2)));
							}
							else
							{
								edges.pb(mp(mp(i,j),(l1+l2)));
							}	
						}
					}
					else if(r1[cnt-1]>r2[cnt-1])
					{
						if(c1==c2)
						{
							edges.pb(mp(mp(j,i),-1*(l1+l2)));
						}
						else
						{
							string cmp1="blue",cmp2="green";
							if(c1==cmp1 && c2==cmp2)
							{
								edges.pb(mp(mp(j,i),2*(l1+l2)));
							}
							else
							{
								edges.pb(mp(mp(j,i),(l1+l2)));
							}	
						}
					}
					else
					{
						if(l1>=l2)
						{
							if(c1==c2)
							{
								edges.pb(mp(mp(i,j),-1*(l1+l2)));
							}
							else
							{
								string cmp1="green",cmp2="blue";
								if(c1==cmp1 && c2==cmp2)
								{
									edges.pb(mp(mp(i,j),2*(l1+l2)));
								}
								else
								{
									edges.pb(mp(mp(i,j),(l1+l2)));
								}	
							}
						}
						else
						{
							if(c1==c2)
							{
								edges.pb(mp(mp(j,i),-1*(l1+l2)));
							}
							else
							{
								string cmp1="blue",cmp2="green";
								if(c1==cmp1 && c2==cmp2)
								{
									edges.pb(mp(mp(j,i),2*(l1+l2)));
								}
								else
								{
									edges.pb(mp(mp(j,i),(l1+l2)));
								}	
							}
						}		
					}
				}
			}
		}
	}	
	
	dist[0]=0;	
	for(i=1;i<n+1;i++)
	{
		dist[i] = 1000000;
	}
	int no_of_edges = edges.size(),core=-1;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<no_of_edges;j++)
		{
			int v,u,w;
			u = edges[j].first.first;
			v = edges[j].first.second;
			w = edges[j].second;

			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				core = v;
			}
		}
	}
	int flag=0;
	for(j=0;j<no_of_edges;j++)
	{
		int v,u,w;
		u = edges[j].first.first;
		v = edges[j].first.second;
		w = edges[j].second;
	
		if(dist[v] > dist[u] + w)
		{			
			dist[v] = dist[u] + w;
			parent[v] = u;
			core = v;
			flag = 1;
		}
	}

	if(flag==0)
	{
		printf("Negative Cycle does not exist\n");
	}
	else
	{
		printf("Negative Cycle : ");
		int curr=core;
		for(i=0;i<n;i++)
			curr=parent[curr];

		vector<int> cycle;

		for(i=curr;;i=parent[i])
		{
		    cycle.pb(i);
		    if(i==curr && cycle.size()>1)
		        break;
		}
		reverse(cycle.begin(),cycle.end());
		int tmp=cycle.size();
		for(i=0;i<tmp;i++)
		{
		    if(i!=tmp-1)
			cout << "V" << (cycle[i]+1) << "->";
			else
			cout << "V" << (cycle[i]+1) << "\n";
		}				
	}
	return 0;
}
