#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector < ll > v;
int main()
{
    ll n,m,i;
    bool flag;
    while(cin>>n>>m)
    {
        if(n<2 || m<2 || m>n)
            cout<<"Boring!"<<endl;
        else
        {
            flag=true;
            while(n>1)
            {
                if(n%m!=0)
                    flag=false;
                v.push_back(n);
                n/=m;
            }

            v.push_back(1);

            if(flag==true)
            {
                for(i=0; i<v.size(); i++)
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
        }

        v.clear();

    }
    return 0;
}
