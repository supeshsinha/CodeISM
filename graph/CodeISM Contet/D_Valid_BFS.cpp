#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> height;
vector<int> par;

void dfs(int node, int parent){
    par[node] = parent;
    for(auto ch : adj[node]){
        if(ch == parent) continue;
        height[ch] = height[node] + 1;
        dfs(ch, node);
    }
}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    height.assign(n+1,0);
    par.assign(n+1,-1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    vector<int> a(n);
    vector<bool> vis(n+1,0);
    for(int i=0; i<n; i++) cin>>a[i];
    if(n==1){
        cout<<"YES"<<endl;
        exit(0);
    }
    vis[a[0]] = 1;
    for(int i=1; i<n; i++){
        if(height[a[i]] < height[a[i-1]] || vis[a[i]]){
            cout<<"NO"<<endl;
            exit(0);
        }
        vis[a[i]] = 1;
    }
    if(a[0] != 1){
        cout<<"NO"<<endl;
            exit(0);
    }
    vector<int> sbfs;
     if(par[a[n-1]] != -1) sbfs.push_back(par[a[n-1]]);
    for(int i=n-2; i>=0; i--){
        if(par[a[i]] == sbfs[sbfs.size()-1]) continue;
        if(par[a[i]] != -1) sbfs.push_back(par[a[i]]);
    }
    reverse(sbfs.begin(), sbfs.end());

    for(int i=0; i<sbfs.size(); i++){
        if(sbfs[i] != a[i]){
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    cout<<"YES"<<endl;


    return 0;
}
