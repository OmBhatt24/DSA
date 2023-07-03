#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        stringstream ss(s);
        string ans;
        ss >> ans;
        return stoi(ans);
    }
};
int main()
{
    Solution s;
    cout << s.myAtoi("-000123 is number");

    return 0;
}