#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> dist(n+1,1e18);
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    //dijkastra
    priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>> pq;
    pair<pair<int,int>,pair<int,int>> temp;
    temp.first = {0,1};
    temp.second = {0,0};
    pq.push(temp);

    dist[1] = 0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int newdist = p.first.first;
        int node = p.first.second;
        int maxa = p.second.first;
        int mina = p.second.second;
        if(dist[node]< newdist)continue;

        for(auto ch : adj[node]){
            int wt = ch.first;
            int child = ch.second;
            if(node == 1 && dist[child]>wt){
                dist[child] = wt;
                temp.first = {dist[child],child};
                temp.second = {wt,wt};
                pq.push(temp);
            }
            else if(wt>maxa && dist[child]> dist[node] + maxa){
                dist[child] = dist[node] + maxa;
                temp.first = {dist[child],child};
                temp.second = {wt,mina};
                pq.push(temp);
            }
            else if(wt<mina && dist[child]> dist[node] - mina +2*wt){
                dist[child] = dist[node] - mina +2*wt;
                temp.first = {dist[child],child};
                temp.second = {maxa,wt};
                pq.push(temp);
            }
            else if(dist[child]> dist[node] + wt){
                dist[child] = dist[node] + wt;
               temp.first = {dist[child], child};
               temp.second = {maxa, mina};
               pq.push(temp);
            }
        }
    }
    //ends

    for(int i=2; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}
