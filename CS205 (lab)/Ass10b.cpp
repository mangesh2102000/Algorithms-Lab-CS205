// Code is corrected afterwards
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair

vector < pair < int,double > > adj[1005];
vector < pair < pair<int,int> , double > > edges;
double reset[1005];
int vis[1005];
double dist1[1005];
int parent[1005];

void dijkstra(int s,double dist[])
{
	int i;
	dist[s]=0;
	priority_queue < pair<double,int> > pq;

    pq.push(mp(0,s));
	while(!pq.empty())
	{
		pair <double,int> p;
		p = pq.top();
		pq.pop();
		if(vis[p.S]) continue;
		vis[p.S]=1;

		for(i=0;i<adj[p.S].size();i++)
		{
			if( (dist[p.S] + adj[p.S][i].S)*1000 <= (dist[adj[p.S][i].F])*1000 )
			{
				dist[adj[p.S][i].F] = dist[p.S] + adj[p.S][i].S;
				pq.push(mp(-dist[adj[p.S][i].F],adj[p.S][i].F));
			}
		}
	}
}

int main()
{
	int n,f,i,j,k,s,d,u,v,ans=0;
	double c,w;
	printf("Enter no. of spaceports : ");
	cin >> n;
	printf("Enter no. of flights : ");
	cin >> f;

	printf("Enter details of the flights (format : source dest cost ) : \n");
	for(i=0;i<f;i++)
	{
		cin >> s >> d >> c;
		edges.pb(mp(mp(s,d),c));
	}

	for(i=0;i<n;i++)
	{
		edges.pb(mp(mp(0,i+1),0));
	}

	reset[0]=0;	
	for(i=1;i<n+1;i++)
	{
		reset[i] = 1000000;
	}
	int no_of_edges = edges.size(),flag=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<no_of_edges;j++)
		{
			u = edges[j].first.first;
			v = edges[j].first.second;
			w = edges[j].second;

			if( (reset[v])*1000 > (reset[u] + w)*1000 )
			{
				reset[v] = reset[u] + w;
				parent[v] = u;
			}
		}
	}

	for(j=0;j<no_of_edges;j++)
	{
		u = edges[j].first.first;
		v = edges[j].first.second;
		w = edges[j].second;
	
		if( (reset[v])*1000 > (reset[u] + w)*1000 )
		{			
			reset[v] = reset[u] + w;
			parent[v] = u;
			flag = 1;
		}
	}
		
	if(flag==1)
	{
		printf("Negative cycle exists\n");
	}
	else
	{		
		for(i=0;i<no_of_edges;i++)
		{
			u = edges[i].first.first;
			v = edges[i].first.second;
			w = edges[i].second;

			if(u!=0)
				adj[u].pb(mp(v,w+reset[u]-reset[v]));
		}
		
		for(i=1;i<=n;i++)
		{
			cout << i << "-\n";
			for(j=0;j<adj[i].size();j++)
			{
				cout << adj[i][j].F << "=" << adj[i][j].S << "\n";
			}
		}
		double sum = 1000000000;

		for(i=1;i<=n;i++)
		{
			cout << "node" << i << " ";
			
			double curr_sum=0;
			for(j=1;j<=n;j++)
			{
				dist1[j]=1000000;
				vis[j]=0;
			}
			dijkstra(i,dist1);
			cout << "distances - ";
			for(j=1;j<=n;j++)
			{
				curr_sum += (dist1[j]+reset[j]-reset[i]);   // Correction
				cout << j << "-" << (dist1[j]+reset[j]-reset[i]) << " ";
			}

			cout << "total dist - "<< curr_sum << "\n";
			if( (curr_sum)*1000 < (sum)*1000 )
			{
				ans = i;
				sum = curr_sum;
			}
		}

		printf("Spaceport that minimizes the sum of the minimum flying times to all other spaceports is %d\n",ans);
	}
	return 0;
}
