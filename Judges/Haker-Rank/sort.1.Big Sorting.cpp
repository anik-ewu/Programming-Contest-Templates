#include<bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{
    if(a.size()==b.size() && a>b || a.size()>b.size())
        return true;
    return false;
}

int main()
{

    vector <string > v;
    string s,p;
    int n,i,j,k;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),check);
    for(i=v.size()-1; i>=0; i--)
        cout<<v[i]<<endl;
    return 0;
}
