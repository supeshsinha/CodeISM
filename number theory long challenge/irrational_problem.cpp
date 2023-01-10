#include <iostream>
using namespace std;

int main(){
    int p1,p2,p3,p4,a,b;
    cin>>p1>>p2>>p3>>p4>>a>>b;
    int least = min(p1,min(p2,min(p3,p4)));

    if(b<least) cout << b-a+1 <<endl;
    else if(a>= least) cout << 0 <<endl;
    else cout<< least - a;


    return 0;
}