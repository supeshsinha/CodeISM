#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> par;
vector<int> ranks;

int numcomp;
int largest = 1;


void make_set(int n){
    for(int i=1;i<=n;i++){
        par[i] = i;
        ranks[i] = 1;
    }
    return;
}

int find_set(int x){
    if(x == par[x]) return x;

    par[x] = find_set(par[x]);
    return par[x];
}

void union_set(int a, int b){
    int x = find_set(a);
    int y = find_set(b);

    if(x==y) return;

    numcomp--;
    if(ranks[x]>ranks[y]){
        par[y] = x;
        ranks[x] += ranks[y];
        largest = max(largest,ranks[x]);
    }
    else{
        par[x] = y;
        ranks[y] += ranks[x];
        largest = max(largest,ranks[y]);
    }
}


int32_t main(){
    int n,m;
    cin>>n>>m;
    numcomp = n;
    par.resize(n+1);
    ranks.resize(n+1);

    make_set(n);
    int u,v;
    while(m--){
        cin>>u>>v;
        union_set(u,v);
        cout<<numcomp<<" "<<largest<<endl;
    }

}
