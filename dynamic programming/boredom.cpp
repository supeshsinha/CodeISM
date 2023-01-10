#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

    int n;
    cin>>n;
    int temp, largest =0;
    vector <int> freq(1e5+1,0);
    for( int i=0; i<n; i++){
        cin>>temp;
        largest = max(largest,temp);
        freq[temp]++;
    }

    vector <int> dp(largest+1,0);
    vector <int> max_taken(largest+1,0);

    dp[1]= freq[1];
    if(freq[1] != 0) max_taken[1] = 1;

    for(int i=2; i<=largest; i++){
        if(freq[i]==0){
            dp[i] = dp[i-1];
            max_taken[i] = max_taken[i-1];
            continue;
        }
        if(max_taken[i-1] != i-1){
            dp[i] = dp[i-1] + i*freq[i];
        }
        else{
            dp[i] = max(dp[i-1], i*freq[i] + dp[i-2]);
        }

        if(dp[i] != dp[i-1]) max_taken[i] = i;
        else max_taken[i] = max_taken[i-1];
    }

    cout<< dp[largest] <<endl;

    return 0;
}