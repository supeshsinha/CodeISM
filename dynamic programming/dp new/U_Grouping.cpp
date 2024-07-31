#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n;
int a[16][16];
vector<int> dp;

int score(int mask){
    if(__builtin_popcount(mask) == 1) return 0;

    if(dp[mask]!= -1e18) return dp[mask];

    dp[mask] = 0;
    for(int i =0; i<n; i++){
        if((1<<i) & mask)for(int j= i+1; j<n; j++) if((1<<j) & mask) dp[mask] += a[i][j];
    }

    for(int i = (mask-1)&mask; i>0; i = (i-1)&mask){
        dp[mask] = max(dp[mask], score(i)+ score(mask^i));
    }

    return dp[mask];
}

int32_t main(){
    cin>>n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];

    dp.assign(1<<n,-1e18);

    cout<<score((1<<n)-1);

}
