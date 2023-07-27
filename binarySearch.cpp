#include <bits/stdc++.h>
using namespace std;
// Binary Search function
class Solution
{
public:
    Solution() {}
    int binarySearch(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // Element not found
        return -1;
    }
    // https://leetcode.com/problems/find-target-indices-after-sorting-array/
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
    // https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (auto i : grid)
        {
            int left = 0, right = i.size() - 1;
            if (i[left] < 0)
                count += i.size();
            else if (i[right] < 0)
            {

                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (i[mid] >= 0)
                        left = mid + 1;
                    else
                    {
                        count += right - mid + 1;
                        right = mid - 1;
                    }
                }
            }
            cout << count << endl;
        }
        return count;
    }

    // https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
    int maximumCount(vector<int> &nums)
    {
        int countNegative = 0, countPositive = 0, n = nums.size();
        if (nums[0] >= 0 || nums[n - 1] < 0)
            return n;
        else
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] >= 0)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return max(n - left, left);
        }
        return -1;
    }
    // https://leetcode.com/problems/intersection-of-two-arrays/solutions/
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto i : nums2)
        {
            if (s.count(i))
            {
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }

    // This is the custom function interface.
    // You should not implement it, or speculate about its implementation
    class CustomFunction
    {
    public:
        // Returns f(x, y) for any given positive integers x and y.
        // Note that f(x, y) is increasing with respect to both x and y.
        // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
        int f(int x, int y);
    };
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        vector<vector<int>> ans;
        int left = 0, right = 1000;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (customfunction.f(left, right) == z)
            {
                vector<int> temp{left, right};
                ans.push_back(temp);
            }
            else if (customfunction.f(left, right) < z)
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }

    // https://leetcode.com/problems/first-bad-version/
    // The API isBadVersion is defined for you.
    bool isBadVersion(int version);
    int firstBadVersion(int n)
    {
        long int start = 1, end = n;
        while (start <= end)
        {
            long int mid = (start + end) / 2;
            if (isBadVersion(mid))
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }

    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
    vector<int> twoSum_(vector<int> &numbers, int target)
    {
        vector<int> ans;

        for (int i = 0; i < numbers.size(); i++)
        {
            int start = i + 1, end = numbers.size() - 1;
            int numToFind = target - numbers[i];
            while (start <= end)
            {
                int mid = (start + end) / 2;
                if (numbers[mid] > numToFind)
                    end = mid - 1;
                else if (numbers[mid] < numToFind)
                    start = mid + 1;
                else
                {
                    ans.push_back(i + 1);
                    ans.push_back(mid + 1);
                    return ans;
                }
            }
        }
        return {-1, -1};
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int start = 0, end = numbers.size() - 1;
        while (start <= end)
        {
            if (numbers[start] + numbers[end] < target)
                ++start;
            else if (numbers[start] + numbers[end] > target)
                --end;
            else
            {
                return {start + 1, end + 1};
            }
        }

        return {0, 0};
    }

    // https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int start = 0, end = height.size() - 1;
        while (start <= end)
        {
            int val = min(height[start], height[end]) * (end - start);
            if (height[start] >= height[end])
                --end;
            else
                ++start;
            if (val > max)
            {
                max = val;
            }
        }
        return max;
    }
    int singleNonDuplicate(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;
        while (start != end)
        {
            int mid = (start + end) / 2;
            if (nums[start] != nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return nums[start];
    }
    int mySqrt(int x)
    {
        long int i = 0, j = pow(2, 32) - 1;
        while (i < j)
        {
            long int mid = (i + j) / 2;
            if ((mid * mid) == x)
                return mid;
            else if ((mid * mid) > x)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return j;
    }
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;

            if (arr[mid + 1] > arr[mid])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
    double timeRequired(vector<int> &dist, int speed)
    {
        double time = 0.0;
        for (int i = 0; i < dist.size(); i++)
        {

            double t = ((double)dist[i] / (double)speed);
            time += (i == dist.size() - 1) ? t : ceil(t);
        }
        return time;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int i = 1, j = 1e7, ans = -1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (timeRequired(dist, mid) <= hour)
            {
                ans = mid;
                j = mid - 1;
            }
            else
                i = mid + 1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{1, 3, 2};
    s.minSpeedOnTime(v, 2.7);
    return 0;
}