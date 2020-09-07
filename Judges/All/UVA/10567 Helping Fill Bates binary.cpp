#include<bits/stdc++.h>
using namespace std;
bool flag;
string s,ss;
vector< int > v[123];

int main(){

    int t,i,start,pos;
    cin>>s;
    for(i=0; i<s.size(); i++){
        v[s[i]].push_back(i);
    }
    cin>>t;
    while(t--){
        cin>>ss;
        flag=true,pos=-1;
        for(i=0; i<ss.size(); i++){
            pos=upper_bound(v[ss[i]].begin(),v[ss[i]].end(),pos)-v[ss[i]].begin();
            if(pos==v[ss[i]].size()){
                flag=false;break;
            }
            pos=v[ss[i]][pos];
            if(i==0)start=pos;
        }
        if(flag){
            cout<<"Matched "<<start<<' '<<pos<<endl;
        }
        else{
            cout<<"Not matched"<<endl;
        }
    }
    return 0;
}
