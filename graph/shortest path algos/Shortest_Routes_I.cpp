#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> dist(n+1,1e18);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int wt = p.first;
        int node = p.second;
        if(dist[node]< wt)continue;

        for(auto ch : adj[node]){
            if(dist[ch.second]> dist[node] + ch.first){
                dist[ch.second] = dist[node] + ch.first;
                pq.push({dist[ch.second],ch.second});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}
