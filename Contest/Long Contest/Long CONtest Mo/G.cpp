#include<bits/stdc++.h>
using namespace std;

#define sz 3000005

struct query{
    int l,r,id;
}q[sz];
int len,mx;
int ans[sz],arr[sz];
int fre[sz],ffre[sz];

bool cmp(query &a, query &b){
    if(a.l/len!=b.l/len)
        return a.l/len<b.l/len;
    return a.r<b.r;
}
void add(int pos){
    int a=arr[pos];
    fre[a]++;
    ffre[fre[a]]++;
    mx=max(mx,fre[a]);
}

void del(int  pos){
    int a=arr[pos];
    int b=fre[a];
    ffre[fre[a]]--;
    fre[a]--;
    if(ffre[b]==0)
        mx=fre[a];
}

int main(){

    int n,i,j,m;
    while(cin>>n){
        if(n==0)break;
        scanf("%d",&m);
        len=sqrt(n)+1;
        mx=0;
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
            arr[i]+=100000;///handling negative values
            fre[arr[i]]=0;
            ffre[i]=0;
        }
        for(i=1; i<=m; i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].id=i;
        }
        sort(q+1,q+m+1,cmp);///sort query
        int currentL=0;
        int currentR=-1;
        for(i=1; i<=m; i++){
            int l=q[i].l-1;
            int r=q[i].r-1;
            while(currentL>l){
                currentL--;
                add(currentL);
            }
            while(currentR<r){
                currentR++;
                add(currentR);
            }
            while(currentL<l){
                del(currentL);
                currentL++;
            }
            while(currentR>r){
                del(currentR);
                currentR--;
            }
            ans[q[i].id]=mx;
        }
        for(i=1; i<=m; i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
