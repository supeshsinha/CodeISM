#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;



int32_t main(){
    int n;
    cin>>n;
    unordered_set<int> s;
    int p;
    for(int i=1; i<n;i++){
        cin>>p;
        s.insert(p);
    }
    //int ans = n - (n-s.size()-1); n - number of branches   no of brances = leaf node -1 = n-s.size()-1
    cout<<s.size()+1<<endl;
    return 0;
}
