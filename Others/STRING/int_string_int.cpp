#include<bits/stdc++.h>
using namespace std;

string int_to_str(int num)
{
    stringstream ss;

    ss << num;

    return ss.str();
}

int str_to_int(string str)
{
    stringstream ss(str);

    int num;
    ss >> num;

    return num;
}

int main()
{
    int x;
    string s;
    x=str_to_int();
    s=int_to_str();


    return 0;
}
