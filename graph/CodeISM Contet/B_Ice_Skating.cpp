#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<pair<int,int>>> adjx(1001);
vector<vector<pair<int,int>>> adjy(1001);
vector<vector<bool>> vis(1001, vector<bool>(1001,0));

void dfs(int x, int y){
    vis[x][y] = 1;

    for(auto ch: adjx[x]){
        if(!vis[ch.first][ch.second]) dfs(ch.first, ch.second);
    }
    for(auto ch: adjy[y]){
        if(!vis[ch.first][ch.second]) dfs(ch.first, ch.second);
    }
}

int32_t main(){
    int n;
    cin>>n;
    int x,y;
    vector<pair<int,int>> nodes;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        adjx[x].push_back({x,y});
        adjy[y].push_back({x,y});
        nodes.push_back({x,y});
    }
    int c = 0;

    for(int i=0; i<nodes.size(); i++){
        x = nodes[i].first;
        y = nodes[i].second;
        if(!vis[x][y]){
            c++;
            dfs(x,y);
        }
    }
    cout<<c-1<<endl;

    return 0;
}
