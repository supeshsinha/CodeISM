#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> a(21,vector<int>(21));
vector<int> dp(1<<21,-1);
int n;
const int mod = 1e9+7;

int ways(int mask){

    int k = __builtin_popcount(mask);

    if(k==n) return 1;
    if(dp[mask] != -1) return dp[mask];

    int ans = 0;
    for(int j=0; j<n; j++){
        if(a[k][j] && !((1<<j)&mask)){
            ans += ways(mask | (1<<j));
            if(ans>=mod) ans -= mod;
        }
    }
    return dp[mask] = ans;

}


int32_t main(){
    
    cin>>n;
    for(int i=0; i<n;i++) for(int j=0; j<n; j++) cin>>a[i][j];

    cout<<ways(0)<<endl;


    return 0;
}
