#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = 1000000000;
        while (l < r)
        {
            int mid = (l + r) / 2, total;
            for (auto p : piles)
                total += ceil(p / mid);

            if (total > h)
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return l;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 1, 2, 3, 4};
    // cout << s.findMin(nums);
    return 0;
}