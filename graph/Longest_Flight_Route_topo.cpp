#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<int> par;


int32_t main(){
    int n,m;
    cin>>n>>m;
    int temp = m;
    int u,v;
    adj.resize(n+1);
    dist.assign(n+1,-1);
    par.assign(n+1,-1);
    vector<int>indeg(n+1,0);
    vector<int>order;
    while(temp--){
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        order.push_back(x);

        for(auto ch: adj[x]){
            indeg[ch]--;
            if(indeg[ch] == 0) q.push(ch);
        }
    }
    dist[1] = 0;
    for(auto x : order){
        if(dist[x]!= -1){
            for(auto ch: adj[x]){
            if(dist[ch]< dist[x]+1){
                dist[ch] = dist[x] + 1;
                par[ch] = x;
            }
        }
        }
        
    }





    

    if(dist[n] == -1) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<dist[n]+1<<endl;
        vector<int> ans;
        int temp = n;
        while(par[temp]!= -1){
            ans.push_back(par[temp]);
            temp = par[temp];
        }
        for(int i = ans.size()-1; i>=0; i--){
            cout<<ans[i]<<" ";
        }
        cout<<n<<endl;
    }

    return 0;
}
