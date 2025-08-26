#include <bits/stdc++.h>
using namespace std;
vector<int>g[100009];
bool visited[100009];

int main() {
	int n,m,k,u,v;
	cin>>n>>m>>k;
	while(m--)
	{
	    cin>>u>>v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	
	vector<int>ans;
	
	for(int i=1;i<=n;i++)
	{
	    stack<int>s;
	    int count=0;
	    if(visited[i]==0)
	    {
	        count=1;
	        s.push(i);
	        visited[i]=1;
	        while(!s.empty())
	        {
	            u=s.top();
	            s.pop();
	            for(int i=0;i<g[u].size();i++)
	            {
	                if(visited[g[u][i]]==0)
	                {
	                    count++;
	                    s.push(g[u][i]);
	                    visited[g[u][i]]=1;
	                }
	            }
	        }
	        ans.push_back(count);
	    }
	}
	
	int res=0;
	
	sort(ans.begin(),ans.end(),greater<int>());
	m=ans.size();
	m=min(m,k);
	
	for(int i=0;i<=m;i++)
	{
	    res+=ans[i];
	}
	cout<<res<<endl;
	
	return 0;
	
}
