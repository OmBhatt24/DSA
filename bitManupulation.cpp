#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //   https://leetcode.com/problems/add-binary/
    string addBinary(string a, string b)
    {

        string ans;

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

    // https://leetcode.com/problems/add-digits/
    int addDigits(int num)
    {
        int ans = 0;

        while (num > 0)
        {
            ans += num % 10;
            num / = 10;
        }
        return (ans >= 0 && ans < 10) ? ans : addDigits(ans);
    }
    int findDuplicate(vector<int> &nums)
    {
        int h = 0, x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x = 1;
            x = x << nums[i];
            if (x & h)
            {
                return nums[i];
            }
            else
            {
                h |= x;
            }
        }
        return -1;
    }
    // https://leetcode.com/problems/single-number-ii/
    int singleNumber(vector<int> &nums)
    {
        int i = 0;
        for (auto j : nums)
        {
            i = (i ^ j);
        }
        return i + 1;
    }
};
int main()
{
    Solution s;
    vector<int> v{1, 2, 4, 5, 6, 4, 3, 2};
    s.singleNumber(v);
    return 0;
}