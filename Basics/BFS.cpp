// Distinct Subsequences| (DP-32)
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

vector<ll> bfs(ll V, ll E, vector<ll> adj[]){
	
	vector<ll> ans;
	vector<ll> visArr(V+1, 0);
	queue<ll> q;
	
	// 0 based Indexing && initial Config
	visArr[0] = 1;
	q.push(0);
	
	while(!q.empty()){
		int node = q.front();
		ans.push_back(node);
		q.pop();
		
		for(auto it : adj[node]){
			if(!visArr[it]){
				visArr[it] = 1;
				q.push(it);
			}
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
		
		vector<ll> ans = bfs(V, E, adj);
		for(auto it : ans){
			cout<<it<<" ";
		}
			
	}
	
	return 0;
}