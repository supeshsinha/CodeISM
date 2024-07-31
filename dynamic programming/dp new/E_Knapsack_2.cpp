#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    int n,w;
    cin>>n>>w;
    vector<int> wt(n+1);
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin>>wt[i]>>v[i];

    vector<vector<int>> dp(2,vector<int>(1e5+1,1e18));

    for(int i=0; i<=n;i++) dp[i%2][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j= 1; j<=1e5; j++){
            dp[i%2][j] = dp[(i-1)%2][j];
            if(j>=v[i]) dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j-v[i]] + wt[i]);
        }
    }
    for(int i=1e5; i>=0; i--) if(dp[n%2][i] <= w){
        cout<<i<<endl;
        return 0;
    }
    cout<<0<<endl;

    return 0;
}
