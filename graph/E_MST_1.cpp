#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> par;
vector<int> ranks;


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

struct edge{
    int u;
    int v;
    bool query;
    int index;
};

int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    par.resize(n+1);
    ranks.resize(n+1);
    make_set(n);
    vector<bool> ans(q,0);

    vector<pair<pair<int,int>,pair<int,int>>> edges(m+q);

    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        // edges[i] = {c,{a,b}};
        edges[i].first.first = c;
        edges[i].second.first = a;
        edges[i].second.second = b;
        edges[i].first.second = -1;
    }

    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        // edges[i] = {c,{a,b}};
        edges[m+i].first.first = c;
        edges[m+i].second.first = a;
        edges[m+i].second.second = b;
        edges[m+i].first.second = i;
    }

    sort(edges.begin(), edges.end());

    for(int i=0;i<m+q;i++){
        a = edges[i].second.first;
        b = edges[i].second.second;
        int index = edges[i].first.second;
        if(index != -1){
            if(find_set(a) != find_set(b)){
                ans[index] = 1;
            }
        }
        else{
            union_set(a,b);
        }
    }
    for(int i=0;i<q;i++){
        if(ans[i] == 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }



    return 0;
}
