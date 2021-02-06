/*#include <stdio.h>
int fib(int n)
{
    if(n<3) return 1;
    return fib(n-2) + fib(n-1);
}

int main()
{
    int n, v;
    scanf("%d", &n);
    v = fib(n);
    printf("%d\n", v);
    return 0;
}*/
#include<iostream>
using namespace std;
int fibonaci(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return fibonaci(n-1)+fibonaci(n-2);
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<fibonaci(n)<<endl;
    }
}
