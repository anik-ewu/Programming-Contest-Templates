#include<iostream>
using namespace std;
odd_arry(int i,int j,int *n,int *a)
{

    if(i==*n)
    {
        *n=j;
        return 0;
    }
    if(a[i]%2==0)
        a[j++]=a[i];
    odd_arry(i+1,j,n,a);

}
int main()
{
    int n;
    while(cin>>n)
    {
        int a[10];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        odd_arry(0,0,&n,a);
        for(int i=0; i<n; i++)
            cout<<a[i]<<endl;
    }
}
