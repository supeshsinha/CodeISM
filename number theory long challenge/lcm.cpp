#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int b;
    cin>>b;
    int ans = 0;

    for(int i=1; i*i<=b; i++){
        if(b%i == 0){
            ans++;
            if(i*i != b) ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}