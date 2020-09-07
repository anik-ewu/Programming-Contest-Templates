#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{

    ll a,b,c,n,m;
    bool flag;
    vector < ll > v;
    while(cin>>n>>m)
    {
        flag=true;
        if(n<2 || m<2)
        {
            flag=false;
        }
        else
        {
            while(n>0)
            {
                if(n%m!=0 && n!=1)
                {
                    flag=false;
                    break;
                }
                v.push_back(n);
                n/=m;
            }
        }
        if(flag)
        {
            for(ll i=0; i<v.size(); i++)
            {
                cout<<v[i];
                if(i+1==v.size())
                    cout<<endl;
                else
                    cout<<' ';
            }
        }
        else
            cout<<"Boring!"<<endl;
        v.clear();

    }
    return 0;
}
