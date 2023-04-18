#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int r,c;
bool isvalid(int i,int j){
    if(i<0 || j<0 || i>=r || j>=c) return false;
    else return true;
}

void solve(){

    cin>>r>>c;
    vector<string> map(r);
    for(int i=0;i<r;i++){
        cin>>map[i];
    }
    deque<pair<int,int>> dq;
    vvi(dist,r,c,INT_MAX);
    dist[0][0] = 0;
    dq.push_back({0,0});
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    while(!dq.empty()){
        pair<int,int> p = dq.front();
        int x = p.first;
        int y = p.second;
        dq.pop_front();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isvalid(nx,ny) && map[nx][ny] == map[x][y] && dist[nx][ny] > dist[x][y]){
                dist[nx][ny] = dist[x][y];
                dq.push_front({nx,ny});
            }
            else if(isvalid(nx,ny) && map[nx][ny] != map[x][y] && dist[nx][ny] > dist[x][y]+1){
                dist[nx][ny] = dist[x][y] +1;
                dq.push_back({nx,ny});
            }
        }

    }
    cout<<dist[r-1][c-1]<<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
