#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>q>>q;

    int sum = 0;
    int xors = 0;

    for(int i=0; i<n; i++){
        sum += a[i];
        xors ^= a[i];
    }
    int f = sum - xors;

    // int si = 0;
    // int ei = n-1;
    // for(int i=0; i<=ei; i++){
    //     if(sum - a[i] - (xors^a[i]) == f){
    //         sum -= a[i];
    //         xors ^= a[i];
    //         if(si+1 <= ei)si++;
    //     }
    //     else break;
    // }
    // for(int j=n-1; j>=si; j--){
    //     if(sum - a[j] - (xors^a[j]) == f){
    //         sum -= a[j];
    //         xors ^= a[j];
    //         if(ei-1>=si)ei--;
    //     }
    //     else break;
    // }

    //cout<<si+1<<" "<<ei+1<<endl;

    int i=0;
    int j = 0;
    sum = a[0];
    xors = a[0];

    int ans = n;
    int ansi = 0;
    int ansj = n-1;

    while(j<n && i<=j){
        if(sum - xors < f){
            j++;
            sum += a[j];
            xors ^= a[j];
        }
        else{
            if(ans > j-i+1){
                ans = j-i+1;
                ansi = i;
                ansj = j;
            }
            sum -= a[i];
            xors ^= a[i];
            i++;
        }
    }
    cout<<ansi+1<<" "<<ansj+1<<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
