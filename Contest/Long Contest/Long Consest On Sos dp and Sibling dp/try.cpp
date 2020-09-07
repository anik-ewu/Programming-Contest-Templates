#include<bits/stdc++.h>
using namespace std;

int v[1<<18];
int dp[1<<18][18];
int process(string s){

    int pos,n=0;
    int mark[20];
    memset(mark,0,sizeof(mark));
    for(int i=0; i<s.size(); i++){
        pos=s[i]-'a';
        if(mark[pos]==0){
            n+=powl(2,pos);
        }
        mark[pos]=1;
    }
    return n;
}

int f(int mask, int x){
    if(x==-1)return v[mask];
    if(dp[mask][x]!=-1)
        return dp[mask][x];
    if(mask &&(1<<x)!=0)
        return dp[mask][x]=f(mask,x-1)+f(mask^(1<<x),x-1);
    else
        return dp[mask][x]=f(mask,x-1);
}

int flip(int mask){
    for(int i=0; i<5; i++){
        mask=mask^(1<<i);
    }
    return mask;
}

int main(){

    int n;
    string s;
    //freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s;
        v[process(s)]++;
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<=(1<<5); i++){
        ///int mask=flip(i);
        ///cout<<i<<' ' <<mask<<endl;
        ///cout<<n-f(mask,23)<<endl;

        cout<<f(i,4)<<endl;
    }



    return 0;
}
