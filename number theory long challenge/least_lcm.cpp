#include<bits/stdc++.h>
#define int long long
using namespace std;


int lcm(int a, int n){
    int b = n-a;
    return (a*b)/__gcd(a,b);

}

int32_t main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){

        int n;
        cin>>n;
        
        int spf = -1;
        for(int i=2;i*i<=n;i++){
            if(n%i == 0){
                spf = i;
                break;
            }
        }
        if(spf == -1) spf = n;

        cout<<n/spf<<" "<<(n/spf)*(spf-1)<<endl;

    }


    



    return 0;
}