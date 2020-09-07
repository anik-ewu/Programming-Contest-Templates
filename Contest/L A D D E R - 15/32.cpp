///Date     : 20.5.2020
///Tags     : Implementation
///Comments : Just because someone stumbles, loses their way, doesn't mean they lost forever.

#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int dis(int l, int r){
    if(r<l)swap(l,r);
    if(r>=l){
        return min((r-l),(26-r)+l);
    }
}

int cal(int a, int b, int k){

    while(a<=b && s[a]==s[n-a])a++;///left index with miss match
    while(b>=a && s[b]==s[n-b])b--;///right index with miss match
    if(a>b)return 0;///already a palindrome

    int sum=min(abs(k-a),abs(k-b));
    if(abs(a-k)<=abs(k-b)){
        while(a<=b){
            if(s[a]!=s[n-a])sum+=dis(s[a],s[n-a]);
            if(a<b)sum++;///moving cursor
            a++;
        }
    }
    else{
        while(b>=a){
            if(s[b]!=s[n-b])sum+=dis(s[b],s[n-b]);
            if(b>a)sum++;///moving cursor
            b--;
        }
    }
    return sum;
}

int main(){

    int mn,m,k;
    cin>>n>>k>>s;
    m=n;n--;k--;
    mn=cal(0,(m/2)-1,k);///first half
    mn=min(mn,cal((m/2)+(m%2),n,k));///second half
    cout<<mn<<endl;

    return 0;
}


