#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void bfs(unordered_map<int, vector<int>> adj, int u, vector<bool>& visited, vector<int>& res){
    queue<int> q;
    res.push_back(u);
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int v: adj[node]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                res.push_back(v);
            }
        }
    }
    return;
}

void dfs(unordered_map<int, vector<int>> adj, int u, vector<bool>& visited, vector<int>& res){
    // if(visited[u] == true) return;
    visited[u] = true;
    res.push_back(u);
    for(auto& v : adj[u]){
        if(!visited[v]){
            dfs(adj, v, visited, res);
        }
    }
    return;
}

void solve(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adj;
    for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
  }

  vector<bool> visited(n, false);
  vector<int> result;
  cout << "1. dfs"<< endl << "2. bfs" << endl;
  int choice;
  cin >> choice;
  if(choice == 1) {
      dfs(adj, 0, visited, result);
  } else {
    bfs(adj, 0, visited, result);   
  }
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

}

int main(){
    int n;
    cout << "Enter number of edges: ";
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2, 0));

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    solve(n, edges);
    return 0;
}