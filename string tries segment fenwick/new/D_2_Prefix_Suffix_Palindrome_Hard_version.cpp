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
        while(j>0 && s[j] != s[i]) j = pi[j-1];
        if(s[i]==s[j]) pi[i] = j+1;
        else pi[i] = 0;
    }
    return pi;
}


void solve(){
    string s;
    cin>>s;
    int len = s.length();

    int i = 0;
    int j = len -1;

    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else break;
    }
    string str = s.substr(i, len- 2*i);
    string rstr = str;
    reverse(rstr.begin(), rstr.end());

    string front = str + "#" + rstr;
    string back = rstr + "#" + str;

    vector<int> pif = kmp(front);
    vector<int> pib = kmp(back);

    string middle;
    if(pif.back() >= pib.back()){
        middle = str.substr(0,pif.back());
    }
    else middle = rstr.substr(0, pib.back());


    cout<<s.substr(0,i)<<middle<<s.substr(len-i)<<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
