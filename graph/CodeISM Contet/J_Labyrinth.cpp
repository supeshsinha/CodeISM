#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct node{
    int i;
    int j;
    int left;
    int right;

    node(int x, int y, int l, int r) : i(x), j(y), left(l), right(r) {}
};

int n,m;
vector<string> grid;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

bool isvalid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && grid[i][j] == '.';
}


int32_t main(){
    
    cin>>n>>m;
    int r,c;
    cin>>r>>c;
    r--;
    c--;
    int left,right;
    cin>>left>>right;
    grid.resize(n);
    for(int i=0; i<n; i++) cin>>grid[i];

    deque<node> q;
    node start(r, c, left, right);
    q.push_back(start);
    grid[r][c] = '+';

    while(!q.empty()){
        node p = q.front();
        q.pop_front();

        for(int k=0; k<4; k++){
            int newi = p.i + di[k];
            int newj = p.j + dj[k];
            if(!isvalid(newi, newj)) continue;
            if(k==2){
                if(p.right != 0){
                    q.push_back(node(newi,newj,p.left, p.right-1));
                    grid[newi][newj] = '+';
                }
            }
            else if(k==3){
                if(p.left != 0){
                    q.push_back(node(newi,newj, p.left-1, p.right));
                    grid[newi][newj] = '+';
                }
            }
            else{
                q.push_front(node(newi,newj,p.left, p.right));
                grid[newi][newj] = '+';
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(grid[i][j] == '+') ans++;
    cout<<ans<<endl;
    


    return 0;
}
