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
int main()
{
    int a,b,c,i,j,k,t,n,m,q,x,y;
    char arry[200];
    cin>>s;
    n=0;
    c=0;
    for(i=0; i<s.size()-1; i++)
    {
        if(s[i]!=s[i+1])
        {
            n+=1;
            arry[n]=s[i];
            c++;
            if(arry[n-1]==arry[n] && c!=0)
            {
                n-=2;
                c=1;
            }
        }
        else
            i++;
    }
    if(s.size()==1)
    {
        cout<<s<<endl;
        return 0;
    }
    if(n==0)
    {
        if(s[s.size()-1]!=s[s.size()-2])
            n+=1;
        arry[n]=s[s.size()-1];
    }
    if(arry[n]==s[s.size()-1])
        n--;
    else
    {
        n+=1;
        arry[n]=s[s.size()-1];
    }
    if(n<=0)
        cout<<"Empty String"<<endl;
    else
    {
        for(i=1; i<=n; i++)
            cout<<arry[i];
        cout<<endl;
    }
    return 0;
}
