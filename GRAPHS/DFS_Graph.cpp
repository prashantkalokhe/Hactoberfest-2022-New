#include<bits/stdc++.h>
using namespace std;

vector<int>Depth_Graph(int V, vector<int> adj[])
{
	vector<int> dfs;
	vector<int> vis(V+1, 0);

	for(int i=0 ;i<V; i++)
	{
		if(!vis[i])
		{
			stack<int>st;
			st.push(i);
			vis[i] = 1;

			while(!st.empty)
			{
				int node = st.top();
				st.pop();
				dfs.push_back(node);
				for(auto it: adj[node])
				{
					if(!vis[it])
					{
						st.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}
}