#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    vector<vector<int>> dist(n+1,vector<int>(2,1e18));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    dist[1][0] = 0;
    dist[1][1] = 0;
    pq.push({0,{1,0}});

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int node = p.second.first;
        int discused = p.second.second;
        if(dist[node][discused] < p.first) continue;
        for(auto ch : adj[node]){
            int wt = ch.first;
            int child = ch.second;
            if(!discused){
                if(dist[child][0]> dist[node][0] + wt){
                    dist[child][0] = dist[node][0] + wt;
                    pq.push({dist[child][0],{child,0}});
                }
                if(dist[child][1]>dist[node][0] + wt/2){
                    dist[child][1] = dist[node][0] + wt/2;
                    pq.push({dist[child][1],{child,1}});
                }
            }
            else{
                if(dist[child][1]> dist[node][1] + wt){
                    dist[child][1] = dist[node][1] + wt;
                    pq.push({dist[child][1],{child,1}});
                }
            }

        }
    }
    cout<<dist[n][1]<<endl;

    return 0;
}
