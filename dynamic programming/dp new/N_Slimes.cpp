#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> a;
vector<vector<int>> dp;

int mincost(int i, int j){
    if(i==j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 1e18;
    for(int k=i; k<j; k++){
        dp[i][j]= min(dp[i][j], mincost(i,k)+ mincost(k+1,j)+ a[j]-a[i-1]);
    }
    return dp[i][j];
}


int32_t main(){
    int n;
    cin>>n;
    a.resize(n+1);
    dp.assign(n+1,vector<int>(n+1,-1));
    a[0] = 0;
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        a[i] = a[i-1]+temp;
    }

    cout<<mincost(1,n)<<endl;


    return 0;
}
