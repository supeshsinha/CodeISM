#include<bits/stdc++.h>
#define int long long
using namespace std;

int height[2][100000+1];

vector<vector<int>> dp(1e5+1,vector<int>(2,-1));


int max_height(int i,int row){
    if(i==1) return height[row][1];

    if(dp[i][row]!= -1) return dp[i][row];

    dp[i][row] = max(max_height(i-1,1-row)+height[row][i], max_height(i-1,row));

    return dp[i][row];

}


int32_t main(){
    int n;
    cin>>n;
    for(int i=1; i<=n;i++) cin>>height[0][i];
    for(int i=1; i<=n;i++) cin>>height[1][i];

    cout<<max(max_height(n,0),max_height(n,1))<<endl;

    return 0;
}