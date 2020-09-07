#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector< int > v;
    int a,n,i;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0; i<n; i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(i=0; i<n; i++)
        {
            cout<<v[i];
            if(i+1==n)
                cout<<endl;
            else
                cout<<' ';
        }
        v.clear();
    }
    return 0;
}
