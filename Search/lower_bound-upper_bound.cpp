// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
using namespace std;
int main ()
{
    int myints[] = {3,20,30,30,20,10,10,20};
    vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

    sort (v.begin(), v.end());                // 3 10 10 20 20 20 30

    vector<int>::iterator low,up;
    low=lower_bound (v.begin(), v.end(), 4); //          ^
    up= upper_bound (v.begin()+4, v.end(), 19); //                   ^

    cout << "lower_bound at position " << (low- v.begin()) << '\n';
    cout << "upper_bound at position " << (up - v.begin()) << '\n';

    return 0;
}
