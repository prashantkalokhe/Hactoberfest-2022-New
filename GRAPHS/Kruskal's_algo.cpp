#include<bits/stdc++.h>
using namespace std;
struct node{
	int u, v, wt;
	node(int first, int second, int weight){
		u = first;
		v = second;
		wt = weight;
	}
};

bool comp(node a, node b){
	return a.wt < b.wt;
}

int findPar(int a, vector<int>&parent){
	if(a == parent[a]){
		return a;
	}
	return parent[a] = findPar(parent[a], parent);
}

void union(int u, int v, vector<int> &parent, vector<int> &rank){
	u = findPar(u, parent);
	v = findPar(v, parent);

	if(rank[u] < rank[v]){
		parent[u] = v;
	}
	else if(rank[v] < rank[u]){
		parent[v] = u;
	}
	else{
		parent[u] = v;
		rank[v]++;
	}
}




int main(){
	int N, m;
	cin>>N>>m;
	vector<node>edges;

	for(int i=0; i<m; i++){
		int u, v, wt;
		cin>>u>>v>>wt;
		edges.push_back(node(u, v, wt));
	} 

	sort(edges.begin(), edges.end(), comp)

	vector<int> parent(N);

	for(int i=0; i<N; i++){
		parent[i] = i;
	}
	vector<int> rank(N, 0);
	int cost = 0;
	vector<pair<int, int>>mst;
	for(auto it:edges){, 
		if(findPar(it.v, parent) != findPar(it.u, parent)){
			cost += it.wt;
			mst.push_back({it.u, it.v});
			union(it.u, it.v, parent, rank);
		}
	}


	return 0;
}