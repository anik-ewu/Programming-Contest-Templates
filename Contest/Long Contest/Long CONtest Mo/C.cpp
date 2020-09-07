#include<bits/stdc++.h>
using namespace std;
#define MAXN    50050
#define SQRSIZE 300
int len,n;
int arr[MAXN];
int block[SQRSIZE][MAXN];

int query(int l, int r, int val){

    int sum = 0;
    int cl = l / len;
    int cr = r / len;
    int mn=-1,mx=-1;
    if(val==0)
        mn=0;

    if (cl == cr)
        for (int i=l; i<=r; ++i){
            if(arr[i]==val && mn==-1){
                mn=i+1;
            }
            else if(arr[i]==val){
                mx=i+1;
            }
        }
    else{
        for (int i=l, end=(cl+1)*len-1; i<=end; ++i){
            if(arr[i]==val && mn==-1){
                mn=i+1;
            }
            else if(arr[i]==val){
                mx=i+1;
            }
        }
        for (int i=cl+1; i<=cr-1; ++i){
            if(block[i][val] && mn==-1){
                mn=block[i][val]+1;
            }
            else if(block[i][val]){
                mx=block[i][val]+1;
            }
        }
        for (int i=cr*len; i<=r; ++i){
            if(arr[i]==val && mn==-1){
                mn=i+1;
            }
            else if(arr[i]==val){
                mx=i+1;
            }
        }
    }
    if(mn!=-1 && mx!=-1)
     return mx-mn;
     return 0;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int q,i,l,r,val;
    cin>>n>>q;
    len=sqrt(n)+1;
    for(i=0; i<n; i++){
        cin>>arr[i];
        if(i)
            arr[i]+=arr[i-1];
    }
    for(i=0; i<n; i++){
        block[i/len][arr[i]]=i;
    }
    while(q--){
        cin>>l>>r;
        l--;r--;///0 base indexing
        val=arr[r];
        cout<<query(l,r,val)<<endl;
    }
    return 0;
}
