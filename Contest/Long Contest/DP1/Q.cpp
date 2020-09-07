#include<bits/stdc++.h>
using namespace std;
string s,p;
int ex,n,m;
int dp[21][21];
int cal(int i, int j){
    if(i>=n) return m-j;
    if(j>=m) return n-i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==p[j])
        return dp[i][j]=cal(i+1,j+1);
    int a=1+cal(i+1,j);
    int b=1+cal(i,j+1);
    int c=1+cal(i+1,j+1);
    return dp[i][j]=min(a,min(b,c));
}
void pp(char x, char y, int val){
    printf("%c%c%02d",x,y,val);
    return;
}

void path(int i, int j, int len, int add){

    if(i>=n){
        for(int k=j; k<m; k++){
            pp('I',p[k],k+1);///no of k+1+add, as we are inserting at the end of s
        }
          cout<<"E"<<endl;
        return;
    }
    else if(j>=m){
        for(int k=i; k<n; k++){
            pp('D',s[k],k+1+add);
            add--;
        }
          cout<<"E"<<endl;
        return;
    }
    else if(s[i]==p[j]){
        path(i+1,j+1,len,add);
    }
    else if(cal(i+1,j)+1==len){
        pp('D',s[i],i+1+add);
        path(i+1,j,len-1,add-1);
    }
    else if(cal(i,j+1)+1==len){
        pp('I',p[j],i+1+add);
        path(i,j+1,len-1,add+1);
    }
    else{
        pp('C',p[j],i+1+add);
        path(i+1,j+1,len-1,add);
    }

}
void breakline(string ss){

    int i=0,j=0;
    s=p="";
    while(i<ss.size()){
        if(ss[i]==' '){
            i++;j=1;continue;
        }
        if(!j)s+=ss[i];
        if(j)p+=ss[i];
        i++;
    }
}

int main(){
    string line;
    while(getline(cin,line)){
        breakline(line);///dividing the line into two strings
        if(s=="#")break;
        n=s.size(); m=p.size();
        memset(dp,-1,sizeof(dp));
        cal(0,0);
        path(0,0,cal(0,0),0);
    }
    return 0;
}
