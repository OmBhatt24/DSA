#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subsetSum(vector<int> &nums, int n, int sum)
    {
        bool t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= sum; j++)
                {

                    if (nums[i - 1] <= j)
                        t[i][j] = t[i - 1][j - nums[i - 1]] | t[i - 1][j];
                    else
                        t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        else
            return subsetSum(nums, nums.size(), sum / 2);
    }
};
int main()
{
    Solution s;
    vector<int> v{5, 10, 5};
    cout << s.canPartition(v);
    return 0;
}