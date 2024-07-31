#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n;
vector<int> a;
vector<vector<int>> dp;
const int mod = 1e9+7;

// int ways(int i,int k){
//     if(i==n+1 && k>0) return 0;
//     if(k==0 || i==n+1) return 1;
    

//     if(dp[i][k] != -1) return dp[i][k];

//     dp[i][k] = 0;
//     for(int j=0; j<=a[i]; j++) if(j<=k){
//         dp[i][k] += ways(i+1,k-j);
//         if(dp[i][k]>=mod) dp[i][k] -= mod;
//     }

//     return dp[i][k];
// }

int32_t main(){
    int k;
    cin>>n>>k;
    a.resize(n+1);
    dp.assign(n+1,vector<int>(k+1,0)); 

    for(int i=1; i<=n; i++) cin>>a[i];

    if(k==0){
        cout<<1<<endl;
        return 0;
    }

    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int j=0; j<=k; j++) dp[0][j] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j] - (((j-a[i]-1)<0) ? 0 : dp[i-1][j-a[i]-1]);
            dp[i][j] = (dp[i][j] + mod)%mod;
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    
    cout<<(dp[n][k]-dp[n][k-1]+mod)%mod<<endl;


    return 0;
}
