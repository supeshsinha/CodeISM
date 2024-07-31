#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> cost,pages;
map<int,int, greater<int>> dp;

// int maxpages(int n, int x){
//     if(n==0 || x==0) return 0;
    

//     if(dp[n][x]) return dp[n][x];

//     dp[n][x] = maxpages(n-1, x);
//     if(cost[n]<=x) dp[n][x] = max(dp[n][x], pages[n] + maxpages(n-1, x-cost[n]));

//     return dp[n][x];

// }

int32_t main(){
    int n,x;
    cin>>n>>x;
    cost.resize(n+1);
    pages.resize(n+1);
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=1;i<=n;i++) cin>>pages[i];
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(auto it = dp.begin(); it != dp.end(); it++){
            int newcost = it->first + cost[i];
            if(newcost > x) continue;
            int newpage = it->second + pages[i];
            auto newit = dp.find(newcost);
            if(newit == dp.end()) dp[newcost] = newpage;
            else newit->second = max(newit->second, newpage);
        }
    }
    int maxa = 0;
    for(auto m : dp) if(m.first <= x) maxa = max(maxa, m.second);

    cout<<maxa<<endl;


    return 0;
}
