#include<iostream>
using namespace std;

int main()
{
    long long int i,r,k,num,arr[64000];
    while(cin>>num)
    {
        if(num==0)break;
        i=0,r,k=0;
        while(num!=0)
        {
            r = num%2;
            if(r==1)
                k++;
            arr[i++] = r;
            num /= 2;
        }

        cout<<"The parity of ";
        for(int j=i-1; j>=0; j--)
            cout<<arr[j];
        cout<<" is "<<k<<" (mod 2)."<<endl;
    }
    return 0;
}
