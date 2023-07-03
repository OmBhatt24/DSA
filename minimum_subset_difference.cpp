#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums)
{
    int range = 0;
    int mn = INT_MAX;
    for (auto i : nums)
        range += i;

    bool t[nums.size() + 1][range + 1];
    for (int i = 0; i < nums.size() + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    for (int i = 1; i < nums.size() + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (nums[i - 1] <= j)
                t[i][j] = t[i - 1][j - nums[i - 1]] | t[i - 1][j];

            else
                t[i][j] = t[i - 1][j];
        }
    }
    for (int i = 0; i <= (range) / 2; i++)
    {
        if (t[nums.size()][i])
            mn = min(mn, range - (2 * i));
    }

    return mn;
}

int main()
{
    vector<int> v{1, 1, 2, 3};
    cout << minimumDifference(v);
    return 0;
}