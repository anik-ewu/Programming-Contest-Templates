///STL : SET

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main(){
    set <int > set1;

    set1.insert(10);
    set1.insert(30);
    set1.insert(50);
    set1.insert(50); /// only one 50 will be added to the set

    /// printing set
    set <int> :: iterator itr;
    for (itr = set1.begin(); itr != set1.end(); ++itr){
        cout << *itr;
    }

    set <int> set2(set1.begin(), set1.end());/// assigning the elements from set1 to set2

    set2.erase(set2.begin(), set2.find(30));/// remove all elements up to 30 in set2

    int num = set2.erase (50);/// remove element with value 50 in set2

    ///Search
    set1.lower_bound(40);///lower bound >=
    set2.upper_bound(40);///upper bound >

    return 0;

}
