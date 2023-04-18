#include<bits/stdc++.h>
#define int long long
using namespace std;
int in_degeree[];
int out[];
vector<int>adj[];
Void solve(){
	queue<int>q;
	for(int i=1;i<=n;i++)if(in_degree[i]==0)q.push(i);
	while(!q.empty()){
		auto x=q.front();
		q.pop();
		for(auto child:adj[x]){
			prob[child]+=prob[x]/out[x];
			In_degree[child]--;
			if(in_degree[child]==0)q.push(child);
		}
	}
}

int main()
{
    int n,m,r; 
    cin>>n>>m>>r;
    memset(adj,0,sizeof adj);
    for(int i=0;i<m;i++)
    {
        int x; cin>>x;
        int y; cin>>y;
        adj[x].push_back(y);
    }
    
    
}