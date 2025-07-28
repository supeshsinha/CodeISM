#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n,x;
vector<int> w;
vector<pair<int,int>> dp;

pair<int,int> better(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first) return a;
    else if(b.first < a.first) return b;
    else if(a.second > b.second) return a;
    else return b;
}

pair<int,int> minrides(int mask){
    if(mask == 0) return {0,0};
    if(dp[mask].first != -1) return dp[mask];

    dp[mask] = {INT_MAX, 0};
    for(int i=0; i<n; i++){
        if((1<<i) & mask){
            auto temp = minrides(mask^(1<<i));
            if(temp.second >= w[i]) temp.second -= w[i];
            else temp = {temp.first+1, x-w[i]};
            dp[mask] = better(dp[mask], temp);
        }
    }
    return dp[mask];
}

int32_t main(){
    cin>>n>>x;
    w.resize(n);
    dp.assign((1<<n), {-1,-1});
    for(int i=0; i<n; i++) cin>>w[i];
    
    cout<<minrides((1<<n)-1).first<<endl;

    //for(int i=0; i<(1<<n); i++) cout<<i<<" "<<dp[i].first<<" "<<dp[i].second<<endl;

    return 0;
}
