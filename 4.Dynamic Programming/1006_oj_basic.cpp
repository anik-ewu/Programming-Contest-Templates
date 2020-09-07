#include<bits/stdc++.h>
using namespace std;
long long int a, b, c, d, e, f;
long long int mark[10005];
long long int fn( int n )
{
    if( n == 0 ) return a% 10000007;
    if( n == 1 ) return b% 10000007;
    if( n == 2 ) return c% 10000007;
    if( n == 3 ) return d% 10000007;
    if( n == 4 ) return e% 10000007;
    if( n == 5 ) return f% 10000007;
    if(mark[n]!=-1)return mark[n];
    else
    {
        mark[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;
        return mark[n];
    }
}
void init()
{
    for(int i=1; i<=10000; i++)
        mark[i]=-1;
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
         init();
        printf("Case %d: %d\n", ++caseno, fn(n) );


    }
    return 0;
}

/*
int a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
*/
