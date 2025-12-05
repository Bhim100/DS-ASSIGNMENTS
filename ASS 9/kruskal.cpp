#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> rank,parent,size;

    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if (node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void UnionbyRank(int u,int v){

        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v; 
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }

    void UnionbySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
    }
}
};

int main(){
    int n= 5;

    vector<pair<int, pair<int,int>>> edges = {
        {5, {1,2}},
        {3, {1,3}},
        {4, {2,3}},
        {6, {2,4}},
        {2, {3,5}},
        {7, {4,5}}
    };

    
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mstWeight = 0;

    cout << "Edges in MST:\n";

    
    for(auto &e : edges){
        int wt = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if(dsu.findUPar(u) != dsu.findUPar(v)){
            mstWeight += wt;
            cout << u <<"-" << v << ": " << wt << endl;
            dsu.UnionbySize(u, v);
        }
    }

    cout<< "Total MST Wt::"<< mstWeight<< endl;
}