#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int arr[sz];

int lis(int n ){
	int lis[n];
	lis[0] = 1;
	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ){
		lis[i] = 1;
		for (int j = 0; j < i; j++ )
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
    return *max_element(lis, lis+n);
}

int main(){
	int n;
	cin>>n;
	for(int  i=0; i<n; i++)cin>>arr[i];
	cout<<lis(n)<<endl;///Length of lis
	return 0;
}
///Input : 16
///0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
///Output : 6
