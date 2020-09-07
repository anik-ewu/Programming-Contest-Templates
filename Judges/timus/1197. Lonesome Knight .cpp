
#include<iostream>
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

char f[3],g;
string s,p;
double aa,bb,cc;
int arr[Sz],brr[Sz];
vector< int > v,va,vb[Sz];
map< int, int > mp;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};


int main()
{
    int a,b,c, n,m,t, i,j,k, x,y,z;

    sf("%d",&n);
    while(n--)
    {
        sf("%s",&f);
        a=(f[0]-'a')+1;
        b=f[1]-'0';
        z=0;
        for(i=0; i<8; i++)
        {
            x=a+dx[i];
            y=b+dy[i];

            if(x>0 && x<9 && y>0 && y<9)
                z++;
        }
        pf("%d",z);
        nl;
    }

    return 0;
}

