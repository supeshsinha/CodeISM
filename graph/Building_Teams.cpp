#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>>adj;
vector<bool>vis;
vector<int>team;

bool dfs(int n, int num){
    vis[n] = 1;
    team[n] = num;
    for(auto ch: adj[n]){
        if(team[ch] == team[n]){
            return false;
        }
        if(!vis[ch]){
            bool possible = dfs(ch, 3 - num);
            if(possible == 0) return false;
        }
    }
    return true;
}


int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,0);
    team.resize(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool possible = dfs(i,1);
            if(!possible){
                cout<<"IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<team[i]<<" ";
    }
    cout<<"\n";

    

    return 0;
}
