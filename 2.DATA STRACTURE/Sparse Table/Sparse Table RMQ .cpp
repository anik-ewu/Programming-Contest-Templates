///Problem   : Minimum Value On Range L-R
///Approach  : Sparse Table
///Complexity: build O(N logN) query O(1)

#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define K 20 /// k = log2(n)
int arr[sz];
int logs[sz];
int st[sz][k];

void precompute(int n){
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i/2] + 1;

    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++){
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }
}

int query(int L, int R){
    int j = logs[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    return minimum;
}

int main(){

    int l,r,t,i,n,q,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=0; i<n; i++){
            scanf("%d",&arr[i]);
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
5 3
78 1 22 12 3
1 2
3 5
4 4
1 1
10
1 1
OUTPUT:
Case 1:
1
3
12
Case 2:
10
*/
