#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n;
vector<int> coin;
vector<int> dp;
const int mod = 1e9+7;

// Recursive Way
// int ways(int x){
//     if(x==0) return 1;
//     if(x<0) return 0;

//     if(dp[x] != -1) return dp[x];

//     dp[x]= 0;
//     for(int i=0; i<n;i++){
//         dp[x] += ways(x-coin[i]);
//         if(dp[x]>=mod) dp[x] -= mod;
//     }

//     return dp[x];
// }


int main(){
    int x;
    cin>>n>>x;
    coin.resize(n);
    dp.assign(x+1,0);

    for(int i=0;i<n;i++) cin>>coin[i];
    // Iterative
    dp[0] = 1;

    for(int i=1; i<=x; i++){
        for(int j=0; j<n;j++){
            if(coin[j]<= i){
                dp[i] += dp[i-coin[j]];
                if(dp[i]>=mod) dp[i] -= mod;
            }
        }
    }

    cout<<dp[x]<<endl;

    return 0;
}
