#include<bits/stdc++.h>
using namespace std;

map < char, int> mp,mps;
map < int, char > mp1,mp2;
void init()
{
    int i;
    for(i=0; i<26; i++)
    {
        mp[char(int('a')+i)]=i+1;
        mp1[i+1]=char(int('a')+i);
    }

    for(i=0; i<26; i++)
    {
        mps[char(int('A')+i)]=i+1;
        mp2[i+1]=char(int('A')+i);
    }
}
int main()
{
    init();
    string s;
    int n,i,j,k,a,b;
    cin>>n>>s>>k;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            int x=mps[s[i]];
            int y=x+k;
            y=y%26;
            if(y==0)
                y=26;
            cout<<mp2[y];
        }
        else if(s[i]>='a' && s[i]<='z')
        {

            int x=mp[s[i]];
            int y=x+k;
            y=y%26;
            if(y==0)
                y=26;
            cout<<mp1[y];
        }
        else
            cout<<s[i];
    }
    cout<<endl;

    return 0;

}
