#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<int> kmp(string s){
    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i=1; i<n; i++){
        int j = pi[i-1];

        while(j>0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) pi[i] = j+1;
        else pi[i] = 0;

    }
    return pi;
}

int32_t main(){

    string str, pat;
    cin>>str>>pat;
    string temp = pat + "#" + str;

    vector<int> pi = kmp(temp);

    int ans = 0;
    for(int i= pat.size()+1; i< pat.size()+str.size()+1; i++) if(pi[i]==pat.size()) ans++;

    cout<<ans<<endl;
    
    return 0;
}
