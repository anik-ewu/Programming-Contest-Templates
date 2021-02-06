#include<iostream>
using namespace std;
int binarySearch(int i, int j, int v, int *a)
{
    int m;
    if(i > j) return -1;
    m = (i+j)/2;
    if(a[m] < v) return binarySearch(m+1, j, v, a);
    if(a[m] > v) return binarySearch(i, m-1, v, a);
    return m;
}
int main()
{
    int a[10],b,i,j,n,x,y;
    for(i=1; i<=5; i++)
    {
        a[i]=i;
    }
    cin>>j;
    while(j>0)
    {
        cin>>y;
        x=binarySearch(1,5,y,a);
        if(x==-1)
            cout<<"not found"<<endl;
        else
            cout<<x<<endl;
        j--;
    }
}
