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
        
        while(j>0 && s[j]!=s[i]){
            j = pi[j-1];
        }
        if(s[j] == s[i]) pi[i] = j+1;
        else pi[i] = 0;
    }
    return pi;
}


void solve(){
    string str;
    cin>>str;
    int i =0;
    int j = str.size()-1;
    while((str[i] == str[j]) && i<=j){
        i++;
        j--;
    }
    if(i>j){
        cout<<str<<endl;
        return;
    }

    string first = str.substr(0,i);
    string last = first;
    reverse(last.begin(), last.end());

    string s = str.substr(i,j-i+1);
    string rs = s;
    reverse(rs.begin(), rs.end());

    string temp1 = s + "#" + rs;
    string temp2 = rs + "#" + s;

    vector<int> pi1 = kmp(temp1);
    vector<int> pi2 = kmp(temp2);

    string middle;
    if(pi1[2*s.length()] < pi2[2*s.length()]){
        middle = rs.substr(0,pi2[2*rs.length()]);
    }
    else{
        middle = s.substr(0,pi1[2*s.length()]);
    }
    cout<<first<<middle<<last<<endl;


}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
