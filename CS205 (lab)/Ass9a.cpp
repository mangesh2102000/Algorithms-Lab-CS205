#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair

int n,m,q,s,t;
vector < pair < int,int > > adj[100005];
int vis[100005];
int dist2[100005];
int dist1[100005];

void dijkstra(int s,int dist[])
{
	int i;
	dist[s]=0;
	priority_queue < pair<int,int> > pq;

    pq.push(mp(0,s));
	while(!pq.empty())
	{
		pair <int,int> p;
		p = pq.top();
		pq.pop();
		if(vis[p.S]) continue;
		vis[p.S]=1;

		for(i=0;i<adj[p.S].size();i++)
		{
			if(dist[p.S] + adj[p.S][i].S <= dist[adj[p.S][i].F])
			{
				dist[adj[p.S][i].F] = dist[p.S] + adj[p.S][i].S;
				pq.push(mp(-dist[adj[p.S][i].F],adj[p.S][i].F));
			}
		}
	}
}

int main()
{
	int u,v,w,i,j;
	cout << "Enter no. of nodes : ";
	cin >> n;
	cout << "Enter no. of edges : ";
	cin >> m;

	cout << "Enter edges format : u v w \n";
	for(i=0;i<m;i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back(mp(v,w));
		adj[v].push_back(mp(u,w));
	}

	cout << "Enter no. of potential edges : ";
	cin >> q;
	int p_ed[q][3];
	for(i=0;i<q;i++)
	{
		cin >> u >> v >> w;
		p_ed[i][0]=u;
		p_ed[i][1]=v;
		p_ed[i][2]=w;
	}

	cout << "Enter value of s and t : ";
	cin >> s >> t;

	for(j=0;j<=n;j++)
	{
		dist2[j]=1000000;
	}
	dijkstra(s,dist2);

	for(j=0;j<=n;j++)
	{
		vis[j]=0;
	}
	for(j=0;j<=n;j++)
	{
		dist1[j]=1000000;
	}
	dijkstra(t,dist1);

	int min_dist = dist2[t],ansu=0,ansv=0,answ=0,flag=0;

	for(i=0;i<q;i++)
	{
		u = p_ed[i][0];
		v = p_ed[i][1];
		w = p_ed[i][2];

		int tmp = min(dist2[u]+w+dist1[v],dist1[u]+w+dist2[v]);
		if(tmp<min_dist)
		{
			ansu = p_ed[i][0];
			ansv = p_ed[i][1];
			answ = p_ed[i][2];
			min_dist = tmp;
			flag=1;
		}
	}

	if(flag==1)
	{
		cout << "Edge to be constructed : ";
		cout << ansu << " " << ansv << "\n";
	}
	else
	{
		cout << "No edge is required to be constructed\n";
	}		

} 
