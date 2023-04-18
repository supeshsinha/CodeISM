#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int n,m;

bool isvalid(int i,int j){
    if(i<0 || j<0 || i>= n || j>=m) return false;
    else return true;
}


int32_t main(){

    cin>>n>>m;
    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};
    vector<vector<char>> map(n,vector<char>(m));
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(m,LLONG_MAX));
    pair<int,int> target;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j] == 'A'){
                q.push({i,j});
                map[i][j] = '#';
                dist[i][j] = 0;
            }
            else if(map[i][j] == 'B') target = {i,j};
        }
    }
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ni = p.first + di[k];
            int nj = p.second + dj[k];
            if(isvalid(ni,nj) && map[ni][nj] != '#'){
                parent[ni][nj] = p;
                dist[ni][nj] = dist[p.first][p.second] + 1;
                map[ni][nj] = '#';
                q.push({ni,nj});
            }
        }
    }

    if(dist[target.first][target.second] == LLONG_MAX) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<< dist[target.first][target.second] <<endl;
        stack<char> path;

        while(parent[target.first][target.second].first != -1){
            pair<int,int> par = parent[target.first][target.second];
            if(par.first<target.first) path.push('D');
            else if(par.first>target.first) path.push('U');
            else if(par.second<target.second) path.push('R');
            else if(par.second>target.second) path.push('L');
            target = par;
        }
        while(!path.empty()){
            cout<< path.top();
            path.pop();
        }
        cout<<endl;
    }


    


    return 0;
}
