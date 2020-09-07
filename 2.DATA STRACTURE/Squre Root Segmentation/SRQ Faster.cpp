#include<bits/stdc++.h>
using namespace std;
int len;
vector< int >arr(100);
vector< int >block(10);

int query(int l, int r){

    int sum = 0;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r)
        for (int i=l; i<=r; ++i)
            sum += arr[i];
    else{
        for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
            sum += arr[i];
        for (int i=c_l+1; i<=c_r-1; ++i)
            sum += block[i];
        for (int i=c_r*len; i<=r; ++i)
            sum += arr[i];
    }
    return sum;
}

int main(){

    int n,i;
    cin>>n;
    len=sqrt(n)+1;
    ///preprocessing
    for(i=0; i<n; i++){
        cin>>arr[i];
        block[i/len]+=arr[i];
    }
    ///query sum on l r
    int l,r;
    while(cin>>l>>r){
        cout<<query(l,r)<<endl;
    }
    return 0;
}
