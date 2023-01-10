#include<bits/stdc++.h>
#define int long long
using namespace std;


int maxhappy(int arr[][3], int n,int task, int memo[][3]){
    if(n==1) return max(arr[0][0],max(arr[0][1],arr[0][2]));
    if(n==0) return 0;

    if(memo[n][task]!= 0) return memo[n][task];

    int temp = -1;
    for(int i=0;i<3;i++){
        if(i==task) continue;
        temp = maxhappy(arr,n-1,i,memo) + arr[n-1][task];
        memo[n][task] = max(memo[n][task],temp);
    }
    return memo[n][task];

    
}

int32_t main(){

    int n;
    cin>>n;
    int arr[n][3];
    int memo[n+1][3] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int ans = -1;
    for(int i=0;i<3;i++){
        int temp = maxhappy(arr,n,i,memo);
        if(temp>ans) ans = temp;
    }
    cout<< ans<<endl;


    return 0;
}