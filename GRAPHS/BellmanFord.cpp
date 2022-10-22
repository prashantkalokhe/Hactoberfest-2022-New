// shortest distance with negative weights...
#include<bits/stdc++.h>
using namespace std;

struct node{
	int u;
	int v;
	int wt;

	node(a, b, c){
		u=a;
		v=b;
		wt=c;
	}
};


int main(){

	int n, m;
	cin>>n>>m;

	vector<node> adj;
	for(int i=0; i<m; i++){
		int u, v, wt;
		cin>>u>>v>>wt;
		adj.push_back(node(u, v, wt));
	}
	int src;
	cin>>src;

	int inf = 100000
	vector<int> dist(n, inf);

	dist[src] = 0;

	for(int i=0; i<n-1; i++){
		for(auto it:adj){
			if(dist[it.u] + it.wt < dist[it.v]){
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}

	int fl=0;

	for(auto it:adj){
		if(dist[it.u] + it.wt < dist[it.v]){
			fl = 1;
			break;
		}
	}
	if(!fl){
		for(int i=0; i<n; i++){
			cout<<i<<" "<<dist[i]<<endl;
		}
	}



	return 0;
}