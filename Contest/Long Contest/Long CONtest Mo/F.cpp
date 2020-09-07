#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int n;
int len;
int arr[sz];
char ch[10];
int lazy[320];
int block[320][sz];
int lucky[30]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};

void update_lazy(int l, int r, int idx){

    for(int i=l; i<r && i<n; i++){
        block[i/len][arr[i]]--;
        arr[i]+=lazy[idx];
        block[i/len][arr[i]]++;
    }
    lazy[idx]=0;
}

void update(int l, int r, int val){

    int cnt=0;
    int cl=l/len;
    int cr=r/len;

    if(lazy[cl]){
        update_lazy(cl*len,(cl*len)+len,cl);
    }
    if(lazy[cr]){
        update_lazy(cr*len,(cr*len)+len,cr);
    }
    if(cl==cr){
        for(int i=l; i<=r; i++){
            block[i/len][arr[i]]--;
            arr[i]+=val;
            block[i/len][arr[i]]++;
        }
    }
    else{

        for(int i=l, end=(cl+1)*len; i<end; i++){
            block[i/len][arr[i]]--;
            arr[i]+=val;
            block[i/len][arr[i]]++;
        }
        for(int i=cl+1; i<cr; i++){
            lazy[i]+=val;
        }
        for(int i=cr*len; i<=r; i++){
            block[i/len][arr[i]]--;
            arr[i]+=val;
            block[i/len][arr[i]]++;
        }
    }
}

int query(int l, int r){

    int cnt=0;
    int cl=l/len;
    int cr=r/len;

    if(lazy[cl]){
        update_lazy(cl*len,(cl*len)+len,cl);
    }
    if(lazy[cr]){
        update_lazy(cr*len,(cr*len)+len,cr);
    }
    if(cl==cr){
        for(int i=l; i<=r; i++){
            for(int j=0; j<30; j++){
                if(arr[i]==lucky[j]){
                    cnt++;
                    break;
                }
            }
        }
    }
    else{

        for(int i=l, end=(cl+1)*len; i<end; i++){
            for(int j=0; j<30; j++){
                if(arr[i]==lucky[j]){
                    cnt++;
                    break;
                }
            }
        }
        for(int i=cl+1; i<cr; i++){
            for(int j=0; j<30; j++){
                if(lucky[j]-lazy[i]>=0)
                  cnt+=block[i][lucky[j]-lazy[i]];
                else
                  break;
            }
        }
        for(int i=cr*len; i<=r; i++){
            for(int j=0; j<30; j++){
                if(arr[i]==lucky[j]){
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main(){

    reverse(lucky,lucky+30);
    int i,m,val,l,r;
    scanf("%d%d",&n,&m);
    len=sqrt(n)+1;
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
        block[i/len][arr[i]]++;
    }
    while(m--){
        scanf("%s%d%d",&ch,&l,&r);
        l--;r--;
        if(ch[0]=='c'){
            int sum=query(l,r);
            printf("%d\n",sum);
        }
        else{
            scanf("%d",&val);
            update(l,r,val);
        }
    }
    return 0;
}
