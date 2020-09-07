#include<bits/stdc++.h>
using namespace std;

#define ll  long long
#define inf 1e9
ll dp[11][2];
int len;
string s;o

ll cal(int pos, bool smaller){

    if(pos>=len){
        return 0;
    }
    if(dp[pos][smaller]!=-1)return dp[pos][smaller];

    int limit=9;
    if(!smaller)limit=s[pos]-'0';

    for(int i=0; i<len; i++){
        int val=s[i]-'0';
        if( && mark[])
    }
}

int main(){

    ll a=inf;
    ///a=1<<15;
    cout<<a<<endl;





    return 0;
}
