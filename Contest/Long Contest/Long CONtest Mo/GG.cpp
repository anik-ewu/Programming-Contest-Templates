//Bismillahir Rahmanir Rahim
#define ll long long
#define ull unsigned long long
#define scf1(a)  scanf("%lld",&a)
#define scf2(a,b)  scanf("%lld %lld",&a,&b)
#define pf    printf
#define pb    push_back
#define rsrt(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define ff first
#define ss second
#define spd ios_base::sync_with_stdio(false)
#include<bits/stdc++.h>
using namespace std;
struct Query
{
    ll l;
    ll r;
    ll i;
};
ll arr[100005];
ll block;
ll ml,mr,mx;
Query Q[100005];
ll ans[100005];
ll freq[300005];
ll dfreq[300005];
ll mark[100005];
bool cmp(Query a, Query b)
{
    if(a.l/block!=b.l/block)
        return a.l/block<b.l/block;
    return a.r<b.r;
}

void add(ll id)
{
    freq[arr[id]]++;
    dfreq[freq[arr[id]]]++;
    mx = max(mx,freq[arr[id]]);
}

void rem(ll id)
{
    if(freq[arr[id]]==mx)
    {
        if(dfreq[freq[arr[id]]]>1)
        {
            mx = freq[arr[id]];

        }

        else
            mx = freq[arr[id]]-1;
    }

    dfreq[freq[arr[id]]]--;

    freq[arr[id]]--;
}
int main()
{
    ll n;

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);
    while(1){
        cin>>n;
        ll num=1;
        if(n==0)
        {
            return 0;
        }

        ll q,i,j;
        block = sqrt(n);
        cin>>q;

        for(i=0; i<n; i++){
            cin>>arr[i];
            arr[i]+=100000;
            freq[arr[i]]=0;
            dfreq[i]=0;
        }

        for(i=0; i<q; i++)
        {
            cin>>Q[i].l>>Q[i].r;
            Q[i].l--;
            Q[i].r--;
            Q[i].i=i;
        }

        sort(Q,Q+q,cmp);

        ml = 0,mr=-1;
        mx = 0;

        for(i=0; i<q; i++)
        {
            ll L = Q[i].l;
            ll R = Q[i].r;

            while(ml>L)
            {
                ml--;
                add(ml);
            }

            while(mr<R)
            {
                mr++;
                add(mr);
            }

            while(ml<L)
            {
                rem(ml);
                ml++;
            }

            while(mr>R)
            {
                rem(mr);
                mr--;
            }
            ans[Q[i].i]=mx;

        }

        for(i=0; i<q; i++)
            cout<<ans[i]<<"\n";
    }
}
