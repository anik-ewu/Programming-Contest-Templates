#include<bits/stdc++.h>
using namespace std;
string s,sp;
int string_to_int(string s){
    stringstream ss(s);
    int num;
    ss>>num;
    return num;
}

int main(){


    ///freopen("out.txt","w",stdout);

    double t1,t2,dis;
    double a,b,c,x=0,y=0,z=0,speed=0,sum=0.0;
    stringstream ss;
    while(getline(cin,s)){
        sp=s;
        for(int i=0; i<s.size(); i++){
            if(s[i]==':')s[i]=' ';
        }
        ss.clear();
        ss<<s;
        ss>>s;
        a=(s[0]-'0')*10+(s[1]-'0');
        ss>>s;
        b=(s[0]-'0')*10+(s[1]-'0');
        ss>>s;
        c=(s[0]-'0')*10+(s[1]-'0');

        t1=(x*60.0*60.0)+(y*60.0)+z;
        t2=(a*60.0*60.0)+(b*60.0)+c;
        dis+=((t2-t1)/3600.0)*speed;

        if(sp.size()<=8){
        cout<<sp;
        printf(" %0.2lf km\n",dis);
        }
        else{
        ss>>s;
        speed=string_to_int(s);
        }
        x=a;y=b;z=c;
      }
      return 0;
}

