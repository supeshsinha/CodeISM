#include<bits/stdc++.h>
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

int remainder(string a, int b){
    int rem = 0;
    string rem1 = "";
    for(int i=0;i<a.length();i++){
        rem1 = to_string(rem);
        rem1 = rem1 + a[i];
        rem = stoi(rem1);
        rem = rem%b;
    }
    return rem;
}



void solve(){
    int cycle[] = {1,1,4,4,2,1,1,4,4,2};
    string a;
    string b;
    cin>>a>>b;
    int a1 = a[a.length()-1] - 48;
    int rem = remainder(b,cycle[a1]);
    if(rem==0) rem = cycle[a1];
    int ans = pow(a1,rem);
    ans = ans%10;
    cout<<ans<<endl;


}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
