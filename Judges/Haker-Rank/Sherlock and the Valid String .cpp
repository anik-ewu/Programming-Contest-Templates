#include<bits/stdc++.h>
using namespace std;
int  mp[29];
map < char, int > mps;

void init()
{
    int i;
    for(i=0; i<26; i++)
        mps[char(int('a')+i)]=i+1;
}

int main()
{
    init();
    string s;
    int i,j,k,a,b,c=0;
    cin>>s;
    for(i=0; i<s.size(); i++)
    {
        a=mps[s[i]];
        mp[a]++;
    }
    for(i=1; i<=26; i++)
    {
        if(mp[i]!=0)
        {
            for(j=i+1; j<=26; j++)
            {
                if(mp[j]!=0 && mp[i]!=mp[j])
                {
                    c++;
                    if(c>1)
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    }
                    if(mp[i]==1)
                        mp[i]=0;
                    else if(mp[j]==1)
                        mp[j]=0;
                    else
                    {
                        b=abs(mp[i]-mp[j]);
                        if(b>1)
                        {
                            cout<<"NO"<<endl;
                            return 0;
                        }
                        else if(b==1)
                        {
                            if(mp[i]<mp[j])
                                mp[i]+=1;
                            else
                                mp[j]+=1;
                        }

                    }
                }
            }
        }

    }
    cout<<"YES"<<endl;
    return 0;
}
