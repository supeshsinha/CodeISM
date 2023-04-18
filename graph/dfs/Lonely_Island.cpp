#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n,m,r;
vector<vector<int>> adj;
vector<double> ans;


int32_t main(){
    const double eps = 1e-9;
    cin>>n>>m>>r;
    adj.resize(n+1);
    ans.assign(n+1,0);
    int u,v;
    vector<int> outdeg(n+1,0);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i] == 0) q.push(i);
    }
    vector<int> possibleans;


    for(int i=1;i<=n;i++){
        if(outdeg[i] == 0) possibleans.push_back(i);
    }

    ans[r] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto ch: adj[x]){
            indeg[ch]--;
            if(indeg[ch] == 0) q.push(ch);
            ans[ch]+= ans[x]/outdeg[x];
        }

    }
    double maxa = 0;

    for(int i=0; i<possibleans.size(); i++){
        maxa = max(maxa,ans[possibleans[i]]);
    }


    for(int i=0; i<possibleans.size(); i++){
        if(maxa-ans[possibleans[i]] <= eps) cout<<possibleans[i]<<" ";
    }
    cout<<endl;

    


    return 0;
}
