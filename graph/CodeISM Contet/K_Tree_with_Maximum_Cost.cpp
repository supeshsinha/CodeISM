#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> value, cost, sum;
vector<vector<int>> adj;
int ans = 0;

void dfs(int node, int par){
    sum[node] = value[node];

    for(auto ch: adj[node]){
        if(ch == par) continue;
        dfs(ch, node);
        cost[node] += (cost[ch] + sum[ch]);
        sum[node] += sum[ch];
    }
}

void dfs1(int node, int par){
    ans = max(ans, cost[node]);

    for(auto ch: adj[node]){
        if(ch == par)continue;
        cost[node] -= (cost[ch] + sum[ch]);
        sum[node] -= sum[ch];
        cost[ch] += (cost[node] + sum[node]);
        sum[ch] += sum[node];

        dfs1(ch, node);

        sum[ch] -= sum[node];
        cost[ch] -= (cost[node] + sum[node]);
        sum[node] += sum[ch];
        cost[node] += (cost[ch] + sum[ch]);
    }
}


int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    value.resize(n+1);
    sum.resize(n+1);
    cost.assign(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>value[i];
    }
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    dfs1(1,-1);
    cout<<ans<<endl;


    return 0;
}
