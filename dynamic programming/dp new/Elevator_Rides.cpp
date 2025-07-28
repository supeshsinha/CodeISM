#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

pair<int,int> better(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first) return a;
    else if(b.first < a.first) return b;
    else if(a.second > b.second) return a;
    else return b;
}

int32_t main(){
    int n,x;
    cin>>n>>x;
    vector<int> w(n);

    for(int i=0; i<n; i++) cin>>w[i];

    vector<pair<int,int>> dp((1<<n), {INT_MAX, 0});

    dp[0] = {0,0};
    for(int i=1; i<(1<<n); i++){
        for(int j=0; j<n; j++) if((1<<j) & i){
            auto temp = dp[i^(1<<j)];
            if(temp.second >= w[j]) temp.second -= w[j];
            else{
                temp.first++;
                temp.second = x-w[j];
            }
            dp[i] = better(dp[i], temp);
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;

    return 0;
}
