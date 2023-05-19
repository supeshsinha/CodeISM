#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> ndist(2e5 + 1);
vector<int> intime;
vector<int> outime;
vector<int> dist;

int counter = 0;
void dfs(int node, int par){
    intime[node] = counter++;

    for(auto ch : adj[node]){
        if(ch != par){
            dist[ch] = dist[node] + 1;
            dfs(ch,node);
        }
    }
    outime[node] = counter++;
    ndist[dist[node]].push_back(node);
}

int u,d;
int f(int node){
    if(intime[node]>=intime[u] && outime[node]<=outime[u]) return 0;
    else if(outime[node]>outime[u]) return -1;
    else return 1;
}

void solve(){
    cin>>u>>d;

    int lo = 0;
    int hi = ndist[d].size()-1;
    int ans1 = -1;

    if(ndist[d].size()==0){
        cout<<0<<endl;
        return;
    }

    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(f(ndist[d][mid]) == 0){
            ans1 = mid;
            hi = mid - 1;
        }
        else if(f(ndist[d][mid]) == -1){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    lo = 0;
    hi = ndist[d].size()-1;
    int ans2 = -1;

    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(f(ndist[d][mid]) == 0){
            ans2 = mid;
            lo = mid + 1;
        }
        else if(f(ndist[d][mid]) == -1){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    if(ans1 == -1 || ans2 == -1){
        cout<<0<<endl;
        return;
    }

    cout<<(ans2-ans1+1)<<endl;

}

int32_t main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    intime.assign(n+1,0);
    outime.assign(n+1,0);
    dist.assign(n+1,0);

    for(int i=2; i<=n;i++){
        int p;
        cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    dfs(1,-1);

    int q;
    cin>>q;

    while(q--){
        solve();
    }

    return 0;
}
