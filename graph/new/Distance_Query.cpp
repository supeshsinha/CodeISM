#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct kth{
    int par;
    int maxa;
    int mina;
};

vector<vector<pair<int,int>>> adj; 
vector<vector<int>> par, maxp, minp;
vector<int> level;
int x;

void dfs(int node, int parent){
    level[node] = level[parent] + 1;
    par[node][0] = parent;

    for(auto ch: adj[node]){
        if(ch.first == parent) continue;
        int v = ch.first;
        int w = ch.second;
        maxp[v][0] = w;
        minp[v][0] = w;
        par[v][0] = node;
        for(int j=1; j<=x; j++){
            par[v][j] = par[par[v][j-1]][j-1];
            maxp[v][j] = max(maxp[v][j-1], maxp[par[v][j-1]][j-1]);
            minp[v][j] = min(minp[v][j-1], minp[par[v][j-1]][j-1]);
        }
        dfs(v, node);
    }

}

kth find_kth(int u, int k){
    int maxa = 0;
    int mina = 1e18;

    for(int j=x; j>=0; j--){
        if(k & (1<<j)){
            maxa = max(maxa, maxp[u][j]);
            mina = min(mina, minp[u][j]);
            u = par[u][j];
        }
    }
    return {u, maxa, mina};
}

int lca(int a, int b){
    if(level[a]>level[b]) swap(a,b);
    int d = level[b] - level[a];
    b = find_kth(b, d).par;
    if(a==b) return a;

    for(int j=x; j>=0; j--){
        if(par[a][j] != par[b][j]){
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);

    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    x = log2(n) + 1;

    par.resize(n+1, vector<int>(x+1));
    maxp.resize(n+1, vector<int>(x+1));
    minp.resize(n+1, vector<int>(x+1));
    level.assign(n+1,0);

    maxp[1][0] = 0;
    minp[1][0] = 1e18;

    dfs(1, 1);

    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<=x; j++) cout<<minp[i][j]<<" ";
    //     cout<<endl;
    // }

    int q;
    cin>>q;

    while(q--){
        int a, b;
        cin>>a>>b;
        int c = lca(a,b);
        // cout<<c<<endl;
        kth k1 = find_kth(a, level[a]-level[c]);
        kth k2 = find_kth(b, level[b]-level[c]);
        // cout<<k1.par<<" "<<k1.mina<<" "<<k1.maxa<<endl;
        // cout<<k2.par<<" "<<k2.mina<<" "<<k2.maxa<<endl;

        cout<<min(k1.mina, k2.mina)<<" "<<max(k1.maxa, k2.maxa)<<endl;
    }

    return 0;
}
