#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int ans = -1;
    int index = -1;
    int temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(temp<m && ans<temp){
            ans = temp;
            index = i;
        }
    }
    cout<<index<<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
