#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /* template for sliding window
        int fn(vector<int> &arr)
        {
            int left = 0, ans = 0, curr = 0;

            for (int right = 0; right < arr.size(); right++)
            {
                // do logic here to add arr[right] to curr

                while (WINDOW_CONDITION_BROKEN)
                {
                    // remove arr[left] from curr
                    left++;
                }

                // update ans
            }

            return ans;
        }
        */
    int countGoodSubstrings(string s)
    {
        int i = 0, j = 0, n = s.size(), ans = 0;
        while (j < n)
        {
            if (j - i + 1 == 3)
            {
                string temp = s.substr(i, 3);
                unordered_map<int, int> mp;
                for (auto i : temp)
                    mp[i]++;
                if (mp.size() == 3)
                    ans++;
                i++;
            }
            j++;
        }
        return ans;
    }

    // https://leetcode.com/problems/contains-duplicate-ii/
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if (mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if (abs(i - mp[nums[i]]) <= k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
    // https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        // code here
        long int sum = 0;
        for (int i = 0; i < K; i++)
        {
            sum += Arr[i];
        }
        long int maxSum = sum;
        for (int i = K; i < N; i++)
        {
            sum = sum + Arr[i] - Arr[i - K];
            maxSum = max(maxSum, sum);
            /* code */
        }
        return maxSum;
    }
    // https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
    long maximumSumSubarrayOther(int K, vector<int> &Arr, int N)
    {
        // code here
        int i = 0, j = 0;
        long ans = INT_MIN, sum = 0;
        while (j < N)
        {
            sum += Arr[j];
            if (j - i + 1 == K)
            {
                ans = max(sum, ans);
                sum -= Arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int i = 0, j = 0, n = arr.size(), sum = 0, ans = 0;

        while (j < n)
        {
            sum += arr[j];
            if (j - i + 1 == k)
            {
                if ((sum * 1.0) / k >= threshold)
                    ans++;
                sum -= arr[i];
                i++;
            }
            j++;
            /* code */
        }
        return ans;
    }
    // https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
    int numberOfSubstrings(string s)
    {
        int i = 0, j = 0, n = s.size(), ans = 0;
        unordered_map<char, int> mp;
        while (j < n)
        {
            mp[s[j]]++;
            if (mp.size() < 3)
            {
                j++;
            }
            else if (mp.size() == 3)
            {

                while (mp.size() == 3)
                {
                    ans += n - j;
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
    // https://leetcode.com/problems/longest-substring-without-repeating-characters/
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, n = s.size(), ansLen = 0;
        unordered_map<char, int> mp;
        while (j < n)
        {
            mp[s[j]]++;
            if (mp[s[j]] > 1)
            {
                while (mp[s[j]] > 1)
                {
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
            else if (mp[s[j]] == 1)
            {
                j++;
                ansLen = max(j - i, ansLen);
            }
        }
        return ansLen;
    }
    // https://leetcode.com/problems/longest-nice-substring/
    string longestNiceSubstring(string s)
    {
    }

    // https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0, minLen = INT_MAX, sum = 0, n = nums.size();
        while (j < n)
        {
            sum += nums[j++];
            while (sum >= target)
            {
                minLen = min(minLen, j - i);
                sum -= nums[i++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> ans(nums.size(), -1);
        int i = 0, j = 0, sum = 0, windowSize = (2 * k) + 1;
        while (j < nums.size())
        {
            sum += nums[j];
            j++;
            if (j - i + 1 == windowSize)
            {
                int mid = (i + j) / 2;
                ans[mid] = (sum) / windowSize;
                sum -= nums[i];
                i++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v{2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, v);

    return 0;
}