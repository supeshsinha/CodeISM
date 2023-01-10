#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,temp;
    int ans =1;
    cin>>n;
    vector<int> freq(1e5+1,0);
    vector<bool> seive(1e5+1,1);
    for(int i = 0; i<n ; i++){
        cin>>temp;
        freq[temp]++;
    }

    for(int i =2;i<=1e5;i++){
        int count = 0;
        if(seive[i]==0) continue;
        for(int multiple = i; multiple<=1e5; multiple+=i){
            seive[multiple] = 0;
            count += freq[multiple];
        }
        ans = max(ans,count);
    }

    cout<<ans<<endl;

    
    return 0;
}