#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<vector<int>> up ,mina, maxa;
vector<int> intime, outtime, level;
int n,x;
int timer = 0;

void dfs(int node, int par){
    intime[node] = timer++;

    up[node][0] = par;
    for(int j=1; j<=x; j++){
        up[node][j] = up[up[node][j-1]][j-1];
    }
    

    for(auto ch : adj[node]){
        if(ch.first == par) continue;

        up[ch.first][0] = node;
        mina[ch.first][0] = ch.second;
        maxa[ch.first][0] = ch.second;

        for(int j=1; j<=x; j++){
            up[ch.first][j] = up[up[ch.first][j-1]][j-1];
            mina[ch.first][j] = min(mina[ch.first][j-1], mina[up[ch.first][j-1]][j-1]);
            maxa[ch.first][j] = max(maxa[ch.first][j-1], maxa[up[ch.first][j-1]][j-1]);
        }

        level[ch.first] = level[node] + 1;
        dfs(ch.first,node);
    }
    outtime[node] = timer++;
}

pair<int,int> kthpar(int node, int k){
    int maxp = -1;
    int minp = 1e18;
    for(int i=x; i>=0; i--){
        if(k & (1ll << i)){
            maxp = max(maxp, maxa[node][i]);
            minp = min(minp, mina[node][i]);
            node = up[node][i];
        }
    }
    return {minp,maxp};
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
    
    cin>>n;
    x = log2(n) + 1;
    adj.resize(n+1);
    intime.assign(n+1,0);
    outtime.assign(n+1,0);
    level.assign(n+1,0);
    up.assign(n+1,vector<int>(x+1,1));
    mina.assign(n+1,vector<int>(x+1,1e18));
    maxa.assign(n+1,vector<int>(x+1,-1));
    int t1,t2,w;
    for(int i=2; i<=n;i++){
        cin>>t1>>t2>>w;
        adj[t1].push_back({t2,w});
        adj[t2].push_back({t1,w});
    }

    dfs(1,1);

    int q;
    cin>>q;
    int a1,b1;
    while(q--){
        cin>>a1>>b1;
        int la = lca(a1,b1);
        pair<int,int> p1 = kthpar(a1, level[a1]-level[la]);
        pair<int,int> p2 = kthpar(b1, level[b1]-level[la]);
        int ansmin = min(p1.first, p2.first);
        int ansmax = max(p1.second, p2.second);
        cout<<ansmin<<" "<<ansmax<<endl;
    }

    return 0;
}
