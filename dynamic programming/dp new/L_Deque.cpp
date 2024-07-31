#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> a;
vector<vector<vector<int>>> dp;

int optimal(int i, int j, int turn){
    if(i>j) return 0;

    if(dp[i][j][turn] != -1) return dp[i][j][turn];

    if(turn == 0){
        dp[i][j][turn] = max(optimal(i+1,j,1)+a[i], optimal(i,j-1,1)+a[j]);
    }
    else dp[i][j][turn] = min(optimal(i+1,j,0)-a[i], optimal(i,j-1,0)-a[j]);

    return dp[i][j][turn];
}


int32_t main(){
    
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; i++) cin>>a[i];

    dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));

    cout<< optimal(0,n-1,0)<<endl;


    return 0;
}
