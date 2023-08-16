
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
                return nums[i];
            i++;
            j++;
        }
        return -1;
    }
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 0, freq = 1;
        while (j < nums.size())
        {
            j++;
            if (nums[i] == nums[j])
            {
                j++;
                while (nums[i] == nums[j])
                {
                    nums.erase(nums.begin() + j);
                }
            }
            else
            {
                i++;
            }
        }
        return nums.size();
    }
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (auto i : nums)
            mp[i]++;
        int start = 0, end = nums.size() - 1, ans = 0;
        while (start < end)
        {
            if (nums[start] + nums[end] == k)
            {
                ans++;
                start++;
                end--;
            }
            else if (nums[start] + nums[end] > k)
                end--;
            else
                start++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}