#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct trie{
    trie* child[2];

    trie(){
        child[0] = NULL;
        child[1] = NULL;
    }
};

void insert(trie* root, int x){
    for(int i = 30; i>=0; i--){
        int bit = (x>>i)&1;
        if(root->child[bit] == NULL) root->child[bit] = new trie;
        root = root->child[bit];
    }
}

int maxxor(trie* root, int x){
    int ans = 0;
    for(int i=30; i>=0; i--){
        int bit = (x>>i)&1;
        if(root->child[1^bit] != NULL){
            ans |= 1<<i;
            root = root->child[1^bit];
        }
        else{
            root = root->child[bit];
        }
    }
    return ans;
}


int32_t main(){
    int n,m;
    cin>>n;
    int temp;
    trie* root = new trie;
    for(int i=0;i<n;i++){
        cin>>temp;
        insert(root, temp);
    }
    cin>>m;
    while(m--){
        cin>>temp;
        cout<<maxxor(root, temp)<<endl;
    }


    return 0;
}
