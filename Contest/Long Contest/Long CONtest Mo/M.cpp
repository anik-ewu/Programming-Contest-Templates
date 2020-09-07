#include<bits/stdc++.h>
using namespace std;

#define sz 100005
int len;
int arr[sz];
int block[320][sz];

int query(int l, int r, int k){
    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
         for(int i=l; i<=r; i++){
            if(arr[i]==k)cnt++;
         }
    }
    else{
        for(int i=l, end=(cl+1)*len-1; i<=end; i++){
            if(arr[i]==k)cnt++;
        }
        for(int i=cl+1; i<=cr-1; i++){
            cnt+=block[i][k];
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]==k)cnt++;
        }
    }
    return cnt;
}

void update(int l, int r){

    int cl=l/len;
    int

}

int main(){

    ///ios_base::sync_with_stdio(false);cout.tie(false);cin.tie(false);
    int n,i,m;
    scanf("%d",&n);
    len=sqrt(n)+1;
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    int blk,type,l,r,k,val,pos;
    while(m--){
        scanf("%d",&type);
        if(type==2){
            scanf("%d%d%d",&l,&r,&k);
            l--;r--;
            printf("%d\n",query(l,r,k));
            update(l,r);
        }
        else{
            scanf("%d%d",&l,&r);
        }
    }
    return 0;

}
