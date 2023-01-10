#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    string str;
    int count = 0;
    cin>> str;
    int length = str.length();

    for(int i=0;i< length; i++){
        for(int j = i+1; j<length; j++){
            for(int k = j+1; k<length; k++){
                if(str[i]=='Q' && str[j]=='A' && str[k]=='Q') count++;
            }
        }
    }
    cout << count <<endl;


    return 0;
}