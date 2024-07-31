#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> h;
vector<vector<int>> dp;

int solve(int i, int row){
    if(i==0) return h[0][row];

    if(dp[i][row] != -1) return dp[i][row];

    dp[i][row] = max(solve(i-1,(row+1)%3), solve(i-1,(row+2)%3)) + h[i][row];
    return dp[i][row];
}

int32_t main(){
    int n;
    cin>>n;
    h.assign(n,vector<int>(3));
    dp.assign(n,vector<int>(3,-1));
    for(int i=0; i<n;i++) for(int j=0; j<3; j++) cin>> h[i][j];

    cout<<max(solve(n-1,0), max(solve(n-1,1), solve(n-1,2)))<<endl;

    return 0;
}
