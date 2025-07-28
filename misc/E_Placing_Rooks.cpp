#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

const int mod = 998244353;

int bepower(int a, int b){
    if(b==0) return 1;
    int x = bepower(a, b/2);
    x = (x*x)%mod;
    if(b%2) x = (x*a)%mod;
    return x;
}

vector<int> fact;
int ncr(int n, int r){
    return (fact[n]*((bepower(fact[r], mod-2) * bepower(fact[n-r], mod-2))%mod))%mod;
}


int32_t main(){
    int n,k;
    cin>>n>>k;

    fact.resize(n+1);
    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = (fact[i-1]*i)%mod;

    
    if(k>=n){
        cout<<0<<endl;
        return 0;
    }
    int m = n-k;
    int ans = 0;
    
    for(int i=0; i<m; i++){
        if(i%2) ans = ((ans - ncr(m,i)*bepower(m-i,n))%mod + mod)%mod;
        else ans = (ans + ncr(m,i)*bepower(m-i,n))%mod;
    }

    ans = (ans * ncr(n,k))%mod;
    if(k>0) ans = (ans*2)%mod;

    cout<<ans<<endl;
    return 0;
}
