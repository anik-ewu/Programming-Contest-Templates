#include<bits/stdc++.h>
using namespace std;

vector < int > v[100];
queue < int > q;

int main()
{
    int n,i,j,a,b,cas=1;
    while(1)
    {

        for(j=1; j<=20; j++)
        {
            cin>>a;
            for(i=1; i<=a; i++)
            {
                cin>>b;
                v[a].push_back(b);
            }
        }
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a>>b;
        }
        cout<<"ok"<<endl;

    }
    return 0;


}
