#include<bits/stdc++.h>
using namespace std;
#define range 100
int node1,node2,cost,source,total_node;
int uni[100];
priority_queue<pair<int,pair<int,int> > > PQ;
int init()
{
    int x;
    for(x=0; x<100; x++)
    {
        uni[x]=x;
    }
    while(!PQ.empty())
        PQ.pop();
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
int kruskal_input()
{
    cin>>total_node;
    while(cin>>node1>>node2>>cost)
    {
        if(node1==0&&node2==0&&cost==0)
            break;
        PQ.push(make_pair((cost*-1),make_pair(node1,node2)));
    }
    cin>>source;
}
int kruskal()
{
    int count1=0,b,c,x,y,z,ans=0;
    while(count1<total_node-1)
    {
        node1=PQ.top().second.first;
        node2=PQ.top().second.second;
        if(find(node1)==find(node2))
            PQ.pop();
        else
        {
            Union(node1,node2);
            count1++;
            ans=ans+(PQ.top().first*-1);
            cout<<node1<<" "<<node2<<" "<<PQ.top().first<<endl;
            PQ.pop();
        }
    }
    return ans;

}
int main()
{
    int a,b,c,d,e,f,g,h,x,y,z,node1,node2,cost,source;
    init();
    kruskal_input();
    cout<<kruskal()<<endl;
    return 0;
}
/*input:
8
1 2 4
1 4 10
1 5 2
5 1 2
4 1 10
2 1 4
2 3 18
3 2 18
2 4 8
4 2 8
3 4 11
4 3 11
4 5 5
5 4 5
4 7 11
7 4 11
4 8 9
8 4 9
6 7 1
7 6 1
6 8 2
8 6 2
0 0 0
1
*/

