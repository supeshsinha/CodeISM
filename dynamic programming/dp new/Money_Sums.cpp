#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


void pos(int n, set<int> &ans){
    

}


int main(){
    int n;
    cin>>n;
    vector<int> coin(n);
    for(int i=0;i<n;i++) cin>>coin[i];

    //  Iterative approach
    // vector<bool> dp(1e5+1,0);

    // dp[0] = 1;

    // for(int i=0; i<n; i++){
    //     for(int j= 1e5-coin[i]; j>=0; j--){
    //         if(dp[j]) dp[j+coin[i]] = 1;
    //     }
    // }

    // vector<int> answer;

    // for(int i=1; i<=1e5; i++){
    //     if(dp[i]) answer.push_back(i);
    // }

    // cout<<answer.size()<<endl;
    // for(auto c: answer) cout<<c<<" ";
    // cout<<endl;

    return 0;
}
