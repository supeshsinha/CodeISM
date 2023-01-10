#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

    vector <int> prime(1e18,1);

   prime[0]=prime[1]=0;
for(int i=2;i*i<=1e18;i++){
	if(prime[i]==1)for(int multiple=i*i;multiple<=1e6;multiple+=i){
		prime[multiple]=0;
}
}

    for(int i = 0; i<18;i++){
        if
    }


    return 0;
}