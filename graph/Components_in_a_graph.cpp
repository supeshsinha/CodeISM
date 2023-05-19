#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> par(2*15001);
vector<int> ranks(2*15001);

void make_set(int n){
    for(int i=0; i<n;i++){
        ranks[i] = 1;
        par[i] = i;
    }
}

int find_set(int x){
    if(x==par[x]) return x;

    par[x] = find_set(par[x]);
    return par[x];
}

void union_set(int a, int b){
    int x = find_set(a);
    int y = find_set(b);

    if(x == y) return;

    if(ranks[x]>ranks[y]){
        par[y] = x;
        ranks[x] += ranks[y];
    }
    else{
        par[x] = y;
        ranks[y] += ranks[x];
    }
}

int32_t main(){
    int m;
    cin>>m;
    int n = 2*15001;
    make_set(n);
    int u,v;
    while(m--){
        cin>>u>>v;
        union_set(u,v);
    }
    int mina = 1e18;
    int maxa = 1;
    for(int i=1;i<n;i++){
        int size = ranks[find_set(i)];
        maxa = max(maxa, size);
        if(size>1) mina = min(mina, size);

    }
    cout<<mina<<" "<<maxa<<endl;

    return 0;
}
