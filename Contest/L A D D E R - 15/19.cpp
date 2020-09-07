#include<bits/stdc++.h>
using namespace std;

int val;
int len;
string s,ss;

double rec(int pos, int sum){
    if(pos>=len)return sum==val?1.0:0.;
    if(ss[pos]=='+')return rec(pos+1,sum+1);
    if(ss[pos]=='-')return rec(pos+1,sum-1);
    return 0.5*rec(pos+1,sum+1)+0.5*rec(pos+1,sum-1);
}

int main(){
    cin>>s>>ss;
    len=s.size();
    for(int i=0; i<s.size(); i++){
        s[i]=='+'?val++:val--;
    }
    cout<< fixed << setprecision(10)<<rec(0,0)<<endl;


    return 0;
}
