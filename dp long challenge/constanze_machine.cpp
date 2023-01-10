#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

    int power(int n,int p){
        if(p == 0) return 1;
        if(p%2) return (power(n,p-1) * n%mod)%mod;
        else {
            int ans = power(n,p/2);
            return (ans * ans)%mod;
        }
    }

int32_t main(){


    string str;
    cin>>str;
    int count = 1;
    int length = str.length();

    if(str[0]=='w' || str[0]=='m'){
            cout<<0<<endl;
            exit(0);
    }
    for(int i =1; i<length; i++){
        int subcount = 1;
        if(str[i]=='w' || str[i]=='m'){
            cout<<0<<endl;
            exit(0);
        }
        if(str[i]=='n' && str[i-1]=='n'){
            int j = i-1;
            while(str[i]=='n') i++;
            int n = i - j;
            if(n%2) subcount = (power(2,n/2) * 2 -1)%mod;
            else subcount = (power(2,(n-1)/2)*3 -1)%mod;
        }
        if(str[i]=='u' && str[i-1]=='u'){
            int j = i-1;
            while(str[i]=='u') i++;
            int n = i - j;
            if(n%2) subcount = (power(2,n/2) * 2 -1 +mod)%mod;
            else subcount = (power(2,(n-1)/2)*3 -1 +mod)%mod;
        }
        count *= subcount;
        count = count % mod;

    }
    cout << count <<endl;

    return 0;
}