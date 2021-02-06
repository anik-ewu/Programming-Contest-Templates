#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int prime(int i,int sr, int n)
{
    if(i<n)
    {
        if(n<2)return 1;
        if(i>sr)return 0;
        if(n%i==0)return 1;
        return prime(i+1,sr,n);
    }
    return 0;
}

int main()
{
    int a;
    while(cin>>a)
    {
        if(prime(2, (int)sqrt(a), a)==0) printf("prime\n");
        else printf("not prime\n");
    }
}
