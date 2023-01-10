#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    vector<bool> seive(1e6+1,1);
    seive[0]=seive[1]=0;
    for(int i=2; i*i<=1e6;i++){
        if(seive[i]){
            for(int multiple = i*i ; multiple <= 1e6; multiple += i)seive[multiple]=0;
        }
    }

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int root = sqrt(x);
        if(root*root==x && seive[root]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }





    return 0;
}