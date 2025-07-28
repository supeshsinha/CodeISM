#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;



int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    adj.resize(n+1);

    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n+1,-1);

    queue<int> q;
    par[1] = 0;
    q.push(1);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(par[v]==-1){
                par[v] = u;
                q.push(v);
            }
        }
    }
    if(par[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    stack<int> ans;
    int temp = n;
    while(temp != 0){
        ans.push(temp);
        temp = par[temp];
    }

    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;

    return 0;
}
