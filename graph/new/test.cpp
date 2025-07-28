#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> b;
    for(int i=0;i<n; i++){
        b.push_back(a[i]);
        b.push_back(a[n-1-i]);
    }
    vector<bool> deleted(2*n,0);

    for(int i=0; i<2*n-1; i++){
        int par1 = __builtin_popcount(b[i])%2;
        int par2 = __builtin_popcount(b[i+1])%2;

        if(par1 == par2){
            deleted[i] = 1;
            deleted[i+1] = 1;
        }
    }

    for(int i=0; i<2*n; i++) if(!deleted[i]) cout<<b[i]<<" ";
    cout<<endl;


    return 0;
}
