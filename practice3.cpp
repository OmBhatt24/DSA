#include <bits/stdc++.h>
using namespace std;
int subsetSum(vector<int> &nums, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;
    if (nums[n - 1] <= sum)
        return subsetSum(nums, n - 1, sum - nums[n - 1]) + subsetSum(nums, n - 1, sum);
    else
        return subsetSum(nums, n - 1, sum);
}
int f(vector<int> &nums, int diff)
{
    int sum = 0;
    for (auto i : nums)
        sum += i;
    return subsetSum(nums, nums.size(), (sum + diff) / 2);
}
int main()
{
    vector<int> v{1, 1, 2, 3};
    // vector<int> v{2, 40, 6, 6, 43, 44, 10, 32, 12, 12, 26, 31, 48, 14, 38, 42, 25};
    cout << f(v, 1);
    return 0;
}