#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> wt;
vector<int> dp;
int n,W;

int trips(int mask){
    

    if(dp[mask] != -1) return dp[mask];
    if(mask == 0) return 0;



    dp[mask] = INT_MAX;
    for(int i = mask; i>0; i = (i-1)&mask){
        if(wt[i] <= W) dp[mask] = min(dp[mask], trips(mask^i)+1); 
    }
    return dp[mask];
}

int main(){
    
    cin>>n>>W;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    wt.assign(1<<n,0);
    dp.assign(1<<n,-1);

    for(int i=0; i<(1<<n); i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) sum+= p[j];
        }
        wt[i] = sum;
    }

    cout<< trips((1<<n)-1)<<endl;

    return 0;
}
