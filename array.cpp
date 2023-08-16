#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        string temp;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j < nums.size() - 1 && nums[j + 1] == nums[j] + 1)
            {
                j++;
            }

            if (j > i)
            {
                temp += to_string(nums[i]) + "->" + to_string(nums[j]);
            }
            else if (j == i)
                temp += to_string(nums[i]);
            ans.push_back(temp);
            i = j;
            temp.clear();
        }
        return ans;
    }
    // https://leetcode.com/problems/3sum/?envType=study-plan-v2&envId=top-interview-150
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back)
            {
                /* code */
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    vector<int> temp{nums[target], nums[front], nums[back]};
                    ans.push_back(temp);
                    while (front < back && nums[front] == temp[1])
                        front++;
                    while (front < back && nums[back] == temp[2])
                        back--;
                }
            }
            while (nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
    // https://leetcode.com/problems/find-the-winner-of-the-circular-game/
    int findTheWinner(int n, int k)
    {
        vector<int> friends;
        for (int i = 0; i < n; i++)
        {
            friends.push_back(i + 1);
        }
        int turn = 0;
        while (friends.size() != 1)
        {
            n = friends.size();
            turn = (turn + k - 1) % n;
            // cout<<turn ;
            friends.erase(friends.begin() + turn);
        }
        return friends[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto i : intervals)
        {
            if (ans.empty() || ans.back()[1] < i[0])
            {
                ans.push_back(i);
            }
            else
            {
                ans.back()[1] = max(i[1], ans.back()[1]);
            }
        }
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (auto i : intervals)
        {
            if (ans.empty() || ans.back()[1] > i[0])
            {
                ans.push_back(i);
            }
            else
            {
                ans.back()[1] = max(i[i], ans.back()[1]);
            }
        }
        return ans;
    }
    bool canJump(vector<int> &nums)
    {
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > reachable)
                return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
    // https://leetcode.com/problems/find-the-highest-altitude
    int largestAltitude(vector<int> &gain)
    {
        vector<int> altitudes(gain.size() + 1);
        altitudes[0] = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            altitudes[i + 1] = altitudes[i] + gain[i];
        }
        return *max_element(altitudes.begin(), altitudes.end());
    }
    
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int leftProduct = 1;
            if (i != 0)
            {
                for (int j = 0; j < i; j++)
                {
                    leftProduct *= nums[j];
                }
            }
            int rightProduct = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                rightProduct *= nums[j];
            }
            ans[i] = leftProduct * rightProduct;
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            if (mp.count(temp))
            {
                mp[temp].push_back(str);
            }
            else
                mp[temp].push_back(str);
        }
        for (auto i : mp)
            ans.push_back(i.second);
        return ans;
    }
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        string prev = "";
        for (auto word : words)
        {
            string temp = word;
            sort(temp.begin(), temp.end());
            if (temp != prev)
            {
                ans.push_back(word);
            }
            prev = temp;
        }
        return ans;
    }
    int sumOfDigits(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += (n % 10);
            n /= 10;
        }
        return ans;
    }
    int temp(int n1, int n2)
    {
        // test case 10,19
        int a = n1, b = n2;
        while (a != b)
        {
            a += sumOfDigits(a);
            b += sumOfDigits(b);
            cout << "a: " << a << " b: " << b << endl;
        }
        return a;
    }

    int removeDuplicates(vector<int> &nums)
    {
        int count = 0, i = 0, prev = nums[0];
        while (i < nums.end() - nums.begin())
        {
            if (nums[i] == prev)
                count++;
            else
            {
                prev = nums[i + 1];
                count = 0;
            }
            if (count > 2)
            {
                nums.erase(nums.begin() + i);
                continue;
            }
            i++;
        }
        return nums.size();
    }
};

int main()
{
    return 0;
}