#include<bits/stdc++.h>
using namespace std;

#define sz 10000005
int L,R;
int lazy[4*sz];
set< int > st;

void move(int at, int l, int r){
    if(lazy[at] && (l!=r))
    lazy[at*2]=lazy[at*2+1]=lazy[at],lazy[at]=0;
    ///lazy[at]=0;
}

void update(int at, int l, int r, int color){

    move(at,l,r);
    if(R<l || r<L)return;
    if(L<=l && r<=R){
        lazy[at]=color;
        move(at,l,r);
        return;
    }
    //move(at);
    int mid=(l+r)/2;
    //move(at);
    update(at*2,l,mid,color);
    update(at*2+1,mid+1,r,color);
}

void cnt(int at, int l, int r){
    ///move(at,l,r);
    if(lazy[at]){
        st.insert(lazy[at]);
        return;
    }
    if(l==r)return;
    int mid=(l+r)/2;
    cnt(at*2,l,mid);
    cnt(at*2+1,l,mid);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,q,i;

    cin>>t;
    while(t--){
        memset(lazy,0,sizeof(lazy));
        cin>>n;
        st.clear();
        for(i=1; i<=n; i++){
            cin>>L>>R;
            update(1,1,sz,i);
        }
        cnt(1,1,sz);
        cout<<st.size()<<endl;
    }

    return 0;
}
