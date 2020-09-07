#include<bits/stdc++.h>
using namespace std;

string a="abcdefghijklmnopqrstuvwxyz";
map < string , int > mp;

void pre_cal()
{
    int i,j,k,l,m,cost=1;
    string s;
    for(i=0; i<26; i++)
    {
        s="";
        s+=a[i];
        mp[s]=cost++;
    }
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            s="";
            s+=a[i];
            s+=a[j];
            mp[s]=cost++;
        }
    }

    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            for(k=j+1; k<26; k++)
            {
                s="";
                s+=a[i];
                s+=a[j];
                s+=a[k];
                mp[s]=cost++;
            }
        }
    }

    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            for(k=j+1; k<26; k++)
            {
                for(l=k+1; l<26; l++)
                {
                    s="";
                    s+=a[i];
                    s+=a[j];
                    s+=a[k];
                    s+=a[l];
                    mp[s]=cost++;
                }
            }
        }
    }
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            for(k=j+1; k<26; k++)
            {
                for(l=k+1; l<26; l++)
                {
                    for(m=l+1; m<26; m++)
                    {
                        s="";
                        s+=a[i];
                        s+=a[j];
                        s+=a[k];
                        s+=a[l];
                        s+=a[m];
                        mp[s]=cost++;
                    }
                }
            }
        }
    }
}

int main()
{
    pre_cal();
    string s;
    while(cin>>s)
    {
        cout<<mp[s]<<endl;
    }
    return 0;
}
