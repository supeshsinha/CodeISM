#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<bool>> adj;
vector<int> team;
int n,m;

bool dfs(int node, int currTeam){
    team[node] = currTeam;
    bool ans1;
    for(int i=1;i<=n;i++){

        if(adj[node][i]){

            if(team[i] == team[node]) { return false;}
            if(team[i]==0){
                
                ans1 = dfs(i,3-currTeam);
                if(ans1 == false) return false;
            }
        }
    }

    return true;
}

void solve(){
    
    bool ans;
    cin>>n>>m;
    adj.assign(n+1,vector<bool>(n+1,1));
    team.assign(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 0;
        adj[v][u] = 0;
    }
    for(int i=1;i<=n;i++){
        adj[i][i] = 0;
    }
    for(int i=1;i<=n;i++){
        if(team[i] == 0){
            ans = dfs(i,1);

            if(ans == false){

                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}

