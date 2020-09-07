#include<bits/stdc++.h>
using namespace std;
#define S 100005
typedef long long int ll;

char f,g;
int n,m, x,y,z;
double dd,dd2,dd3;

string s,p;
int arr[S],brr[S],crr[S];
vector < int > v,va,vb,vc;

map < string, int > mp;

queue< int > q,q2;
pair < int, int> pp,pp2;
priority_queue<int> pq;

int main()
{
    int a,b,c, i,j,k, t,q;

    cin>>s;

    for(i=1; i<=s.size(); i++)
    {
        x=i;
        p="";
        for(j=0; j+i<=s.size(); j++)
        {
            for(k=j; k<j+x && k<s.size(); k++)
                p+=s[k];
            cout<<p<<endl;
            p="";
        }
    }

    return 0;
}
