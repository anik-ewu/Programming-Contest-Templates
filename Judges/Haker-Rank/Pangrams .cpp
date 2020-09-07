#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define S 1000005
#define mod 1000000009
string s,p;
char Q,Z;
double l,r;
bool flag=true;
vector < int > v;
map < char, int > mp;

void init()
{
    char x='a';
    for(int i=0; i<26; i++)
    {
        x=char(int('a'+i));
        mp[x]=1;
    }
}

int main()
{
    int a,b,c,i,j,k,t,n,m,q,y;
    char x;
    getline(cin,s);
    init();
    for(i=0; i<s.size(); i++)
    {
        x=s[i];
        if(x>='A' && x<='Z')
            x=x-'A'+'a';
        mp[x]=0;
    }
    x='a';
    for(i=0; i<26; i++)
    {
        x=char(int('a'+i));
        if(mp[x]==1)
        {
            cout<<"not pangram"<<endl;
            return 0;
        }
    }
    cout<<"pangram"<<endl;

    return 0;
}

