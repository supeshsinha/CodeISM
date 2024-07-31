#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<bool> isleaf;
vector<int> intime;
vector<int> outime;
vector<int> par;
int counter = 0;

void dfs(int node, int parent){
    intime[node] = counter++;
    par[node] = parent;
    for(auto ch : adj[node]){
        if(ch == parent) continue;
        dfs(ch, node);
    }
    
    outime[node] = counter++;
}


int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    isleaf.assign(n+1,0);
    intime.assign(n+1,0);
    outime.assign(n+1,0);
    par.assign(n+1,-1);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k=0;
    for(int i=2; i<=n; i++) if(adj[i].size() == 1){
        k++;
        isleaf[i] = 1;
    }
    vector<int> lorder(k+2);
    lorder[0] = 1;
    for(int i=1; i<k+1; i++) cin>>lorder[i];
    lorder[k+1] = 1;
    dfs(1,-1);
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<k+1; i++){
        int node = lorder[i];
        int node1 = lorder[i+1];

        for(; !(intime[node]<=intime[node1] && outime[node]>=outime[node1]); node = par[node]){
            ans.push_back(node);
        }
        ans.push_back(node);
        
        while(node1 != node){
            st.push(node1);
            node1 = par[node1];
        }
        while(!st.empty()){
            if(st.size()==1){
                st.pop();
                continue;
            }
            ans.push_back(st.top());
            st.pop();
        }
    }

    if(ans.size() == 2*n-1){
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;

   
    return 0;
}
