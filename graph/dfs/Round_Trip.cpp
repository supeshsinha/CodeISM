#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<int> par;
vector<bool> black;

pair<int,int> dfs(int n){

    for(auto ch: adj[n]){
        if(dist[ch] && !black[ch] && dist[n]-dist[ch] >= 2){
            return {n,ch};
        }
        else if(!dist[ch]){
            dist[ch] = dist[n] + 1;
            par[ch] = n;
            pair<int,int>p = dfs(ch);
            if(p.first != -1) return p;
        }
        
    }
    black[n] = 1;
    return {-1,-1};
}


int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    dist.assign(n+1,0);
    par.assign(n+1,0);
    black.assign(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool  flag = 0;
    for(int i=0;i<n;i++){
        if(!dist[i]){
            dist[i] = 1;
            pair<int,int>p = dfs(i);
            if(p.first != -1){
                int n = p.first;
                int ch = p.second;
                cout<<dist[n]-dist[ch] + 2<<endl;
                cout<<ch<<" ";
                while(n != ch){
                    cout<<n<<" ";
                    n= par[n];
                }
                cout<<ch<<endl;
                flag = 1;
                break;
            }
        }
    }
    if(!flag) cout<<"IMPOSSIBLE"<<endl;


    return 0;
}
