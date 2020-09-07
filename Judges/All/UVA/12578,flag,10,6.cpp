#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)

int main()
{
    int n,a,b;
    double g,f,k,c;
    cin>>n;

    while(n>0)
    {
        cin>>a;
        g=(2*a)/10.0;
        c=PI*g*g;

        k=(6*a)/10.0;
        f=k*a;
        f=f-c;
        printf("%0.2lf %0.2lf\n",c,f);
        n--;
    }
    return 0;
}
