///28.4.2020
///Printing All Possible Subset OF an Array

#include <bits/stdc++.h>
using namespace std;

void allPossibleSubset(int arr[],int n){
	int  count = pow(2,n);
	for (int i = 0; i < count; i++){
		for (int j = 0; j < n; j++){
			/// checking if jth bit in binary representation of i is set or not
			if ((i & (1 << j)) > 0)
				cout << arr[j]<< " ";
		}
		cout << "\n";
	}
}

int main(){
	int n;
	int arr[10];
	cin >> n;
    for(int i=0;i<n;i++)
		cin >> arr[i];

	allPossibleSubset(arr,n);

	return 0;
}
