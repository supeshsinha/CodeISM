#include<iostream>
#define int long long int
using namespace std;


bool f()

int32_t main(){
    int lo = 1,hi = 1e9,mid1,mid2;
    int n = 50;
    int arr[n];

    while(hi-lo>=3){
        mid1 = lo + (hi-lo)/3;
        mid2 = hi - (hi-lo)/3;

        if(f(mid1)>f(mid2)){
            lo = mid1;

        }
        else if(f(mid2)>f(mid1)){
            hi = mid2;
        }

    }
    for(int i = lo; i<=hi; i++) ans = max(ans,arr[i]);

}