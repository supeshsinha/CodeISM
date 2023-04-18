#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


vector<bool> vis;
vector<vector<int>> adj;

void dfs(int n){
    vis[n] = 1;
    for( auto child : adj[n]){
        if(!vis[child]){
            dfs(child);
        }
    }
}


int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,0);
    vector<pair<int,int>> new_roads;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for(int i=2; i<=n; i++){
        if(!vis[i]){
            new_roads.push_back({i-1,i});
            dfs(i);
        }
    }
    cout<<new_roads.size()<<endl;
    for(int j=0 ;j<new_roads.size(); j++){
        cout<<new_roads[j].first<<" "<<new_roads[j].second<<endl;
    }


    return 0;
}
