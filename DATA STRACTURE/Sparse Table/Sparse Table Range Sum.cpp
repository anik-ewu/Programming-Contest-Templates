///Problem   : Sum of the values of Given Range L-R
///Approach  : Sparse Table
///Complexity: build O(NlogN) query O(K)
///Update    : No Update

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define K 20 /// k = log2(N)
int arr[sz];
int logs[sz];
int st[sz][K];

void precompute(int n){
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i/2] + 1;

    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = (st[i][j-1]+st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R){
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
}

int main(){

    int l,r,t,i,n,q,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=0; i<n; i++){
            ///scanf("%d",&arr[i]);
        }
        precompute(n);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&l,&r);
            l--;r--;///0 base indexing
            printf("%d\n",query(l,r));
        }
    }
    return 0;
}
/*
INPUT:
1
5 5
1 2 3 4 5
1 2
2 3
1 5
2 4
3 5
OUTPUT:
Case 1:
3
5
15
9
12
*/
