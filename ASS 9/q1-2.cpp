#include <bits/stdc++.h>
using namespace std;

void bfs( vector <vector<int>> &adj,int n){

    vector<int> visited={0};
    queue<int > q;

    visited[0]=1;
    q.push(0);   

    while(q.empty()){
        int front=q.front();
        q.pop();
        cout << front<<"     " ;

        for (int neigh : adj[front]) {
        if (!visited[neigh]) {
            visited[neigh] = 1; 
            q.push(neigh);
        }
        }
    }

}  

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    cout <<node<< "    ";

    for (int neigh: adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }
    }
}


