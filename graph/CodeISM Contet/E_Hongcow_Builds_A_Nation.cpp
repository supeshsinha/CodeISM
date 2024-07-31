#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> sz;
int edges = 0;
int n;

void dfs(int node){
    vis[node] = 1;
    for(int i=1; i<=n; i++) if(adj[node][i]){
        if(adj[node][i] == 1){
            adj[node][i] = 2;
            adj[i][node] = 2;
            edges++;
        }
        if(!vis[i]){
            dfs(i);
            sz[node] += sz[i];
        }
    }
}


int32_t main(){
    int m,k;
    cin>>n>>m>>k;
    vis.assign(n+1,0);
    sz.assign(n+1,1);
    adj.assign(n+1, vector<int>(n+1,0));
    vector<int> capital(k);
    for(int i=0; i<k; i++) cin>>capital[i];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int ans = 0;
    int maxk = 1;

    for(int i=0; i<k; i++){
        edges = 0;
        dfs(capital[i]);
        int nodes = sz[capital[i]];
        maxk = max(maxk, nodes);
        ans += ((nodes*(nodes-1))/2 - edges);
    }
    vector<int> wc;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            edges = 0;
            dfs(i);
            int nodes = sz[i];
            wc.push_back(nodes);
            ans += ((nodes*(nodes-1))/2 - edges);
        }
    }
    wc.push_back(maxk);

    for(int i = wc.size()-1; i>=0; i--){
        for(int j = 0; j<i; j++) ans += (wc[i]*wc[j]);
    }
    cout<<ans<<endl;

    return 0;
}
