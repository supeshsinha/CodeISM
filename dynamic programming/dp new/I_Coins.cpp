#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<double>> dp;
vector<double>p;

double prob(int n, int h){
    if(h==0) return 1;
    if(n==0) return 0;

    if(dp[n][h] != -1) return dp[n][h];

    dp[n][h] = p[n]*prob(n-1,h-1) + (1-p[n])*prob(n-1,h);
    return dp[n][h];
}

int32_t main(){
    int n;
    cin>>n;
    dp.assign(n+1,vector<double>(n/2+2,-1));
    p.assign(n+1,0);
    for(int i=1; i<=n;i++) cin>>p[i];

    cout<<fixed<<setprecision(10)<<prob(n,n/2+1)<<endl;

    return 0;
}
