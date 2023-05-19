#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

const int mod = 1e9+7;

vector<vector<int>> g;
vector<vector<int>> rg;
vector<vector<int>> scg;
vector<int> vis;
vector<int> scid;
vector<int> order;

int bipower(int n,int p){
    if(p==0) return 1;

    int res = bipower(n,p/2);

    int ans = (res*res)%mod;

    if(p%2 == 1){
        ans = (ans * n)%mod;
    }

    return ans;
}

void dfs1(int node){
    vis[node] = 1;
    for(auto ch : g[node]){
        if(!vis[ch]) dfs1(ch);
    }
    order.push_back(node);
    return;
}

void dfs2(int node, int scc){
    vis[node]=1;
    scid[node]=scc;
    for(auto ch: rg[node]){
        if(!vis[ch]){
            dfs2(ch,scc);
        }
    }
    return;
}

void solve(){
    int m,n;
    cin>>m>>n;

    //reset graphs
    g.clear();
    g.resize(n+1);
    rg.clear();
    order.clear();
    rg.resize(n+1);
    vis.assign(n+1,0);
    scid.assign(n+1,-1);
    //

    int u,v;
    for(int i=0;i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    for(int i=1;i<=n;i++) dfs1(i);

    reverse(order.begin(), order.end());
    
    vis.assign(n+1,0);
    int scc = 1;

    for(auto p: order){
        if(!vis[p]){
            dfs2(p,scc);
            scc++;
        }
    }

    scg.clear();
    scg.resize(scc);
    
    vector<int> nodesnum(scc,0);
    vector<int> outdeg(scc,0);

    for(int i=1;i<=n;i++){
        nodesnum[scid[i]]++;
        for(auto ch: g[i]){
            if(scid[i] != scid[ch]){
                scg[scid[i]].push_back(scid[ch]);
                outdeg[scid[i]]++;
            }
        }        
    }

    int ans = 1;

    for(int i=1; i<scc; i++){
        if(outdeg[i] == 0){
            ans = (ans * (bipower(2,nodesnum[i])-1))%mod;
        }
        else{
            ans = (ans * bipower(2,nodesnum[i]))%mod;
        }
    }

    cout<<ans<<endl;
    return;

}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
