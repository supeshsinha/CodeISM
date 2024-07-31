#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> h;
vector<vector<int>> dp;

int solve(int i, int row){
    if(i==0) return h[0][row];

    if(dp[i][row] != -1) return dp[i][row];

    dp[i][row] = max(solve(i-1,1-row)+h[i][row], solve(i-1,row));
    return dp[i][row];
}

int32_t main(){
    int n;
    cin>>n;
    h.assign(n,vector<int>(2));
    dp.assign(n,vector<int>(2,-1));
    for(int i=0;i<n;i++){
        cin>>h[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>h[i][1];
    }

    cout<<max(solve(n-1,0), solve(n-1,1))<<endl;

    return 0;
}
