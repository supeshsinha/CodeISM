#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	int mina, maxa;
	cin>> mina;
	maxa = mina;
	int temp;
	for(int i=1; i<n; i++){
		cin>>temp;
		mina = min(mina, temp);
		maxa = max(maxa, temp);
	}
	cout<<(mina+maxa)<<endl;
}

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
