#include <bits/stdc++.h>
using namespace std;

int prims(int n, vector<vector<pair<int,int>>> &adj) {

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> visited(n+1,0);
    pq.push({0,1});

    int mstWeight = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;
        visited[node]= 1;
        mstWeight+= wt;

        for(auto &p :adj[node]){
            int adjNode = p.first;
            int adjWt   = p.second;

            if(!visited[adjNode]){
                pq.push({adjWt, adjNode});
            }
        }
    }

    return mstWeight;
}

int main() {
    int n = 5;

    vector<vector<pair<int,int>>> adj(n+1);

    
    adj[1].push_back({2,5});
    adj[2].push_back({1,5});

    adj[1].push_back({3,3});
    adj[3].push_back({1,3});

    adj[2].push_back({3,4});
    adj[3].push_back({2,4});

    adj[2].push_back({4,6});
    adj[4].push_back({2,6});

    adj[3].push_back({5,2});
    adj[5].push_back({3,2});

    adj[4].push_back({5,7});
    adj[5].push_back({4,7});

    cout << "MST Weight = " << prims(n, adj) << "\n";
}
