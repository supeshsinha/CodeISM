#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[100000 + 1];


vector <string> aps(int n){
    if(n==1){
        vector<string> ans1 = {"1","2","3","4","5"};
        return ans1;
    }
    vector<string> ans;
    vector<string> prev_ans = aps(n-1);
    if(a[n]>a[n-1]){
        for(int i=0; i<prev_ans.size(); i++){
            int len = prev_ans[i].length();
            for(int j = prev_ans[i][len-1]-47; j<=5; j++){
                ans.push_back(prev_ans[i]+" "+ to_string(j));
            }
        }
    }
    else if(a[n]<a[n-1]){
        for(int i=0; i<prev_ans.size(); i++){
            int len = prev_ans[i].length();
            for(int j = 1; j<=prev_ans[i][len-1]-49; j++){
                ans.push_back(prev_ans[i]+" "+ to_string(j));
            }
        }
    }
    else{
        for(int i=0; i<prev_ans.size(); i++){
            for(int j = 1; j<=5; j++){
                int len = prev_ans[i].length();
                if(prev_ans[i][len-1]-48 == j) continue;
                ans.push_back(prev_ans[i]+" "+ to_string(j));
            }
        }
    }
    return ans;
}

int32_t main(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<string> ans = aps(n);

    if(ans.empty()) cout<< -1;
    else cout<< ans[0]<<endl;

    return 0;
}