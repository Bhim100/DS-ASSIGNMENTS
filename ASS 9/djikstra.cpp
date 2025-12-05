    #include <bits/stdc++.h>
    using namespace std;

    vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int source) {
        set<pair<int,int>> st;
        vector<int> dist(n+1, INT_MAX);

        dist[source] = 0;
        st.insert({0, source});

        while(!st.empty()) {
            auto it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(st.begin());

            for (auto &p : adj[node]) {
                int adjNode = p.first;
                int wt = p.second;

                if(d + wt < dist[adjNode]) {
                    // remove old record if exists
                    if(dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // update distance
                    dist[adjNode] = d + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
