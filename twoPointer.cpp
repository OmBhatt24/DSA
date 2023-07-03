
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (i < nums.size())
        {
            if (j == nums.size())
            {
                i++;
                j = i;
            }
            if (nums[i] == nums[j])
                return nums[i];
            j++;
        }
        return 0;
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
};

int main()
{

    return 0;
}