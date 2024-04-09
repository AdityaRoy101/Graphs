
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

vector<ll> toposort_bfs(ll V, ll E, vector<ll> adj[]){
	
	vector<ll> ans;
	
	// Indegree Array
	vector<ll> indegree(V+1, 0);
	
	
	for(ll i=0;i<V;i++){
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	
	queue<ll> q;
	
	// Initial Config
	for(ll i=0;i<V;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		ll node = q.front();
		q.pop();
		
		ans.push_back(node);
		for(auto it : adj[node]){
			
			// Relaxing the edges
			indegree[it]--;
			if(indegree[it] == 0){
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
		
		vector<ll> ans = toposort_bfs(V, E, adj);
		for(auto it : ans){
			cout<<it<<" ";
		}
			
	}
	
	return 0;
}