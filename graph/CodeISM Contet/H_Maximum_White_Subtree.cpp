#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> color;
vector<vector<int>> adj;
vector<int> maxa;
vector<int> ans;

void dfs(int node, int par){
    if(color[node]) maxa[node] = 1;
    else maxa[node] = -1;
    for(auto ch: adj[node]){
        if(ch == par) continue;
        dfs(ch, node);
        if(maxa[ch] > 0) maxa[node] += maxa[ch];
    }
}

void dfs1(int node, int par){
    ans[node] = maxa[node];

    for(auto ch: adj[node]){
        if(ch == par) continue;
        if(maxa[ch]>0) maxa[node] -= maxa[ch];
        if(maxa[node]>0) maxa[ch] += maxa[node];
        dfs1(ch,node);
        if(maxa[node]>0) maxa[ch] -= maxa[node];
        if(maxa[ch]>0) maxa[node] += maxa[ch];
    }
}

int32_t main(){
    int n;
    cin>>n;
    color.resize(n+1);
    adj.resize(n+1);
    maxa.assign(n+1,0);
    ans.assign(n+1,0);
    for(int i=1; i<=n; i++) cin>> color[i];

    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    dfs1(1,-1);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
