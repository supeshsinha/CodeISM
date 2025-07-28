#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n,m;
vector<int> a;
vector<int> b;

int operations(int level){
    int ans = 0;
    for(int i=0; i<n; i++) if(level > a[i]) ans += (level-a[i]);
    for(int i=0; i<m; i++) if(level < b[i]) ans += (b[i]-level);
    return ans;
}

int32_t main(){
    cin>>n>>m;
    a.resize(n);
    b.resize(m);
    int mina = 1e18;
    int maxb = -1;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mina = min(mina, a[i]);
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
        maxb = max(maxb, b[i]);
    }

    if(mina >= maxb){
        cout<<0<<endl;
        return 0;
    }

    int hi = maxb;
    int lo = mina;

    while(hi-lo >= 3){
        int mid1 = lo + (hi-lo)/3;
        int mid2 = hi - (hi-lo)/3;

        int fmid1 = operations(mid1);
        int fmid2 = operations(mid2);

        if(fmid1 < fmid2) hi = mid2;
        else if(fmid1 > fmid2) lo = mid1;
        else{
            hi = mid2;
            lo = mid1;
        }
    }
    int ans = 1e18;

    for(int i=lo; i<=hi; i++){
        ans = min(ans, operations(i));
    }
    cout<<ans<<endl;

    return 0;
}
