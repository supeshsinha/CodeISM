#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


vector<int> par,ranks;
int ans = 0;
int c =0;

void make_set(int n){
    for(int i=1;i<=n;i++){
        par[i] = i;
        ranks[i] = 1;
    }
}

int find_set(int x){
    if(par[x] == x) return x;

    par[x] = find_set(par[x]);
    return par[x];
}

void union_set(int a, int b, int weight){
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
    ans += weight;
    c++;
}


void solve(){
    int n,p;
    cin>>n>>p;
    par.resize(n+1);
    ranks.resize(n+1);
    ans = 0;
    c=0;
    make_set(n);
    vector<int> a(n+1);
    vector<pair<int,int>> as;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        as.push_back({a[i],i});
    } 

    sort(as.begin(),as.end());

    for(int i = 0; as[i].first<p && i<n; i++){
        int ind = as[i].second;
        int j = ind + 1;
        while(j<=n && a[j]%a[ind] == 0){
            if(find_set(j) == find_set(ind)) break;
            union_set(j,ind,a[ind]);
            j++;
        }
        j = ind - 1;
        while(j>0 && a[j]%a[ind] == 0){
            if(find_set(j) == find_set(ind)) break;
            union_set(j,ind,a[ind]);
            j--;
        }
        if(c == n-1) break;
    }
    ans += (n-1 -c)*p;

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
