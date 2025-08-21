#include<bits/stdc++.h>
using namespace std;
vector<int>g[1009];
bool visited[1009];
int lev[1009];
int main()
{
	int n,m,k,c,u,v;
	cin>>n>>m>>k>>c;
	while(m--)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int>q;
	q.push(c);
	visited[c]=1;
	lev[c]=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			if(visited[g[u][i]]==0)
			{
				lev[g[u][i]]=1+lev[u];
				q.push(g[u][i]);
				visited[g[u][i]]=1;
			}
		}
	}
	int ans=1;
	for(int i=0;i<1009;i++)
	{
		if(lev[i]>0&&lev[i]<=k)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}