#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> intime, outtime;
int n,x;
int timer = 0;

void dfs(int node, int par){
    intime[node] = timer++;

    up[node][0] = par;
    for(int j=1; j<=x; j++){
        up[node][j] = up[up[node][j-1]][j-1];
    }

    for(auto ch : adj[node]){
        if(ch == par) continue;
        dfs(ch,node);
    }
    outtime[node] = timer++;
}

int kthpar(int node, int k){
    for(int i=x; i>=0; i--){
        if(k & (1ll << i)) node = up[node][i];
    }
    return node;
}

bool isAncestor(int an, int node){
    return intime[an] <= intime[node] && outtime[an] >= outtime[node];
}

int lca(int a, int b){
    if(isAncestor(a,b)) return a;
    if(isAncestor(b,a)) return b;

    for(int i=x; i>=0; i--){
        if(!isAncestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}



int32_t main(){
    
    int q;
    cin>>n>>q;
    x = log2(n) + 1;
    adj.resize(n+1);
    intime.assign(n+1,0);
    outtime.assign(n+1,0);
    up.assign(n+1,vector<int>(x+1));
    int temp;
    for(int i=2; i<=n;i++){
        cin>>temp;
        adj[i].push_back(temp);
        adj[temp].push_back(i);
    }
    up[1][0] = 1;

    dfs(1,1);

    int a1,b1;
    while(q--){
        cin>>a1>>b1;
        cout<<lca(a1,b1)<<endl;
    }

    return 0;
}
