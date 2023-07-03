#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150
bool wordPattern(string pattern, string s)
{
    unordered_map<char, char> mp;

    stringstream ss(s);
    string temp;
    int i = 0;
    while (ss >> temp)
    {
        if (mp.count(temp[0]))
        {
            if (mp[pattern[i++]] != temp[0)
                return false;
        }
        else
            mp[pattern[i++]] = temp[0];
    }
    return true;
}
// https://leetcode.com/problems/longest-consecutive-sequence
int longestConsecutive(vector<int> &nums)
{
    map<int, int> mp;
    int len = 0, maxLen = INT_MIN;
    for (auto num : nums)
    {
        mp[num]++;
    }
    for (auto i : mp)
    {
        if (mp.count(i.first + 1))
            len++;
        else
            maxLen = max(len, maxLen);
    }
    return maxLen;
}

class MinStack
{
    vector<int> min_val;
    vector<int> arr;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        arr.push_back(val);
        int minVal = INT_MAX;
        if (min_val.size() > 0)
            minVal = min_val.back();
        min_val.push_back(min(minVal, val));
    }

    void pop()
    {
        arr.pop_back();
        min_val.pop_back();
    }

    int top()
    {
        return arr.back();
    }

    int getMin()
    {
        return min_val.back();
    }
};
int main()
{

    return 0;
}