// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

void dfs(ll node, vector<ll> adj[], vector<ll>&visArr, vector<ll>&ans){
	
	visArr[node] = 1;
	ans.push_back(node);
		
	for(auto it : adj[node]){
		if(!visArr[it]){
			dfs(it, adj, visArr, ans);
		}
	}
	return;
}

vector<ll> runner(ll V, ll E, vector<ll> adj[]){
	
	vector<ll> ans;
	vector<ll> visArr(V+1, 0);
	
	// For Multiple Component graph
	for(ll i=0;i<V;i++){
		if(!visArr[i]){
			dfs(i, adj, visArr, ans);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		
		// Number of Nodes
		ll V;
		V = 5;
		
		// Number of Edges
		ll E;
		E = 4;
		
		// Adjacency List
		vector<ll> adj[] = {{1,2,3},{},{4},{},{}};
		
		vector<ll> ans = runner(V, E, adj);
		for(auto it : ans){
			cout<<it<<" ";
		}
			
	}
	
	return 0;
}
