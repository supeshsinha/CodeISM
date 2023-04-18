#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;



int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(indeg[i]==0) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto ch:adj[x]){
            indeg[ch]--;
            if(indeg[ch] == 0) q.push(ch);
        }
    }
    if(ans.size() == n){
        for(auto ch : ans) cout<<ch<<" ";
    }
    else cout<<"IMPOSSIBLE";
    cout<<endl;

    return 0;
}
