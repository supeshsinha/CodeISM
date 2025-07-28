#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int dp[20][2][11][2];

int solve(string &s, int ind, int tight, int prev, int occured){
    if(ind == s.length()) return 1;
    if(dp[ind][tight][prev][occured] != -1) return dp[ind][tight][prev][occured];

    int ans = 0;
    if(tight){
        for(int i=0; i<s[ind]-'0'; i++){
            if(i == prev && (occured)) continue;
            ans += solve(s, ind+1, 0, i, (i || occured ? 1:0));
        }
        if((s[ind]-'0' != prev) || (occured==0)) ans += solve(s, ind+1, 1, s[ind]-'0', ((s[ind]-'0')|| occured?1:0));
    }
    else{
        for(int i=0; i<=9; i++){
            if(i== prev && occured) continue;
            ans += solve(s, ind+1, 0, s[ind]-'0', (i || occured ? 1:0));
        }
    }
    return dp[ind][tight][prev][occured] = ans;
}

int32_t main(){
    int l,r;
    cin>>l>>r;

    memset(dp, -1, sizeof(dp));

    string rs = to_string(r);
    int ans = solve(rs, 0, 1, 10, 0);

    memset(dp, -1, sizeof(dp));

    if(l>0){
        string ls = to_string(l-1);
        ans -= solve(ls, 0, 1, 10, 0);
    }

    cout<<ans<<endl;


    return 0;
}
