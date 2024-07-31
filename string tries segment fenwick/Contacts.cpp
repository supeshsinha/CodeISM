#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct trie{
    trie* child[26];
    int freq;

    trie(){
        for(int i=0; i<26; i++) child[i] = NULL;
        freq = 0;
    }
};

void insert(trie* root, string s){
    for(int i=0; i<s.size(); i++){
        if(root->child[s[i]-'a'] == NULL){
            root->child[s[i]- 'a'] = new trie;
        }
        root = root->child[s[i]-'a'];
        root->freq++;
    }
}

int findpart(trie* root, string s){
    for(int i=0; i<s.size(); i++){
        if(root->child[s[i]-'a'] == NULL) return 0;
        root = root->child[s[i]-'a'];
    }
    return root->freq;
}

int32_t main(){
    int q;
    cin>>q;
    trie* root = new trie;
    while(q--){
        string op,word;
        cin>>op>>word;
        if(op == "add") insert(root,word);
        else cout<<findpart(root,word)<<endl;
    }
    

    return 0;
}
