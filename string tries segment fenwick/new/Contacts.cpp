#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct trie{
    int freq;
    trie* child[26];

    trie(){
        for(int i=0; i<26; i++) child[i] = NULL;
        freq = 0;
    }
    ~trie(){
        for(int i=0; i<26; i++) delete child[i];
    }
};

void insert(trie* root, string s){

    for(int i=0; i<s.size(); i++){
        if(!root-> child[s[i]-'a']) root->child[s[i]-'a'] = new trie();
        root = root->child[s[i]-'a'];
        root->freq++;
    }
}

int find(trie* root, string s){
    for(int i=0; i<s.size(); i++){
        if(!root->child[s[i]-'a']) return 0;
        root = root->child[s[i]-'a'];
    }
    return root->freq;
}

int32_t main(){
    int n;
    cin>>n;
    trie* root = new trie();

    while(n--){
        string op, s;
        cin>>op>>s;

        if(op == "add")insert(root, s);
        else cout<<find(root, s)<<endl;
    }
    delete root;

    return 0;
}
