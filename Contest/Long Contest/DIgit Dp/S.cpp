///Date     : 13/5/2020
///ALGO     : Dynamic Programming ( Digit DP)
///Notes    : ***
///Comments : Just because someone stumbles, loses their way, doesn't mean they're lost forever.

#include<bits/stdc++.h>
using namespace std;
#define sz 15

int len;
string s;
int arr[]
int dp[10][2][2][11][sz];

void str_to_int(int n){
    stringstream ss;
    ss<<n;
    ss>>s;

}
int cal(int pos, bool smaller, bool sig, int num, int cnt){

    if(pos>=len)return cnt;
    if(dp[pos][smaller][sig][num][cnt]!=-1)return dp[pos][smaller][sig][num][cnt];
    int tot=0;
    int limit=9;
    if(!smaller)limit=s[pos]-'0';
    for(int i=0; i<=limit; i++){
        tot+=cal(pos+1, smaller||(i<limit), sig||(i>0), num, cnt+((num==0 && sig && i==0)||(num!=0 && i==num)));
    }
    return dp[pos][smaller][sig][num][cnt]=tot;
}

int main(){

    int t,n,m,total;
    while(t--){
        cin>>n>>m;

        for(int i=0; i<10; i++){
            str_to_int(m);
            len=s.size();
            memset(dp,-1,sizeof(dp));
            total=cal(0,0,0,i,0);

            if(n-1>0){
                str_to_int(n-1);
                len=s.size();
                memset(dp,-1,sizeof(dp));
                total-=cal(0,0,0,i,0);
            }

            if(i)cout<<' ';
            cout<<total;
        }
        cout<<endl;
    }

    return 0;
}
