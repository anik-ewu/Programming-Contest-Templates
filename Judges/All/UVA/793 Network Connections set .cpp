#include<bits/stdc++.h>
using namespace std;
#define pf printf

int parent[800],Ran[800];

void Make_Set(int x)
{
    parent[x]=x;
    Ran[x]=0;
}

int Find(int x)
{
    if(x!=parent[x])
        parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y)
{
    int PX=Find(x),PY=Find(y);
    if(PX==PY)
        return;

    if(Ran[PX]>Ran[PY])
        parent[PY]=PX;
    else
    {
        parent[PX]=PY;
        if(Ran[PX]==Ran[PY])
            Ran[PY]++;
    }
}



int main()
{
    char f;
    string s;
    int t,n,a,b,i,j,right,wrong;
    cin>>t;

    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        getchar();

        for(j=1; j<=n; j++)
            Make_Set(j);
        right=0;
        wrong=0;
        while(true)
        {
            if(!getline(cin,s) || s.empty())
                break;
            sscanf(s.c_str(),"%c %d %d",&f,&a,&b);

            if(f=='c')
                Union(a,b);
            else
            {
                if(Find(a)==Find(b))
                    right++;
                else
                    wrong++;
            }

        }
        if(i>1)
            pf("\n");
        pf("%d",right);
        pf(",");
        pf("%d\n",wrong);

    }

    return 0;
}
