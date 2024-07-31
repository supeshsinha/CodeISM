#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
int a,b;

pair<int, pair<bool,bool>> dfs(int node){
    vis[node] = 1;
    bool pa = 0;
    bool pb = 0;
    int num = 1;

    for(auto ch: adj[node]){
        if(ch == a) pa = 1;
        if(ch == b) pb = 1;
        if(vis[ch]) continue;
        auto cha = dfs(ch);
        pa |= cha.second.first;
        pb |= cha.second.second;
        num += cha.first;
    }
    return {num, {pa,pb}};

}

void solve(){
    int n,m;
    cin>>n>>m>>a>>b;
    adj.clear();
    adj.resize(n+1);
    vis.assign(n+1,0);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[a] = 1;
    vis[b] = 1;
    int ansa = 0;
    int ansb = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            auto p = dfs(i);
            if(p.second.first && !p.second.second) ansa += p.first;
            if(!p.second.first && p.second.second) ansb += p.first;
        }
    }
    cout<< ansa*ansb <<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
