#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;



int32_t main(){
    int n,w;
    cin>>n>>w;
    vector<int>p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    sort(p.begin(), p.end(), greater<int>());
    vector<bool> sent(n,0);

    int c = 0;
    int ans = 0;
    while(c != n){
        int balance = w;
        ans++;
        for(int i=0; i<n; i++){
            if(!sent[i] && p[i]<= balance){
                c++;
                sent[i] = 1;
                balance -= p[i];
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}
