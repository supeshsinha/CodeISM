#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<pair<int,int>>> adj;
//int dp[101][101][2][26];
vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>>(101, vector<vector<int>>(2,vector<int>(26,-1))));

int win(int i, int j, int turn, int mina){
    if(dp[i][j][turn][mina] != -1) return dp[i][j][turn][mina];
    int ans;
    if(turn){
        ans = 0;
        for(auto ch: adj[i]){
            if(ch.second < mina) continue;
            if(win(ch.first,j,0,ch.second)) ans = 1;
        }
    }
    else{
        ans = 1;
        for(auto ch: adj[j]){
            if(ch.second < mina) continue;
            if(win(i,ch.first, 1, ch.second) == 0) ans=0;
        }
    }
    return dp[i][j][turn][mina] = ans;
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        char c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c-'a'});
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<< ((win(i,j,1,0)) ? "A" : "B");
        }
        cout<<endl;
    }


    return 0;
}
