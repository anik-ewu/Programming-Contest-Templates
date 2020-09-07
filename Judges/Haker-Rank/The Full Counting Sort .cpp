#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define S 1000005
#define mod 1000000009
string s,p;
char Q,Z;
double l,r;
bool flag=true;
vector < string > vs[200];
int main()
{
    int a,b,c,i,j,k,t,n,m,q,x,y;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>s;
        if(i<=n/2)
            vs[a].push_back("-");
        else
            vs[a].push_back(s);
    }
    x=0;
    for(i=0; i<100; i++)
    {
        q=vs[i].size();
        for(j=0; j<q; j++)
        {
            cout<<vs[i][j];
            if(x<n)
                cout<<' ';
        }
    }
    cout<<endl;
    return 0;
}










