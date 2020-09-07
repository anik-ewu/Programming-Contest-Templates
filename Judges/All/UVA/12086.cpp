///UVA      : 12086
///Approach : Square Root Decomposition
///Time     : SQRT(N)
#include<bits/stdc++.h>
using namespace std;
#define sz 200005
int len;
int arr[sz];
int block[500];

void update(int pos , int val){
    block[pos/len]-=arr[pos];
    block[pos/len]+=val;
    arr[pos]=val;
}
int query(int l, int r){
    int cl=l/len;
    int cr=r/len;
    int sum=0;
    if(cl==cr){
        for(int i=l; i<=r; i++){
            sum+=arr[i];
        }
    }
    else{
        for(int i=l, end=(cl+1)*len-1; i<=end; i++){
            sum+=arr[i];
        }

        for(int i=cl+1; i<=cr-1; i++){
            sum+=block[i];
        }
        for(int i=cr*len; i<=r; i++){
            sum+=arr[i];
        }
    }
    return sum;
}


int main(){

    int n,i,l,r,val,pos,cas=1;
    char type;
    while(scanf("%d",&n) && n!=0){
        len=sqrt(n)+1;
        memset(block,0,sizeof(block));
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
            block[i/len]+=arr[i];
        }
        getchar();///remove extra char
        if(cas>1)
            printf("\n");
        printf("Case %d:\n",cas++);

        while(scanf("%ch",&type)){
        if(type=='M'){
            scanf("%d%d",&l,&r);
            l--;r--;
            int ans=query(l,r);
            printf("%d\n",ans);
            getchar();///remove extra char
        }
        else if(type=='S'){
            scanf("%d%d",&pos,&val);
            pos--;
            update(pos,val);
            getchar();///remove extra char
        }
        else{
            getchar();///remove N
            getchar();///remove D
            break;///End of case
          }
        }
    }
    return 0;
}

