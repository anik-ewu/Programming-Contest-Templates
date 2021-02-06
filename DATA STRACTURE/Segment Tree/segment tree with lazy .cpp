#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

struct data
{
    int ar,br;
};
data tree[4*100000]; /// tree[x] = child sum of the node x
int lazy[4*100000]; /// lazy[x] = value under the x sub-tree are needed to increase
int kp[100050];
int s,u,v,n,m,tp;


/// at the beginning, i'th position start with the value kp[i]
void build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod].ar=kp[l];
        tree[nod].br=kp[l-1]-kp[l];
        lazy[nod]=0;
        cout<<tree[nod].ar<<' '<<tree[nod].br<<endl;
        return ;
    }

    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;

    build(left,l,mid);
    build(right,mid+1,r);

    lazy[nod]=0;
    tree[nod].ar=fabs(tree[left].br )+fabs( tree[right].br);
    tree[nod].br=tree[nod].ar;
}

/// from the range (u,v) value s are needed to increase

void update(int nod,int l,int r)
{
    if(r<u || v<l) return;

    if(u<=l && r<=v)
    {
        tree[nod].ar+= (r-l+1)*s ; /// for (r-l+1) position, value s will be increase
        tree[nod].br+=(r-l+1)*s;
        lazy[nod]+=s; /// still we need to update sub tree.
        return ;
    }

    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;
    /// lazy update the sub tree under nod
    if(lazy[nod]>0)
    {
        tree[left].ar+=(mid-l+1)*lazy[nod];
        lazy[left]+=lazy[nod];
        tree[right].ar+=(r-mid)*lazy[nod];
        lazy[right]+=lazy[nod];

        lazy[nod]=0;
    }


    update(left,l,mid);
    update(right,mid+1,r);
    tree[nod].ar=fabs(tree[left].br )+fabs( tree[right].br);
    tree[nod].br=tree[nod].br=tree[nod].ar;
}

/// need to know the total sum of range (u,v)

void query(int nod,int l,int r)
{
    cout<<"ok1"<<endl;
    if(r<u || v<l) return;

    if(u<=l && r<=v)
    {
        if(l==r)
            s+=tree[nod].br;
        else
            s+=tree[nod].ar;
        return ;
    }

    int mid=(l+r)/2;
    int left=nod * 2;
    int right= left + 1;

    /// lazy update the sub tree under nod

    if(lazy[nod]>0)
    {
        tree[left].ar+=(mid-l+1)*lazy[nod];
        lazy[left]+=lazy[nod];

        tree[right].ar+=(r-mid)*lazy[nod];
        lazy[right]+=lazy[nod];
        lazy[nod]=0;
    }


    query(left,l,mid);
    query(right,mid+1,r);

    tree[nod].ar=fabs(tree[left].br )+fabs( tree[right].br);
}


int main()
{
    int c;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>kp[i];
    kp[0]=kp[1];
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        cin>>tp;

        if(tp!=1) /// type 1
        {
            cin>>u>>v>>s;
            update(1,1,n);
        }
        else
        {
            cin>>u>>v>>c;
            ///u++;
            s=c;
            query(1,1,n);
            cout<<s<<endl;
        }
    }
    return 0;
}

