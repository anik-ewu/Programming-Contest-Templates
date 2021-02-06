#include<bits/stdc++.h>
using namespace std;

string s,p;
int dp[110][110];

void init()
{
    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            dp[i][j]=-1;
}

int palindrome(int l, int r)
{
    if(l>=r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(s[l]==s[r])
        dp[l][r]=palindrome(l+1,r-1);

    else
    {
        int a=1+palindrome(l+1,r);
        int b=1+palindrome(l,r-1);
        dp[l][r]=min(a,b);
    }
    return dp[l][r];
}

int main()
{
    int a,b,c, m,t, i,j,k;

    cin>>t;
    getchar();
    for(i=1; i<=t; i++)
    {
        cin>>s;
        init();
        cout<<"Case "<<i<<": "<<palindrome(0,s.size()-1)<<endl;
    }

    return 0;
}
