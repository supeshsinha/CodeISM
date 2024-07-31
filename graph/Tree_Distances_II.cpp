#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;

vector<int> N;
vector<int> S;
vector<int> ans;

void dfs1(int node, int par){

    for(auto ch : adj[node]){
        if(ch != par){
            dfs1(ch,node);
            N[node] += N[ch];
            S[node] += S[ch] + N[ch];
        }
    }
}

void dfs2(int node, int par){

    for(auto ch: adj[node]){
        if(ch != par){
            //make child root
            N[node] = N[node] - N[ch];
            S[node] = S[node] - (N[ch] + S[ch]);
            N[ch] = N[ch] + N[node];
            S[ch] = S[ch] + N[node] + S[node];
            // set ans
            ans[ch] = S[ch];

            dfs2(ch,node);
            //make node root
            S[ch] -= (N[node] + S[node]);
            N[ch] -= N[node];
            S[node] += (N[ch] + S[ch]);
            N[node] += N[ch];
        }
    }

}


int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    N.assign(n+1,1);
    S.assign(n+1,0);
    ans.assign(n+1,0);
    int a,b;
    for(int i=1; i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1,-1);
    ans[1] = S[1];
    dfs2(1,-1);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
