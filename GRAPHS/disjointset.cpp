#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[100000];

void makeSet(int n){
	for(int i=0 ; i<n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

int findPar(int node){
	if(node == parent[node]){
		return node;
	}
	return parent[node] = findPar(parent[node]);
}

void union(int u, int v){
	u = findPar(u);
	v = findPar(v);

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
	int m;
	cin>>m;
	int n;
	cin>>n;
	makeSet(n);
	while(m--){
		int u, v;
		cin>>u>>v;
		union(u, v);
	}
	

	return 0;
}