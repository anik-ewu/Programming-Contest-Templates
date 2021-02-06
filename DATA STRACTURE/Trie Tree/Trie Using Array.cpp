///Size of Trie nodes is equal to the size of the total string

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 10001
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int cnt;
int trie[sz][26];
bool endword[sz];

void init(){
    cnt=1;
    memset(trie, -1, sizeof(trie));
    memset(endword, 0, sizeof(endword));
}

void addWord(string s){
    int curr=0, nxt;
    for(int i=0; i<s.size(); i++){
        nxt=trie[curr][s[i]-'a'];
        if(nxt==-1){
            trie[curr][s[i]-'a']=cnt++;
        }
        curr=trie[curr][s[i]-'a'];
    }
    endword[curr]=true;

}
bool queryWord(string s){
    int curr=0, nxt;
    for(int i=0; i<s.size(); i++){
        nxt=trie[curr][s[i]-'a'];
        if(nxt==-1){
            return false;
        }
        curr=trie[curr][s[i]-'a'];
    }
    return endword[curr]==true;

}


int main(){

    io;
    //freopen("in.txt.", "r", stdin);

    int t,n;
    string s;
    cin>>t;
    while(t--){
         init();
    }

    return 0;
}
