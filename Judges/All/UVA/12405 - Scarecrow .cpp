#include<bits/stdc++.h>
using namespace std;
#define S 100005

string s,p;
vector < int > v;
int arr[S],brr[S];


int main()
{
    int t,a,b,c,i,j,k,n,m,sum=0;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n;
        cin>>s;
        int x=0;
        sum=0;
        for(j=0; j<n; j++)
        {
            if(s[j]=='.')
            {
                j+=2;
                sum++;
            }
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }

    return 0;
}
