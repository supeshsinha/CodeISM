#include<bits/stdc++.h>
#define int long long
#define vvi(name,r,c,d) vector<vector<int>> name(r,vector<int>(c,d))
using namespace std;

struct trie{
    trie* child[10];
    bool isTerminal;

    trie(){
        for(int i=0; i<10; i++) child[i] = NULL;
        isTerminal = false;
    }
};

bool insert(trie* root, string s){
    bool prefix = false;
    for(int i=0; i<s.length(); i++){
        int ind = s[i]-'a';
        if(root->isTerminal) prefix = 1;

        if(root->child[ind] == NULL) root->child[ind] = new trie;
        root = root->child[ind];
    }
    if(root->isTerminal) prefix = 1;
    root->isTerminal = true;
    for(int i=0; i<10; i++){
        if(root->child[i] != NULL) prefix = 1;
    }
    return prefix;
}

int32_t main(){
    int n;
    cin>>n;
    string str;
    trie* root = new trie;
     for(int i=0; i<n; i++){
        cin>>str;
        bool prefix = insert(root, str);
        if(prefix){
            cout<<"BAD SET"<<endl;
            cout<<str<<endl;
            return 0;
        }
     }
     cout<<"GOOD SET"<<endl;

    return 0;
}
