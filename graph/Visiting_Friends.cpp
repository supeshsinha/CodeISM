#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> g;
vector<vector<int>> rg;
vector<vector<int>> scg;
vector<bool> vis;
vector<int> order;
vector<int> people;
vector<int> scid;
vector<int> dp;

void dfs1(int node){

    vis[node] = 1;
    for(auto ch : g[node]){
        if(!vis[ch]) dfs1(ch);
    }
    order.push_back(node);
    return;
}

void dfs2(int node, int scc){
    vis[node] = 1;
    scid[node] = scc;
    for(auto ch : rg[node]){
        if(!vis[ch]){
            dfs2(ch,scc);
        }
    }
}

void dfs(int node){
    vis[node] = 1;
    int maxa = 0;
    for(auto ch: scg[node]){
        if(!vis[ch]){
            dfs(ch);
        }
        maxa = max(maxa,dp[ch]);
    }
    dp[node] += maxa;
    
}

int32_t main(){
    int n,m;
    cin>>n;
    cin>>m;
    people.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>people[i];
    g.resize(n+1);
    rg.resize(n+1);
    scid.assign(n+1,0);
    vis.assign(n+1,0);
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }
    vis.assign(n+1,0);
    reverse(order.begin(), order.end());
    int scc = 1;
    for(auto p : order){
        if(!vis[p]){
            dfs2(p,scc);
            scc++;
        }
    }
    scg.resize(scc);

    dp.assign(scc,0);

    for(int i=1 ;i<=n; i++){
        for(auto ch : g[i]){
            if(scid[i] != scid[ch]){
                scg[scid[i]].push_back(scid[ch]);
            }
        }
        dp[scid[i]] += people[i];
    }
    vis.assign(scc,0);
    for(int i=1; i<scc; i++){
        if(!vis[i]) dfs(i);
    }
    
    for(int i=1; i<=n; i++){
        cout<<dp[scid[i]]<<" ";
    }
    cout<<endl;

    return 0;
}
