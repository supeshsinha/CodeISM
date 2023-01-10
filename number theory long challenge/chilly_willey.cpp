#include<iostream>
#include<string>

using namespace std;

int main(){

    int n,last;
    string numlast;
    cin>>n;
    int temp = n;
    int rem = 10;
    if (n<3){
        cout <<-1<<endl;
        return 0;
    }
    if(n==3){
        cout<<210<<endl;
        return 0;
    }
    while(temp!=2){
        rem = (rem*10)%210;
        temp--;

    }

    string num;
    num = "1";
    for(int i=0; i<n-4;i++) num = num + "0";

    last = 210-rem;
    if (rem==0) numlast = "000";
    else if (last/10 == 0) numlast = "00" + to_string(last);
    else if (last/100 == 0) numlast = "0" + to_string(last);
    else numlast = to_string(last);

    num = num + numlast;
    cout << num<<endl;


    return 0;
}