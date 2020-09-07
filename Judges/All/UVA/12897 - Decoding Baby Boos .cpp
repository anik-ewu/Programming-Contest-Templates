#include<bits/stdc++.h>
using namespace std;
map<int, char > alphabet;
map<char, int > position;

void init()
{
    for(int i=0; i<26; i++)
    {
        alphabet[i+1]=char(int('A'+i));
        position[alphabet[i+1]]=i+1;
    }
}

void change(char a, char b)
{
    for(int i=1; i<=26; i++)
        if(alphabet[i]==b)
            alphabet[i]=a;
}

int main()
{
    string s;
    char a,b,x;
    int i,j,k,n,r;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        init();
        cin>>s>>r;
        while(r--)
        {
            cin>>a>>b;
            change(a,b);
        }
        for(j=0; j<s.size(); j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                int pos=position[s[j]];
                cout<<alphabet[pos];
            }
            else
                cout<<s[j];
        }
        cout<<endl;
    }
    return 0;
}
