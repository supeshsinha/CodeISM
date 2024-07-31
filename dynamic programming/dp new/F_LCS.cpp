#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    string s,t;
    cin>>s>>t;
    int n1 = s.length();
    int n2 = t.length();
    s = "1"+s;
    t = "1"+t;

    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
    vector<int> par(n1+1,-1);

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans="";

    int i=n1;
    int j= n2;

    while(i>0 && j>0){
        if(s[i] == t[j]){
            ans+= s[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;

    }

    for(int k = ans.size()-1; k>=0; k--) cout<<ans[k];
    cout<<endl;

    return 0;
}
