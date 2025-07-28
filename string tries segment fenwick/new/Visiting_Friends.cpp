#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> radj;
vector<vector<int>> sadj;
vector<int> scid;
vector<int> person;
vector<int> order;
vector<bool> vis;

void dfs(int node, vector<vector<int>> &adj){
    vis[node] = 1;
    for(auto ch: adj[node]){
        if(!vis[ch]) dfs(ch, adj);
    }

    order.push_back(node);
}

void dfs1(int node, int scc){
    vis[node] = 1;
    scid[node] = scc;

    for(auto ch: radj[node]) if(!vis[ch]) dfs1(ch, scc);
}


int32_t main(){
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    radj.resize(n+1);
    person.resize(n+1);
    for(int i=1; i<=n; i++) cin>>person[i];

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vis.assign(n+1,0);
    for(int i=1; i<=n; i++) if(!vis[i]) dfs(i, adj);

    reverse(order.begin(), order.end());
    scid.resize(n+1);

    int scc = 1;
    vis.assign(n+1,0);
    for(auto i: order){
        if(!vis[i]){
            dfs1(i, scc);
            scc++;
        }
    }
    //cout<<scc<<endl;

    sadj.resize(scc);
    vector<int> scost(scc, 0);
    for(int i=1; i<=n; i++){
        scost[scid[i]] += person[i];

        for(auto v: adj[i]){
            if(scid[i] != scid[v]) sadj[scid[i]].push_back(scid[v]);
        }
    }

    order.clear();
    vis.assign(scc, 0);

    for(int i=1; i<scc; i++) if(!vis[i]) dfs(i, sadj);

    for(auto u:  order){
        int maxc = 0;
        for(auto v: sadj[u]) maxc = max(maxc, scost[v]);
        scost[u] += maxc;
    }

    for(int i=1; i<=n; i++) cout<<scost[scid[i]]<<" ";
    cout<<endl;

    return 0;
}
