#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

vector<vector<int>> sp(10, vector<int>(10));

void floyd(int x, int y){
    sp.assign(10, vector<int>(10, 1e9));
    for(int i=0; i<10; i++){
        sp[i][(i+x)%10] = 1;
        sp[i][(i+y)%10] = 1;
    }

    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
            }
        }
    }
}


int32_t main(){
    string s;
    cin>>s;
    vector<vector<int>> grid(10, vector<int>(10,-1));
    vector<vector<int>> freq(10, vector<int>(10,0));
    for(int i=0; i<s.length()-1; i++) freq[s[i]-'0'][s[i+1]-'0']++;

    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            floyd(i,j);
            int ans = 0;
            //for(int k=1; k< s.size(); k++) ans += (sp[s[k-1]-'0'][s[k]-'0'] -1);
            for(int l=0; l<10; l++) for(int m=0; m<10; m++){
                ans += freq[l][m]*(sp[l][m]-1);
            }
            if(ans < 1e9-1){
                grid[i][j] = ans;
                grid[j][i] = ans;
            }
        }
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
