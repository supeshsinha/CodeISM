#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> h;
vector<int> dp;

int minc(int final){
    if(final == 0) return 0;
    if(final == 1) return abs(h[0]- h[1]);

    if(dp[final]!= -1) return dp[final];

    dp[final] = min(minc(final-1)+abs(h[final]-h[final-1]), minc(final-2)+abs(h[final]- h[final-2]));
    return dp[final];
}

int32_t main(){
    int n;
    cin>>n;
    h.resize(n);
    dp.assign(n,-1);

    for(int i=0;i<n;i++) cin>>h[i];

    cout<<minc(n-1)<<endl;

    return 0;
}
