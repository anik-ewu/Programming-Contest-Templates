#include<iostream>
using namespace std;
int sum(int n)
{
    if(n==0)return 1;
    return n+sum(n-1);
    //cout<<n<<' ';


}

int main()
{
    int a;
    while(cin>>a)
        cout<<sum(a)<<endl;
    return 0;
}
