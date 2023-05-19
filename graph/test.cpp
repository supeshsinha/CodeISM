#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>vec(n+1);
    vector<int>ind(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        vec[u].push_back(v);
        ind[v]++;
    }
    priority_queue<int, vector<int>, greater<int>>qu;
    for(int i=1;i<n+1;i++){
        if(ind[i]==0)qu.push(i);
    }
    vector<int>order;
    while(!qu.empty()){
        int x=qu.top();
        order.push_back(x);
        qu.pop();
        for(auto p : vec[x]){
            ind[p]--;
            if(ind[p]==0)qu.push(p);
        }
    }
    if(order.size()!= n){
        cout<<-1;
    }

    else for(auto p : order)cout<<p<<" ";
    cout<<endl;
}
