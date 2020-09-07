#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
set<char> S;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
char arr[100005],brr[100005];

char find(char a)
{
    if(arr[a]==a)
        return a;
    return arr[a]=find(arr[a]);
}

void Union(char a, char b)
{
    arr[find(b)]=find(a);
}
int main()
{
    int a,b,c,  n,m,t, l,r, i,j,k,  x,y,z;
    char e;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>e;
        while(cin>>f>>g)
        {
            if(f<g)
                swap(f,g);
            Union(f,g);
        }
    }
    g='A';
    for(i=0; i<=n; i++)
    {
        g=char('A'+i);
        S.insert(find(arr[g]));
        if(g==e)
            break;
    }
    cout<<S.size();
    S.clear();
    return 0;
}
