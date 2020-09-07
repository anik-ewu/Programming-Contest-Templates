#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define yolo "debug_statement"

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi=acos(-1);
const ll mod=1000000007;

int mini;
int a[300005];
int n, q;
bool flag;

struct wavelet_tree
{
    int lo, hi;
    wavelet_tree *l, *r;
    int *b, psz;

    wavelet_tree(){
        lo = 1;
        hi = 0;
        psz = 0;
        l = NULL;
        r = NULL;
    }

    void init(int *from, int *to, int x, int y){
        lo = x, hi = y;
        if(lo == hi || from >= to)
            return;
        int mid = (lo + hi) >> 1;
        auto f = [mid](int x)
        {
            return x <= mid;
        };
        b = (int*)malloc((to - from + 2) * sizeof(int));
        psz = 0;
        b[psz++] = 0;
        for(auto it = from; it != to; it++)
            b[psz] = (b[psz - 1] + f(*it)), psz++;
        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree();
        l->init(from, pivot, lo, mid);
        r = new wavelet_tree();
        r->init(pivot, to, mid+1, hi);
    }
    void solve(int l, int r, int ll, int rr, int k)
    {
        if(l > r)
            return;
        if(lo==hi)
        {
            if(r-l+1 > (rr-ll+1)/k)
            {
                mini = min(mini,lo);
                flag = true;
            }
            return;
        }
        if(r-l+1 <= (rr-ll+1)/k)
            return;
        int lb = b[l-1];
        int rb = b[r];
        int mid = (lo+hi)>>1;
        if(!flag)
            this->l->solve(lb+1,rb,ll,rr,k);
        if(!flag)
            this->r->solve(l-lb,r-rb,ll,rr,k);
    }

    ~wavelet_tree()
    {
        delete l;
        delete r;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, l, r, k;
    cin >> n >> q;
    fo(i,n)cin >> a[i+1];
    wavelet_tree *T = new wavelet_tree();
    T->init(a+1,a+n+1,0,300005);
    while(q--)
    {
        cin >> l >> r >> k;
        mini = inf;
        flag = false;
        T->solve(l,r,l,r,k);
        mini==inf?cout << -1: cout << mini;
        cout << endl;
    }

    return 0;
}

