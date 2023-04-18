#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int h,w;
bool isvalid(int i, int j){
    if(i<=0 || i>h || j<=0 || j>w) return false;
    else return true;
}

int32_t main(){
    cin>>h>>w;
    int ci,cj;
    cin>>ci>>cj;
    int di,dj;
    cin>>di>>dj;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    char maze[h+1][w+1];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++) cin>>maze[i][j];
    }
    deque<pair<int,pair<int,int>>> dq;
    vvi(dist,h+1,w+1,LLONG_MAX);
    dist[ci][cj] = 0;
    dq.push_back({0,{ci,cj}});
    while(!dq.empty()){
        pair<int,pair<int,int>> p = dq.front();
        dq.pop_front();
        int u = p.second.first;
        int v = p.second.second;
        int w = p.first;
        if(u==di && v == dj) break;
        else if(w > dist[u][v]) continue;
        for(int i=-2; i<=2 ;i++){
            for(int j=-2;j<=2;j++){
                int nu = u + i;
                int nv = v + j;
                if(isvalid(nu,nv) && dist[nu][nv]> w+1 && maze[nu][nv] == '.'){
                    dist[nu][nv] = w+1;
                    dq.push_back({dist[nu][nv],{nu,nv}});
                }
            }
        }
        for(int k=0;k<4;k++){
            int nu = u + dx[k];
            int nv = v + dy[k];
            if(isvalid(nu,nv) && dist[nu][nv]> w && maze[nu][nv] == '.'){
                dist[nu][nv] = w;
                dq.push_front({w,{nu,nv}});
            }
        }
        

    }
    if(dist[di][dj] == LLONG_MAX) cout<<-1<<endl;
    else cout<<dist[di][dj]<<endl;

    return 0;
}
