#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


vector<int> cost,pages;
vector<vector<int>> dp(1001,vector<int>(100001,0));


int main(){
    
    int n,x;
    cin>>n>>x;
    cost.resize(n+1);
    pages.resize(n+1);

    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=1;i<=n;i++) cin>>pages[i];

    for(int i=1; i<=n; i++){
        for(int j=1 ; j<=x; j++){
            dp[i][j] = dp[i-1][j];
            if(cost[i]<=j) dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + pages[i]);
        }
    }
    cout<<dp[n][x]<<endl;


    return 0;
}
