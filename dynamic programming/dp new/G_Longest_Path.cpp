#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


vector<vector<int>> adj;
vector<int> indeg;

int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    indeg.assign(n+1,0);
    vector<int> dist(n+1,0);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto ch: adj[node]){
            indeg[ch]--;
            if(indeg[ch] == 0) q.push(ch);

            dist[ch] = max(dist[ch], dist[node]+1);
        }
    }
    int ans = 0;

    for(int i=1; i<=n; i++){
        ans = max(ans,dist[i]);
    }

    cout<<ans<<endl;

    return 0;
}
