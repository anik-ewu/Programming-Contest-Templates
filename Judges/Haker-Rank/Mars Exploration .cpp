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
    for(i=0; i<s.size(); i+=3)
    {
        if(s[i]!='S')
            c++;

        if(s[i+1]!='O')
            c++;

        if(s[i+2]!='S')
            c++;
    }
    cout<<c<<endl;

    return 0;
}

