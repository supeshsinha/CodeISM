#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<string> a;
int h,w;
vector<vector<int>> dp;
const int mod = 1e9+7;

int ways(int i, int j){
    if(i==h-1 && j==w-1) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 0;
    if(j+1 < w && a[i][j+1] =='.') dp[i][j] += ways(i,j+1);
    if(i+1 < h && a[i+1][j] =='.') dp[i][j] += ways(i+1,j);
    if(dp[i][j]>=mod) dp[i][j] -= mod;

    return dp[i][j];
}


int32_t main(){
    cin>>h>>w;
    dp.assign(h,vector<int>(w,-1));
    a.resize(h);
    for(int i=0; i<h; i++) cin>>a[i];

    cout<<ways(0,0)<<endl;

    return 0;
}
