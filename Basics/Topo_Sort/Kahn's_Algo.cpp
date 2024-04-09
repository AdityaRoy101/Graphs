
#include <bits/stdc++.h>
using namespace std;
typedef int ll;

void toposort_dfs(ll node, ll E, vector<ll> adj[], vector<ll> &visArr, stack<ll> &st){
	
	visArr[node] = 1;
	
	for(auto it : adj[node]){
		if(!visArr[it]){
			toposort_dfs(it, E, adj, visArr, st);
		}
	}
	
	st.push(node);
	return;
}


stack<ll> runner(ll V, ll E, vector<ll> adj[]){
	
	
	vector<ll> visArr(V+1, 0);
	stack<ll> st;
	
	// For multiple component graph
	for(ll i=0;i<V;i++){
		if(!visArr[i]){
			toposort_dfs(i, E, adj, visArr, st);
		}
	}
	return st;
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
		
		stack<ll> st = runner(V, E, adj);
		
		while(!st.empty()){
			ll node = st.top();
			st.pop();
			cout<<node<<" ";
		}
			
	}
	
	return 0;
}