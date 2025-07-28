#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> odd, small, presum;
int n,m;

int solved(int k){
    int ans;
    if(k%2 == 0) ans = (n-small[k])*k + presum[k] + (small[k]*k - presum[k] - odd[k])/2;
    else ans = (n-small[k])*k + (small[k]*k - presum[k] - (small[k]-odd[k]))/2;
    return ans;
}

int32_t main(){
    
    cin>>n>>m;
    odd.assign(m+1,0);
    small.assign(m+1, 0);
    presum.assign(m+1, 0);

    vector<int> a(n+1);

    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        a[temp]++;
    }

    for(int i=1; i<=n; i++){
        if(a[i]%2) odd[a[i]]++;
        small[a[i]]++;
        presum[a[i]] += a[i];
    }

    for(int i=1; i<=m; i++){
        odd[i] = odd[i] + odd[i-1];
        small[i] = small[i] + small[i-1];
        presum[i] = presum[i] + presum[i-1];
    }

    int lo = 0;
    int hi = m;

    int ans = m;
    while(hi>= lo){
        int mid = (hi+lo)/2;
..............................................................................................................................................................................................................
        if(solved(mid) >= m){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout<<ans<<endl;

    return 0;
}
