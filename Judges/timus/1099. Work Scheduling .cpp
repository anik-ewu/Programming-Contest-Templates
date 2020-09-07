#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define sf              scanf
#define pf              printf
#define pb              push_back
#define nl              printf("\n")
#define ll              long long int

#define F               first
#define S               second

#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))

#define MOD             1000000007
#define MX              INT_MAX
#define Sz              300
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

char f,g;
string s,p;
double aa,bb,cc;
int arr[Sz];
vector< int > v,va,vb[Sz];
map< int, int > mp;

vector < pair < int, int > > vp;
int main()
{
    int a,b,c, n,m,t, i,j,k, x,y,z;

    sf("%d",&n);
    x=0;
    while(sf("%d%d",&a,&b)==2)
    {
        if(!arr[a] && !arr[b] && a!=b)
        {
            x++;
            vp.pb(make_pair(a,b));
        }
        arr[a]=1;
        arr[b]=1;
    }
    pf("%d",x*2);
    nl;
    for(i=0; i<vp.size(); i++)
    {
        pf("%d %d",vp[i].F,vp[i].S);
        nl;
    }
    return 0;
}
