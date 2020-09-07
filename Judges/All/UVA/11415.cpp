#include<iostream>
using namespace std;

int func(int n)
{
    int ans = 0;
    for(int i=0; ; i++)
    {
        if( count( fact(i) )\le n)
         ans++;
        else
        return ans;
    }
}

int main()
{
  int a,b,c,n;
  cin>>n;
  while(n>0)
  {
      cin>>a;
      cout<<func(a)<<endl;
      n--;
  }
  return 0;

}
