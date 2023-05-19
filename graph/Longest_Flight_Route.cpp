#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<int> par;

void dfs(int node){

    for(auto ch : adj[node]){
        if(dist[ch]<dist[node]+1){
            dist[ch] = dist[node] + 1;
            par[ch] = node;
            dfs(ch);
        }
    }
    return;
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    int temp = m;
    int u,v;
    adj.resize(n+1);
    dist.assign(n+1,-1);
    par.assign(n+1,-1);
    while(temp--){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    dist[1] = 0;
    dfs(1);

    if(dist[n] == -1) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<dist[n]+1<<endl;
        vector<int> ans;
        int temp = n;
        while(par[temp]!= -1){
            ans.push_back(par[temp]);
            temp = par[temp];
        }
        for(int i = ans.size()-1; i>=0; i--){
            cout<<ans[i]<<" ";
        }
        cout<<n<<endl;
    }

    return 0;
}
