#include<bits/stdc++.h>
using namespace std;
#define S
string s[250],s1;
int a,b;
int ans=1;
void DFS(int pos1,int pos2)
{
    if(pos1<0||pos2<0||pos1>=b||pos2>=b)
        return;
    if(s[pos1][pos2]=='.')
        return;
    s[pos1][pos2]='.';
    DFS(pos1+1,pos2);
    DFS(pos1-1,pos2);
    DFS(pos1,pos2+1);
    DFS(pos1,pos2-1);

}
int main()
{
    int t,c,d,e,f,x,y,z,pos1,pos2,cas=0,ans;
    cin>>t;
    while(t--)
    {
        cin>>b;
        for(x=0; x<b; x++)
            cin>>s[x];
        ans=0;
        for(x=0; x<b; x++)
            for(y=0; y<b; y++)
                if(s[x][y]=='x')
                {
                    ans++;
                    DFS(x,y);
                }

        cout<<"Case "<<++cas<<": "<<ans<<endl;
    }
    return 0;

}
