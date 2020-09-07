///Date     : 1.6.2020
///Comments : Instead of taking dp[50][50][50], we can take [51][2][18][18][18] as there we will
///           at most 16 three| six | nine equally at a time (16*3=48 && size<=50);And also instead of decreasing a
///           we can find tot=(b-a) and iterate through a to add 1 with tot if needed.

#include<bits/stdc++.h>
using namespace std;
#define sz 51
#define ll long long
#define mod 1000000007

int len;
string a,b,s;
ll dp[sz][2][18][18][18];
ll cal(int pos, bool issmall, int cn3, int cn6, int cn9){
    if(cn3>=17 || cn6>=17 || cn9>=17)return 0;
    if(pos==-1)return (cn3==cn6 && cn6==cn9 && cn3)?1:0;
    ///ll &ret = dp[pos][cn3][cn6][cn9];
    ///if(issmall and ret != -1) return ret % mod;
    if(issmall && dp[pos][issmall][cn3][cn6][cn9]!=-1)return dp[pos][issmall][cn3][cn6][cn9];

    ll sum=0;
    int limit=9;
    if(!issmall)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        sum=(sum+(cal(pos-1, issmall||(i<limit), cn3+(i==3), cn6+(i==6), cn9+(i==9))%mod))%mod;
    }
     return dp[pos][issmall][cn3][cn6][cn9]=sum;
}

bool check(string A){
    int th,six,nine;
    th=six=nine=0;
    for(int i=0; i<A.size(); i++){
        th+=(s[i]=='3');
        six+=(s[i]=='6');
        nine+=(s[i]=='9');
    }
    if(th==six && six == nine && nine >0)return true;
    return false;
}

ll process(string x){
    s=x;
    len=s.size();
    reverse(s.begin(),s.end());
    return cal(len-1,0,0,0,0);
}

int main(){

    int t;
    ll tot;
    char a[51],b[51];
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",&a,&b);
        tot=process(b)-process(a);
        if(check(a))tot++;  ///checking if a is a 369 number
        printf("%d\n",(tot+mod)%mod);
    }
    return 0;
}
