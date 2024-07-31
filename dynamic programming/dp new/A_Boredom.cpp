#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> freq(1e5+1,0);

vector<int> dp(1e5+1,-1);

int maxpoints(int i){
    if(i<1) return 0;
    if(freq[i] == 0) return maxpoints(i-1);
    
    if(dp[i]!= -1) return dp[i];
    if(freq[i-1] == 0){
        dp[i] = i*freq[i] + maxpoints(i-2);
        return dp[i];
    }
    dp[i] = max(i*freq[i] + maxpoints(i-2), maxpoints(i-1));
    return dp[i];
}


int32_t main(){
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        freq[temp]++;
    }
    cout<<maxpoints(1e5)<<endl;
    
    return 0;
}
