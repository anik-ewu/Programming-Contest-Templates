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
int arry[200];
int main()
{
    int a,b,c,i,j,k,t,n,m,q,x,y;
    cin>>t;
    for(i=1; i<=t; i++)
    {

        cin>>a>>s;
        arry[a]++;
    }
    for(i=0; i<100; i++)
    {
        if(i>0)
            arry[i]+=arry[i-1];
        cout<<arry[i];
        if(i<99)
            cout<<' ';
    }
    cout<<endl;

    return 0;
}

