#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ncr(int n, int r){

	///n<r return 0;

	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	long long p = 1, k = 1;

	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
            long long m = __gcd(p, k);

			// dividing by gcd, to simplify product
			// division by their gcd saves from the overflow
			p /= m;
			k /= m;
			n--;
			r--;
		}

		/// k should be simplified to 1 as C(n, r) is a natural number
		/// (denominator should be 1 ) .
	}

	else
        p = 1;
    return p;
}

// Driver code
int main(){
	int n = 26, r = 2;

	cout<<ncr(n, r)<<endl;

	return 0;
}
