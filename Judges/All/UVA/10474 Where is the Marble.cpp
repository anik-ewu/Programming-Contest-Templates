#include<bits/stdc++.h>
using namespace std ;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define INF             2e16
#define ff              first
#define sf              scanf
#define pf              printf
#define ss              second
#define mk              make_pair
#define pb              push_back
#define PI              acos(-1.0)
#define nl              printf("\n")

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define sz              100005
#define ll              long long int
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

char f,g;
string s,p;
map < int , int > mp;
vector < int > v,va,vb;
int arr[sz],brr[sz],crr[sz];

void init(int n){

    for( int i=0; i<=n; i++){

    }
}

int bsearch(int n, int val){

     int cnt=0,low=0,mid,high=n,index=-1;

     while(low<=high and cnt++<50){

            mid=(low+high)/2;
            if(v[mid]>val)
                high=mid;
            else if(v[mid]<val)
                low=mid+1;
            else{
                index=mid;
                high=mid;
            }
     }
     return index;
}


int main(){

    ///fRead("input.txt");

    int n,q,a,cs=1;

    while(sf("%d%d",&n,&q)){
        if(!n and !q)break;

        v.clear();
        for(int i=0; i<n; i++){
            sf("%d",&a);
            v.pb(a);
        }

        SORT(v);

        pf("CASE# %d:\n",cs++);

        while(q--){
            sf("%d",&a);
            int index=bsearch(n-1,a);

            if(index<0){
                pf("%d not found\n",a);
            }

            else{
                pf("%d found at %d\n",a,index+1);
            }
        }
    }
    return 0;
}

