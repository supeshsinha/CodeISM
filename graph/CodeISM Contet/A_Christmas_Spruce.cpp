#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<bool> isleaf;
vector<bool> leaf3;

void dfs(int node){
    int c = 0;
    for(auto ch: adj[node]){
        if(isleaf[ch]) c++;
        else{
            dfs(ch);
        }
    }
    if(c>=3) leaf3[node] = 1;
}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    isleaf.assign(n+1,0);
    leaf3.assign(n+1,0);
    int temp;
    for(int i=1; i<=n-1; i++){
        cin>>temp;
        adj[temp].push_back(i+1);
    }
    for(int i=1; i<=n; i++) if(adj[i].size() == 0) isleaf[i] = 1;
    dfs(1);

    for(int i=1; i<=n; i++) if(!isleaf[i] && !leaf3[i]){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;


    return 0;
}
