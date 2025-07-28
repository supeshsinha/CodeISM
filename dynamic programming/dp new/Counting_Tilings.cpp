#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

const int mod = 1e9+7;
vector<vector<vector<int>>> dp;
int n,m;

int ways(int ind, int mask, int si){
    #define ll long long
class Solution {
public:
    vector<int>kmp(string s) {
        int n = s.size();
        vector<int>pi(n);
        pi[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[j] != s[i])
            {
                j = pi[j - 1];
            }
            if (s[j] == s[i])pi[i] = j + 1;
            else pi[i] = 0;
        }
        return pi;
    }

    int minStartingIndex(string s, string pat) {
        int n = s.size();
        int len = pat.size();
        vector<int> pi = kmp(pat);

        vector<pair<ll,ll>> dp(n,{0,0});
        if(s[0]==pat[0]) dp[0] = {1,1};
        else dp[0] = {0,1};

        for(int i=1; i<n; i++){
            if(s[i]== pat[dp[i-1].second]) dp[i].second = dp[i-1].second + 1;
            if(s[i]== pat[dp[i-1].first]) dp[i].first = dp[i-1].first + 1;
            else{
                if(s[i]==pat[pi[dp[i-1].first-1]+1]) dp[i].first = pi[dp[i-1].first]+1;
                else dp[i].first = 0;
                dp[i].second = max(dp[i].second, dp[i-1].first+1);
            }
            if(dp[i].first == len || dp[i].second==len) return i-len+1;
        }
        return -1;
    }
};

} 

int32_t main(){
    
    cin>>n>>m;

    dp.assign(m, vector<vector<int>>(1<<n, vector<int>(n+1, -1)));

    cout<<ways(0,0,0)<<endl;

    return 0;
}
