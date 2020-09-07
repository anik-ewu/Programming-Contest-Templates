///multi-set
///upper bound and lower bound exchange their principle

#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_multiset;

int main() {
	ordered_multiset ms;
    vector<int> v{1, 1, 2, 2, 3, 4, 5, 6, 6};

    for(int i : v) ms.insert(i);

	cout << "Ordered Multiset: ";
    for(auto x : ms) cout << x << ' '; cout << '\n';

    cout << "Lower bound of 2: " << *ms.lower_bound(2) << '\n';
    cout << "Upper bound of 2: " << *ms.upper_bound(2) << '\n';
    return 0;
}
