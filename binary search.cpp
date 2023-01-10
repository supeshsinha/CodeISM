#include <iostream>
using namespace std;

int main(){
    int arr[8]=[1,5,7,8,8,10,12,15];
    int x;
    int n = 7;
    cin>>x;
    int l = 0, r=n-1;
    int ans = -1;
    while(l<=r){

        int mid = l+(r-l)/2; // Usefull to avoid overflow

        if(arr[mid]>x){
            r= mid-1;
        }

        else if(arr[mid]<x){
            l = mid+1;
        }
        else{
            ans = mid;
            break;
        }
    }


    return 0;
}