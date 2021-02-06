#include<bits/stdc++.h>
using namespace std;
string a;
void fill_string(int p)
{
    char x='A';
    for(int i=0; i<p; i++)
    {
        string b;
        b=char(int(x)+i);
        a+=b;
    }
}
int main()
{

    int n,i,j,k,p,q;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>p>>q;
        cout<<"Case "<<i<<":"<<endl;
        fill_string(p);
        for(j=1; j<=q; j++)
        {

            cout<<a<<endl;
            if(! next_permutation(a.begin(),a.end()))
                break;

        }
        a="";
    }
    return 0;
}
