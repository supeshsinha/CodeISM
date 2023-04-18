#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int x = arr[0]*arr[n-1];
    for(int i=0; i<=(n-1)/2; i++){
        if (arr[i]*arr[n-1-i]!=x){
            cout<<"-1"<<endl;
            return;
        }
    }
    int c = 0;
    for(int i = 2; i*i<=x; i++){
        if(x%i == 0){
            c++;
            if((i*i)!=x) c++;
        }
    }
    if(c!=n){
        cout<<"-1"<<endl;
        return;
    }
    cout << x<<endl;
    return;
}

int32_t main(){
    int t;
    cin>> t;
    while(t){
        solve();
        t--;
    }
}
