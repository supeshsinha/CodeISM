#include<bits/stdc++.h>
#define int long long
using namespace std;
int N;
int minimumcost(int height[],int n, int k, vector<int> &memo){
    if(n == 2){
        return abs(height[0]-height[1]);
    }
    if(n==1) return 0;

    if (memo[N-n]!= -1) return memo[N-n];
    int mincost= INT_MAX;
    for(int i=1; i<=k && i<n; i++){
        int cost = abs(height[i]- height[0]) + minimumcost(height+i,n-i,k,memo);
        if(cost<mincost) mincost = cost;
    }
    memo[N-n] = mincost;
    return mincost;

}

 

int32_t main(){
    int n,k;
    cin>>n>>k;
    N=n;
    int * height = new int[n];
    vector <int> memo(n,-1);
    for(int i=0;i<n;i++) cin>>height[i];

    cout<< minimumcost(height,n,k,memo)<<endl;

    delete [] height;


    return 0;
}