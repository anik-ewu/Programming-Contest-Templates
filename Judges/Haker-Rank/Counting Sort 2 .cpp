#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define S 1000005
#define mod 1000009
string s,p;
char Q,Z;
double l,r;
bool flag=true;
vector < int > v;
int arry[200];
int main()
{
    int a,b,c,i,j,k,t,n,m,q,x,y;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        arry[a]++;
    }
    for(i=0; i<100; i++)
    {
        q=arry[i];
        while(q--)
        {
            cout<<i;
            if(q==0 && i+1==100)
                cout<<endl;

            else
                cout<<' ';
        }
        if(arry[99]==0)
            cout<<endl;

    }
    return 0;
}

