#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n;
vector<int> a;
vector<vector<int>> dp(1e5+1,vector<int>(2,-1));

int winner(int k, int turn){
    if(k<0) return turn;

    if(dp[k][turn] != -1) return dp[k][turn];

    for(int i=0; i<n; i++){
        if(winner(k-a[i],1-turn) == turn) return dp[k][turn] = turn;
    }

    return dp[k][turn] = 1-turn;
}

int32_t main(){
    int k;
    cin>>n>>k;
    a.resize(n);

    for(int i=0; i<n;i++) cin>>a[i];

    cout<< (winner(k,0) ? "Second" : "First") << endl;

    return 0;
}
