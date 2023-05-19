#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> par;
vector<int> ranks;
int cost = 0;

void make_set(int n){
    for(int i=1; i<=n;i++){
        ranks[i] = 1;
        par[i] = i;
    }
}

int find_set(int x){
    if(x==par[x]) return x;

    par[x] = find_set(par[x]);
    return par[x];
}

void union_set(int a, int b, int c){
    int x = find_set(a);
    int y = find_set(b);

    if(x == y) return;

    cost += c;

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
    int n,m;
    cin>>n>>m;
    par.resize(n+1);
    ranks.resize(n+1);
    make_set(n);

    vector<pair<int,pair<int,int>>> edges(m);

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edges[i] = {c,{a,b}};
    }

    sort(edges.begin(), edges.end());

    for(int i=0;i<m;i++){
        c = edges[i].first;
        a = edges[i].second.first;
        b = edges[i].second.second;

        union_set(a,b,c);
    }
    if(ranks[find_set(1)]<n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else cout<<cost<<endl;



    return 0;
}
