///Date     :   29/5/2020
///Approach :   Dynamic Programming ( Digit DP)
///Notes    :   We have to calculate from the end of the digit
///             Also min difference can be -45 so we can start with +45( reducing state )

#include<bits/stdc++.h>
using namespace std;

int len;
string s;
int dp[11][2][100];

int cal(int pos, bool small , int dif){

    if(pos<0){
        if(dif==46)return 1;///initial was 45
        return 0;
    }
    if(dp[pos][small][dif]!=-1)return dp[pos][small][dif];

    int limit=9;
    if(!small)limit=s[pos]-'0';
    int sum=0;
    for(int i=0; i<=limit; i++){
        if(pos%2==1)  sum+=cal(pos-1, small||(i<limit), dif+i);
        if(pos%2==0)  sum+=cal(pos-1, small||(i<limit), dif-i);
    }
    return dp[pos][small][dif]=sum;
}

void convert(int n){
    stringstream ss;
    ss<<n;
    ss>>s;
    reverse(s.begin(),s.end());
}


int main(){

    int tot,t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;

        convert(b);
        len=s.size();
        memset(dp,-1,sizeof(dp));
        tot=cal(len-1,0,45);

        convert(a-1);
        len=s.size();
        memset(dp,-1,sizeof(dp));
        if(a-1>0)tot-=cal(len-1,0,45);

        cout<<tot<<endl;
    }
    return 0;
}
