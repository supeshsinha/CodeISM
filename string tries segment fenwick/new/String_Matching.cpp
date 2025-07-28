#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> kmp(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if(s[i]==s[j]) pi[i] = j + 1;
        else pi[i] = 0;
    }
    return pi;
}

int32_t main(){
    string s, p;
    cin>>s>>p;

    string temp = p + "#" + s;

    vector<int> pi = kmp(temp);

    int ans = 0;

    for(int i = p.size()+1; i< temp.size(); i++) if(pi[i]==p.size()) ans++;
    cout<<ans<<endl;


    return 0;
}
