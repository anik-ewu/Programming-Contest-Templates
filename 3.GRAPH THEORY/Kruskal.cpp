#include<bits/stdc++.h>
using namespace std;

vector < pair < int, pair< int, int > > > vp;
int uni[100];

int init()
{
    int x;
    for(x=0; x<100; x++)
    {
        uni[x]=x;
    }
}

int find(int num)
{
    if(uni[num]==num)
        return num;
    else
        return uni[num]=find(uni[num]);
}
int Union(int num1,int num2)
{
    uni[find(num1)]=find(num2);
}


void kruskal()
{
    int con=0,mst=0,x,y,z;
    for(int i=0; i<vp.size(); i++)
    {
        x=vp[i].second.first;
        y=vp[i].second.second;

        if(find(x)==find(y))
            continue;
        else
        {
            Union(x,y);
            con++;
            mst+=vp[i].first;
            cout<<x<<' '<<y<<' '<<vp[i].first<<endl;
        }
    }
    cout<<mst<<endl;
}

int main()
{

    int i,j,a,b,w,n,sum=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b>>w;
        sum+=w;
        vp.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(vp.begin(),vp.end());
    init();
    cout<<endl;
    kruskal();


    return 0;
}



