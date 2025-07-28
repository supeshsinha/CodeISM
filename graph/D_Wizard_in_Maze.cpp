#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int r,c;

bool isvalid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}

int32_t main(){
    
    cin>>r>>c;
    int si,sj,ei,ej;
    cin>>si>>sj;
    cin>>ei>>ej;

    vector<string> grid(r);
    for(int i=0; i<r; i++) cin>>grid[i];

    deque<pair<int,int>> q;
    vector<vector<int>> dist(r, vector<int>(c, 1e18));

    dist[si-1][sj-1] = 0;
    q.push_back({si-1, sj-1});

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        for(int i=0; i<4; i++){
            int ni = x + di[i];
            int nj = y + dj[i];

            if(isvalid(ni,nj) && grid[ni][nj]=='.' && dist[ni][nj] > dist[x][y]){
                dist[ni][nj] = dist[x][y];
                q.push_front({ni,nj});
            }
        }

        for(int i=x-2; i<=x+2; i++) for(int j=y-2; j<=y+2; j++){
            if(isvalid(i,j) && grid[i][j]=='.' && dist[i][j]>dist[x][y]+1){
                dist[i][j] = dist[x][y]+1;
                q.push_back({i,j});
            }
        }
    }
    if(dist[ei-1][ej-1] == 1e18) cout<<-1<<endl;
    else cout<<dist[ei-1][ej-1]<<endl;


    return 0;
}
