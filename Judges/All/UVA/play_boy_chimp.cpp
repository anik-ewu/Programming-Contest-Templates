#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,t,i,j,k,a,q;
    vector< int > arry;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        scanf("%d",&a);
        arry.push_back(a);
    }
    vector< int > ::iterator low,up;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&a);

        low=lower_bound(arry.begin(),arry.end(),a);
        up=upper_bound(arry.begin(),arry.end(),a);
        int l,u;
        l=low-arry.begin();
        u=up-arry.begin();
        if(l==0)
            printf("X ");
        else
            printf("%d ",arry[l-1]);
        if(u==arry.size())
            printf("X\n");
        else
            printf("%d\n",arry[u]);
    }
    return 0;
}

