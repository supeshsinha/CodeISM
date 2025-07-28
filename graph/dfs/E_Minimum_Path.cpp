#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;



int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>  adj(n+1);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    vector<vector<vector<int>>> dist(n+1, vector<vector<int>>(2, vector<int>(2, 1e18)));
    
    priority_queue<pair<pair<int,int>, pair<int,int>>, vector<pair<pair<int,int>, pair<int,int>>>, greater<pair<pair<int,int>, pair<int,int>>>> pq;

    dist[1][0][0] = 0;
    
    pq.push({{0, 1}, {0, 0}});

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.first.second;
        int add = p.second.first;
        int sub = p.second.second;
        if(dist[u][add][sub] < p.first.first) continue;

        for(auto ch: adj[u]){
            int v = ch.second;
            int w = ch.first;

            if(dist[v][add][sub] > dist[u][add][sub] + w){
                dist[v][add][sub] = dist[u][add][sub] + w;
                pq.push({{dist[v][add][sub], v}, {add, sub}});
            }
            if(add == 0 && sub == 0 && dist[v][1][1] > dist[u][0][0] + w){
                dist[v][1][1] = dist[u][0][0] + w;
                pq.push({{dist[v][1][1], v}, {1, 1}});
            }
            if(add == 0 && dist[v][1][sub] > dist[u][0][sub] + 2*w){
                dist[v][1][sub] = dist[u][0][sub] + 2*w;
                pq.push({{dist[v][1][sub], v}, {1, sub}});
            }
            if(sub == 0 && dist[v][add][1] > dist[u][add][0]){
                dist[v][add][1] = dist[u][add][0];
                pq.push({{dist[v][add][1], v}, {add, 1}});
            }
            
        }
    }

    for(int i=2; i<=n; i++) cout<<dist[i][1][1]<<" ";
    cout<<endl;


    return 0;
}
