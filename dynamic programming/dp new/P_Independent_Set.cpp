#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> black;
vector<int> white;

const int mod = 1e9+7;

void dfs(int node, int par){

    for(auto ch: adj[node]){
        if(ch == par) continue;
        dfs(ch,node);

        black[node] *= white[ch];
        black[node] %= mod;
        white[node] *= (black[ch] + white[ch])%mod;
        white[node] %= mod;
    }
}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    black.assign(n+1,1);
    white.assign(n+1,1);
    int u,v;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);

    cout<<(black[1]+white[1])%mod<<endl;

    return 0;
}
