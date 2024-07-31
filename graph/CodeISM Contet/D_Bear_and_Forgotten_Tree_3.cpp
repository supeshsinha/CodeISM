#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;


int32_t main(){
    int n,d,h;
    cin>>n>>d>>h; 
    if(d>2*h || d<h || n-1<d || (h==1 && d==1 && n>2)){
        cout<<-1<<endl;
        return 0;
    }
    //int extra = n - (d+1);
    int i = 2;
    for(; i<= h+1; i++){
        cout<<i-1<<" "<<i<<endl;
    }
    int slast = i-2;
    if(d>h){
        cout<<1<<" "<<i<<endl;
        i++;
        for(; i<=d+1; i++) cout<<i-1<<" "<<i<<endl;
    }
    for(; i<=n; i++) cout<<slast<<" "<<i<<endl;



    return 0;
}
