#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

const int mod = 1e9+7;
vector<vector<pair<int,int>>> adj;
vector<int> xorr;

void dfs(int node, int par){

    for(auto ch : adj[node]){
        if(ch.first != par){
            xorr[ch.first] = xorr[node] ^ ch.second;
            dfs(ch.first,node);
        }
    }
    return;
}


int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    xorr.resize(n+1);
    xorr[1] = 0;

    int u,v,w;
    for(int i=1; i<n;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,-1);
    vector<int> bits(63,0);

    for(int i=1; i<=n ;i++){
        for(int j=0; j<=62; j++){
            if(xorr[i] & 1ll << j) bits[j]++;
        }
    }
    int ans = 0;
    for(int j=0; j<=62; j++){
        ans += (((bits[j]*(n-bits[j]))%mod)*((1ll << j)%mod))%mod;
        ans %= mod;
    }
    cout<<ans<<endl;

    return 0;
}
