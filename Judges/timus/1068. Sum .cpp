N#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
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
#define Sz              10005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

char f,g;
string s,p;
double aa,bb,cc;
int arr[Sz],brr[Sz];
vector< int > v,va,vb[Sz];
map< int, int > mp;

int main()
{
    ll a,b,c, n,m,t, i,j,k, x,y,z;

    sf("%lld",&n);
    x=0;
    if(n<0)
    {
        n*=-1;
        x=1;
    }
    a=(n*(n+1))/2;
    if(n==0)
        a=1;

    if(x)
    {
        a--;
        a*=-1;
        pf("%lld",a);
    }
    else
        pf("%lld",a);
    nl;


    return 0;
}

