#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> par;
vector<int> ranks;

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
    int n,q;
    cin>>n>>q;

    par.resize(n+1);
    ranks.resize(n+1);

    make_set(n+1);

    string s;;
    while(q--){
        cin>>s;
        if(s=="M"){
            int a,b;
            cin>>a>>b;
            union_set(a,b);
        }
        else{
            int a;
            cin>>a;
            cout<<ranks[find_set(a)]<<endl;
        }

    }
    

    return 0;
}
