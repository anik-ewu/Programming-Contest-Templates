///Approach  : MO
///Complexity: O(Sqrt(N) * N)
///Problem   : Most Frequent Value On Range L-R

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
    fre[a]--;
    ffre[b]--;
    if(ffre[b]==0)
        mx=fre[a];
}

int main(){

    int n,i,j,m;
    while(scanf("%d",&n) && n){
        if(n==0)break;
        scanf("%d",&m);
        len=sqrt(n)+1;///we may need to tune it 447->500
        mx=0;
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
            arr[i]+=100000;///handling negative values
            fre[arr[i]]=0;
            ffre[i]=0;
        }
        for(i=1; i<=m; i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].id=i;q[i].l--;q[i].r--;
        }
        sort(q+1,q+m+1,cmp);///sort query
        int l=0,  r=-1;
        for(i=1; i<=m; i++){
            while(l>q[i].l)add(--l);
            while(r<q[i].r)add(++r);
            while(l<q[i].l)del(l++);
            while(r>q[i].r)del(r--);
            ans[q[i].id]=mx;
        }
        for(i=1; i<=m; i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

/*
Input :
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
OutPut:
1
4
3
*/
