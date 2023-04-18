#include<bits/stdc++.h>
#define int long long
using namespace std;

    int n,m;

    int di[] = {1,-1,0,0};
    int dj[] = {0,0,1,-1};

vector<vector<bool>> iswall(1000,vector<bool>(1000,0));


bool isvalid(int i, int j){
    if(i>=n || j>=m || i<0 || j<0) return false;
    else if(iswall[i][j]) return false;
    else return true;

}


// void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &distance){
//     for (int i = 0; i < n; i++)
//         for(int j=0;j<m ;j++) visited[i][j]=0;
//     queue<pair<int,int>> q;
//     q.push({i,j});
//     distance[i][j] = 0;
//     visited[i][j] = 1;
//     while(!q.empty()){
//         auto newnode = q.front();
//         q.pop();
//         int i = newnode.first;
//         int j = newnode.second;
//         for (int k = 0; k < 4; k++)
//         {
//             int ni = i + di[k];
//             int nj = j + dj[k];
//             if(!isvalid(ni,nj)) continue;
//             if(!visited[ni][nj]){
//                 q.push({ni,nj});
//                 visited[ni][nj]=1;
//                 distance[ni][nj] = min(distance[i][j] + 1, distance[ni][nj]);
//             }
//         }
        
//     }
// }

pair<int,int> bfs1(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &distance1, vector<vector<int>> &distance, vector<vector<pair<int,int>>> &parent){
    for (int l = 0; l < n; l++)
        for(int s=0;s<m ;s++) visited[l][s]=0;
    queue<pair<int,int>> q;
    q.push({i,j});
    distance1[i][j] = 0;
    visited[i][j] = 1;
    while(!q.empty()){
        auto newnode = q.front();
        q.pop();
        int i = newnode.first;
        int j = newnode.second;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(!isvalid(ni,nj)) continue;
            if(!visited[ni][nj]){
                visited[ni][nj]=1;
                distance1[ni][nj] = distance1[i][j] + 1;
                if(distance1[ni][nj] >= distance[ni][nj]) continue;
                q.push({ni,nj});
                parent[ni][nj] = {i,j};
                if(ni == n-1 || nj == m-1 || ni==0 || nj==0) return {ni,nj};
            }
        }
        
    }
    return {-1,-1};
}



int32_t main(){
    cin>>n>>m;

    vector<vector<bool>> visited(n,vector<bool>(m,0));

    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    vector<vector<int>> distance1(n,vector<int>(m,INT_MAX));

    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));

    vector<pair<int,int>> M;
    pair<int,int> A;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin>>temp;
        for (int j = 0; j < m; j++)
        {
            if(temp[j]=='#') iswall[i][j] = 1;
            else if(temp[j]=='M'){
                M.push_back({i,j});
            }
            else if(temp[j] == 'A') A = {i,j};
        }
        
    }
    if(A.first == n-1 || A.second == m-1 || A.first==0 || A.second==0){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        exit(0);
    }

    queue<pair<int,int>> q;
    for(auto ch:M){
        //bfs(ch.first, ch.second, visited, distance);
        q.push(ch);
        distance[ch.first][ch.second] = 0;
        visited[ch.first][ch.second] = 1;
    }
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        for(int k=0;k<4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(!isvalid(ni,nj) || visited[ni][nj]) continue;
            visited[ni][nj] = 1;
            distance[ni][nj] = distance[i][j] +1;
            q.push({ni,nj});
        }
    }

    pair<int,int> result = bfs1(A.first, A.second, visited, distance1, distance, parent);

    if(result.first == -1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        stack <pair<int,int>> st;
        st.push(result);
        int f = result.first;
        int s = result.second;
        while(parent[f][s].first != -1){
            int temp = parent[f][s].first;
            s = parent[f][s].second;
            f=temp;
            st.push({f,s});
            
        }
        cout<<st.size()-1<<endl;
        pair<int,int> one;
        pair<int,int> two;
        two = st.top();
        st.pop();
        while(!st.empty()){
            one = two;
            two = st.top();
            st.pop();

            if(one.first<two.first)cout<<"D";
            else if(one.first>two.first)cout<<"U";
            else if(one.second<two.second)cout<<"R";
            else if(one.second>two.second)cout<<"L";
        }
        cout<<endl;
    }


    return 0;
}