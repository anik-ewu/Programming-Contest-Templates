#include <bits/stdc++.h>
using namespace std;
int count_SubstringWithEqualEnds(string s)
{
    int result = 0;
    int n = s.length();

    // Iterating through all substrings in
    // way so that we can find first and last
    // character easily
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            if (s[i] == s[j])
                result++;

    return result;
}
int main()
{
    string s;
    cin>>s;
    cout << count_SubstringWithEqualEnds(s);
    return 0;
}
