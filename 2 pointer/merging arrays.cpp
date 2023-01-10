#include <iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++) cin>>b[j];
    int i = 0;
    int j = 0;
    while(i<n && b<m){
        if(a[i]<b[j]){
            cout<< a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j]){
            cout<< b[j]<<" ";
            j++;
        }
    }
}