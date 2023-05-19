#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;



int32_t main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(27);
    vector<int> indeg(27,0);
    string s;
    string next;
    cin>>next;
    for(int i=0;i<n-1;i++){
        s = next;
        cin>>next;
        int j;
        for(j=0; j< min(s.length(),next.length()); j++){
            if(s[j] != next[j]){
                adj[(int)s[j] - 96].push_back((int)next[j]-96);
                indeg[(int)next[j]-96]++;
                break;
            }

            
        }
        if(j== next.length()){
            cout<<"Impossible"<<endl;
            exit(0);
        }
    }
    queue<int> q;
    for(int i=1; i<=26 ; i++){
        if(indeg[i]==0) q.push(i);
    }
    
    vector<int> result;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        result.push_back(x);
        for(auto ch : adj[x]){
            indeg[ch]--;
            if(indeg[ch] == 0) q.push(ch);
        }
    }
    if(result.size() == 26)for(int i=0;i<result.size(); i++) cout<<(char)(result[i]+96);
    else cout<<"Impossible";
    cout<<endl;

    return 0;
}
