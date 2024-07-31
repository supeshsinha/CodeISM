#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> intime,outtime,dist;
vector<vector<int>> up;
int x, counter = 0;

void dfs(int node, int par){
    intime[node] = counter++;

    up[node][0] = par;
    for(int j=1; j<=x; j++){
        up[node][j] = up[up[node][j-1]][j-1];
    }

    for(auto ch: adj[node]){
        if(ch != par){
            dist[ch] = dist[node] + 1;
            dfs(ch,node);
        }
    }
    outtime[node] = counter++;
}

int kthances(int node, int k){
    for(int i=x; i>=0; i--){
        if(k & (1ll << i)) node = up[node][i];
    }
    return node;
}

int isAncestor(int an, int node){
    return intime[an]<= intime[node] && outtime[an] >= outtime[node];
}

int lca(int a, int b){
    if(isAncestor(a,b)) return a;
    if(isAncestor(b,a)) return b;

    for(int i=x; i>=0; i--){
        if(!isAncestor(up[a][i],b)) a = up[a][i];
    }
    return up[a][0];
}


int32_t main(){
    int n,q;
    cin>>n>>q;
    x= log2(n)+1;
    adj.resize(n+1);
    intime.assign(n+1,0);
    outtime.assign(n+1,0);
    dist.assign(n+1,0);
    up.assign(n+1,vector<int>(x+1));
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<dist[a] + dist[b] - 2*dist[lca(a,b)]<<endl;
    }
    

    return 0;
}
