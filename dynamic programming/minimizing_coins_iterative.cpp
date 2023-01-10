#include<bits/stdc++.h>
#define int long long
using namespace std;

vector <int> dp(1e6+1,-1);


int32_t main(){

    int n,x;
    cin>>n>>x;
    vector <int> coins(n);

    for(int i =0; i<n; i++) cin >> coins[i];

    
    dp[0] = 0;
    for (int i = 1; i<=x; i++){
        int ans = INT_MAX;
        for(int j = 0; j<coins.size(); j++){
            if(i>=coins[j]){
                ans = min(ans, dp[i - coins[i]] +1);
            }
        }
        dp[i]=ans;
    }

    if(dp[x] == INT_MAX) cout<< -1<< endl;
    else cout << dp[x] << endl;



    return 0;
}