#include<bits/stdc++.h>

using namespace std;
string s[26];

int main()
{
    int n,i,j,k,x,y,z,a=0;
    cin>>n;

    for(i=1; i<=n; i++)
        cin>>s[i];
    for(i=1; i<=n; i++)
    {
        x=0;
        for(j=0; j<n; j++)
        {
            if(s[i][j]=='1')
                x++;
            else
            {
                if(x>1)
                    a+=x-1;
                x=0;
            }
        }
    }
    cout<<a<<endl;
    return 0;
}
