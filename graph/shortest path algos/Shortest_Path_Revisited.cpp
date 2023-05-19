#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<vector<int>> dist;
int n,m,k;

void dijkastra(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    dist[1][0] = 0;
    pq.push({0,{1,0}});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int node = p.second.first;
        int skipped = p.second.second;
        if(p.first>dist[node][skipped]) continue;
        for(auto ch : adj[node]){
            int child = ch.second;
            int wt = ch.first;
            if(dist[child][skipped]> p.first + wt){
                dist[child][skipped] = p.first + wt;
                pq.push({dist[child][skipped],{child,skipped}});
            }
            if(skipped + 1 <= k && dist[child][skipped+1]> p.first){
                dist[child][skipped+1] = p.first;
                pq.push({dist[child][skipped+1],{child, skipped+1}});
            }
        }
    }
    
}

int32_t main(){
    
    cin>>n>>m>>k;
    adj.resize(n+1);
    dist.assign(n+1,vector<int>(19,1e18));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    dijkastra();

    for(int i=1;i<=n; i++){
        int ans = 1e18;
        for(int j=k ; j>=0; j--){
            ans = min(ans,dist[i][j]);
        }
        cout<<ans<<" ";
    }
    cout<<endl;


    return 0;
}
