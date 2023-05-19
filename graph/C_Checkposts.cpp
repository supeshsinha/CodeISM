#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> g;
vector<vector<int>> rg;
vector<bool> vis;
vector<int> order;
vector<int> scid;
const int mod = 1e9+7;

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

int32_t main(){
    int n,m;
    cin>>n;
    vector<int> cost(n+1,0);
    for(int i=1;i<=n;i++) cin>>cost[i];
    g.resize(n+1);
    rg.resize(n+1);
    scid.assign(n+1,0);
    vis.assign(n+1,0);
    cin>>m;
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

    vector<pair<int,int>> mini(scc,{1e18,1});

    for(int i=1; i<=n; i++){
        if(cost[i]< mini[scid[i]].first){
            mini[scid[i]].first = cost[i];
            mini[scid[i]].second = 1;
        }
        else if(cost[i] == mini[scid[i]].first){
            mini[scid[i]].second++;
        }
    }

    int mincost = 0;
    int ways = 1;
    
    for(int i=1; i<scc; i++){
        mincost += mini[i].first;
        ways = (ways*mini[i].second)%mod;
    }

    cout<<mincost<<" "<<ways<<endl;

    return 0;
}
