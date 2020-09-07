#include<bits/stdc++.h>
using namespace std;
#define sz 1001
int dp[sz][sz];
vector < string > v,va,lcm;

void printlcm(int n, int m){
    lcm.clear();
    while(n && m){
          if(v[n-1]==va[m-1]){
            lcm.push_back(v[n-1]);n--;m--;
          }
          else{
            if(dp[n-1][m]>=dp[n][m-1])n--;
            else m--;
          }
    }
    reverse(lcm.begin(),lcm.end());
    for(int i=0; i<lcm.size(); i++){
        if(i)cout<<' ';
        cout<<lcm[i];
    }
    cout<<endl;
}

void LCM(int n, int m){
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(v[i-1]==va[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printlcm(n,m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int cnt=1;
    string s,p;
    stringstream line;
    while(getline(cin,s)){
         line.clear();
         if(s[0]!='#')
            line<<s;
         if(s[0]=='#')
            cnt++;
         if(cnt==1){
            while(line>>s)
                v.push_back(s);///breaking line into words
         }
         else if(cnt==2){
            while(line>>s)
                va.push_back(s);///breaking line into words
         }
         else if(cnt==3){
            LCM(v.size(),va.size());///find lcm
            cnt=1;///reset for new case
            v.clear();
            va.clear();
         }
    }
    return 0;
}
