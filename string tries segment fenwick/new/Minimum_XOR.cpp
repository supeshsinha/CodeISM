#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct trie{
    int freq;
    trie* child[2];

    trie(){
        child[0] = NULL;
        child[1] = NULL;
        freq = 0;
    }
    ~trie(){
        delete child[0];
        delete child[1];
    }
};

void insert(trie* root, int n){
    for(int i=62; i>=0; i--){
        int bit = (n>>i)&1ll;

        if(!root->child[bit]) root->child[bit] = new trie();
        root = root->child[bit];
        root->freq++;
    }
}

int kmin(trie* root, int n, int k){
    int ans = 0;
    for(int i=62; i>=0; i--){
        int bit = (n>>i)&1ll;
        if(root->child[bit]==NULL || root->child[bit]->freq < k){
            ans |= (1ll<<i);
            if(root->child[bit]) k -= root->child[bit]->freq;
            root = root->child[bit^1ll];
        }
        else{
            root = root->child[bit];
        }
    }
    return ans;
}

int32_t main(){
    int q;
    cin>>q;

    trie* root = new trie();
    int type;
    while(q--){
        cin>>type;

        if(type==1){
            int x;
            cin>>x;
            insert(root, x);
        }
        else{
            int x,k;
            cin>>x>>k;
            cout<<kmin(root,x,k)<<endl;
        }
    }
    //delete root;

    return 0;
}
