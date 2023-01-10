#include<bits/stdc++.h>
#define int long long
using namespace std;

vector <int> dp(1e6+1,-1);

int min_coins(int x, vector <int> &coins){
    if(x==0) return 0;
    if(x<0) return INT_MAX;

    if(dp[x]!= -1) return dp[x];

    int ans = INT_MAX;

    for(int i=0; i< coins.size(); i++) ans = min(ans, min_coins(x - coins[i],coins) +1);

    dp[x] = ans;
    return dp[x];
}


int32_t main(){

    int n,x;
    cin>>n>>x;
    vector <int> coins(n);

    for(int i =0; i<n; i++) cin >> coins[i];

    int ans = min_coins(x,coins);

    if(ans == INT_MAX) cout<< -1<< endl;
    else cout << ans << endl;



    return 0;
}