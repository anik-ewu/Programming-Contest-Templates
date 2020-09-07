#include<bits/stdc++.h>
using namespace std;
typedef  unsigned long long int lld;
map <char, lld>mp;

int main()
{
    lld a,b,c,i,j,k,n,divider,sum,ans;
    string s;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>s;
        for(j=0; j<s.size(); j++)
        {
            mp[s[j]]++;
        }
        ans=1;
        for(j=0; j<s.size(); j++)
        {
            ans*=(j+1);
        }
        for(j=65; j<=90; j++)
        {
            char x= char(j);
            if(mp[x]>1)
                while(mp[x]>1)
                {
                    ans/=mp[x];
                    mp[x]--;
                }
        }
        mp.clear();

        cout<<"Data set "<<i<<": "<<ans<<endl;
    }
    return 0;
}
