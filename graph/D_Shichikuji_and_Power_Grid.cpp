#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


vector<int> par,ranks,k;
vector<pair<int,int>> cordi;

void make_set(int n){
    for(int i=0;i<=n;i++){
        par[i] = i;
        ranks[i] = 1;
    }
}

int find_set(int x){
    if(par[x] == x) return x;

    par[x] = find_set(par[x]);
    return par[x];
}

void union_set(int a, int b){
    int x = find_set(a);
    int y = find_set(b);
    if(x==y) return;

    if(ranks[x]>ranks[y]){
        par[y] = x;
        ranks[x] += ranks[y];
    }
    else{
        par[x] = y;
        ranks[y] += ranks[x];
    }
}

int weight(int u, int v){
    return (k[u]+k[v])*(abs(cordi[u].first - cordi[v].first) + abs(cordi[u].second - cordi[v].second));
}


int32_t main(){
    int n;
    cin>>n;
    par.resize(n+1);
    ranks.resize(n+1);
    cordi.resize(n+1);
    k.resize(n+1);
    vector<int> c(n+1);
    make_set(n);
    int x1,y1;
    for(int i=1; i<=n;i++){
        cin>>x1>>y1;
        cordi[i] = {x1,y1};
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    vector<pair<int,pair<int,int>>> edges;
    for(int i=1; i<=n; i++){
        edges.push_back({c[i],{0,i}});
    }
    for(int i=1; i<=n-1; i++){
        for(int j = i+1; j<=n; j++){
            edges.push_back({weight(i,j),{i,j}});            
        }
    }
    sort(edges.begin(),edges.end());

    vector<int> ans1;
    vector<pair<int,int>> ans2;
    int cost = 0;

    for(auto e : edges){
        int u = e.second.first;
        int v = e.second.second;
        if(find_set(u) == find_set(v)) continue;

        union_set(u,v);
        cost += e.first;
        if(u == 0){
            ans1.push_back(v);
        }
        else{
            ans2.push_back({u,v});
        }
    }

    cout<<cost<<endl;
    cout<<ans1.size()<<endl;
    for(auto a : ans1) cout<<a<<" ";
    cout<<endl;
    cout<<ans2.size()<<endl;
    for(auto &b : ans2) cout<<b.first<<" "<<b.second<<endl;


    return 0;
}
