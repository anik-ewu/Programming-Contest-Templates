
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
    int a,b=0,c=1,i,j,k,t,n,m,q,x,y;
    cin>>n>>m;
    b=n/2;
    if(n%2!=0)
        b++;
    if(m>2)
    {
        c=m/2;
        if(m%2!=0)
            c++;
    }
    b*=c;
    cout<<b<<endl;

    return 0;
}

