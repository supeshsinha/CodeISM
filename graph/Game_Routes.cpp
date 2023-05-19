#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
stack<int> order;
vector<bool> vis;

const int mod = 1e9+7;

void dfs(int node){

    vis[node] = 1;
    for(auto ch : adj[node]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
    order.push(node);
}

int32_t main(){

    int n,m;
    cin>>n>>m;
    int u,v;
    adj.resize(n+1);
    vis.assign(n+1,0);
    vector<int> ways(n+1,0);
    int temp = m;
    while(temp--){
        cin>>u>>v;
        adj[u].push_back(v);
    }

    dfs(1);
    ways[1] = 1;

    while(!order.empty()){
        int x = order.top();
        order.pop();
        for(auto ch : adj[x]){
            // ways[ch] = (ways[ch] + ways[x])%mod;
            ways[ch] = ways[ch] + ways[x] < mod ? ways[ch] + ways[x] : ways[ch] + ways[x] -mod;

        }

    }

    cout<<ways[n]<<endl;
    

    return 0;
}
