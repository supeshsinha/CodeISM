#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> seg;

void update(int in, int left, int right, int l, int r, int val){
    if(left> right || left> r || right< l || seg[in]) return;
    if(left >= l && right<= r){
        seg[in] = val;
        return;
    }
    int mid = (left+right)/2;
    update(in*2, left, mid, l, r, val);
    update(in*2+1, mid+1, right, l, r, val);
}
int get(int in, int left, int right, int ti){
    if(left == right) return seg[in];
    int mid = (left+right)/2;
    if(ti<=mid){
        int x = get(in*2, left, mid, ti);
        if(x==0) return seg[in];
        else return x;
    }
    else{
        int x = get(in*2+1, mid+1, right, ti);
        if(x==0) return seg[in];
        else return x;
    }
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    seg.assign(4*n,0);

    while(m--){
        int l,r,x;
        cin>>l>>r>>x;
        update(1,1,n,l,x-1,x);
        update(1,1,n,x+1,r, x);
    }
    for(int i=1; i<=n; i++){
        cout<< get(1,1,n,i)<<" ";
    }
    cout<<endl;

    return 0;
}
