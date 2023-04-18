#include<bits/stdc++.h>
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

int main(){
    cout<<remainder("9",4);

    return 0;
}
