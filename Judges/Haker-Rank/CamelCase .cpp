#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define S 1000005
#define mod 1000000009
string s,p;
char Q,Z;
double l,r;
bool flag=true;
vector < int > v;
int main()
{
    int a,b,c=0,i,j,k,t,n,m,q,x,y;
    cin>>s;
    for(i=0; i<s.size(); i++)
    {
        if(i==0 && s[i]>='a' && s[i]<='z')
            c++;
        if(s[i]>='A' && s[i]<='Z')
            c++;
    }
    cout<<c<<endl;


    return 0;
}


