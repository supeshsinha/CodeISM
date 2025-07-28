#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    vector<vector<bool>> dp(n, vector<bool>(m+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;
    dp[0][a[0]] = 1;
    for(int i=1; i<n; i++) for(int j=0; j<=m; j++){
        if(j + a[i] <= m && dp[i-1][j]) dp[i][j+a[i]] = 1;
        dp[i][j] = dp[i-1][j];
    }

    vector<bool> steps(m+1,0);
    vector<int> used;

    steps[m] = 1;
    for(int i=n-1; i>0; i--){
        for(int j=0; j<=m; j++){
            if(steps[j] && j-a[i]>=0 && dp[i-1][j-a[i]]){
                if(used.empty() || used.back()!= a[i]) used.push_back(a[i]);
                steps[j-a[i]] = 1;
            }
        }
    }
    if(steps[a[0]]) used.push_back(a[0]);

    n = used.size();

    dp.assign(n, vector<bool>(m+1, 0));

    for(int i=0; i<n; i++) dp[i][0] = 1;
    dp[0][used[0]] = 1;
    for(int i=1; i<n; i++) for(int j=0; j<=m; j++){
        if(j + used[i] <= m && dp[i-1][j]) dp[i][j+used[i]] = 1;
        dp[i][j] = dp[i-1][j];
    }


    vector<int> ans;
    for(int j=0; j<=m; j++) if(dp[n-1][j]) ans.push_back(j);

    cout<<ans.size()<<endl;
    for(auto ch: ans) cout<<ch<<" ";
    cout<<endl;


    return 0;
}
