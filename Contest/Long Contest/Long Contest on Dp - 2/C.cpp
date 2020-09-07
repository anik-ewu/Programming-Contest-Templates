#include<bits/stdc++.h>
using namespace std;
#define sz 1005
int n;
int dp[sz][sz];
int W[sz],S[sz];

struct st{
    int l,r,idx;
}arr[sz];

bool cmp(st a, st b){
    if(a.l==b.l)return a.r>b.r;
    return a.l<b.l;
}

int lis(int p, int index){
       if(p>n)return 0;
       if(index>=0 && dp[p][index]!=-1)return dp[p][index];
       int a,b=0;
       a=lis(p+1,index);
       if(index==-1 || (W[p]>W[index] && S[p]<S[index])){
        b=1+lis(p+1,p);
       }
       return dp[p][index]=max(a,b);
}

void path(int p, int len){
    if(p>n)return ;
    if(lis(p,p)==len-1){
        cout<<arr[p].idx<<endl;
        path(p+1,len-1);
    }
    else{
        path(p+1,len);
    }
}

int main(){

    int a,b;
    n=1;
    while(cin>>a>>b){
        arr[n].l=a;
        arr[n].r=b;
        arr[n].idx=n;///saving index for path printing
        n++;
    }
    n--;
    sort(arr+1,arr+n+1,cmp);
    for(int i=1; i<=n; i++){
        W[i]=arr[i].l;
        S[i]=arr[i].r;
    }
    memset(dp,-1,sizeof(dp));
    cout<<lis(1,-1)<<endl;///length of the lis
    path(1,lis(1,-1));///indexes of the list

    return 0;
}
