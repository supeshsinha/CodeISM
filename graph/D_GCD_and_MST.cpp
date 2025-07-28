#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> par;
vector<int> rnk;

void make_set(int n){
    rnk.assign(n+1,1);
    par.resize(n+1);
    for(int i=0; i<=n; i++) par[i] = i;
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

    if(rnk[x] > rnk[y]){
        par[y] = x;
        rnk[x] += rnk[y];
    }
    else{
        par[x] = y;
        rnk[y] += rnk[x];
    }
}



void solve(){
    int n, p;
    cin>>n>>p;

    make_set(n);
    vector<int> a(n);
    vector<pair<int,int>> b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i] = {a[i], i};
    }

    vector<bool> vis(n,0);
    sort(b.begin(), b.end());

    int ans = 0;
    int comp = n;

    for(int i=0; i<n && b[i].first<p; i++){
        int u = b[i].first;
        int ind = b[i].second;
        for(int k = b[i].second+1; k<n && a[k]%u == 0; k++){
            if(find_set(ind) != find_set(k)){
                union_set(ind, k);
                ans += u;
                comp--;
            }
            if(vis[k]) break;
            vis[k] = 1;
        }
        for(int k = b[i].second-1; k>=0 && a[k]%u == 0; k--){
            if(find_set(ind) != find_set(k)){
                union_set(ind, k);
                ans += u;
                comp--;
            }
            if(vis[k]) break;
            vis[k] = 1;
        }
    }
    ans += ((comp-1)*p);
    cout<<ans<<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
