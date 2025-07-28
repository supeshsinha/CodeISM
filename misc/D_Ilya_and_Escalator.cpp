#include<bits/stdc++.h>
#define int long long
#define ld long double
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

void solve(){
    int n,t;
    ld p;
    cin>>n>>p>>t;

    vector<vector<ld>> dp(n+1, vector<ld>(t+1,0));
    dp[0][0] = 1;

    for(int j=1; j<=t; j++) dp[0][j] = dp[0][j-1]*(1-p);

    for(int i=1; i<=n; i++) for(int j=1; j<=t; j++){
        dp[i][j] = dp[i-1][j-1]*p;
        if(i==n) dp[i][j] += dp[i][j-1];
        else dp[i][j] += (dp[i][j-1]*(1-p));
    }
    ld ans = 0;
    for(int i=0; i<=n; i++) ans += (dp[i][t]*i);
    cout<<fixed<<setprecision(8)<<ans<<endl;
}

int32_t main(){
    int t=1;

    while(t--){
        solve();
    }

    return 0;
}
