#include <bits/stdc++.h>
using namespace std;
vector<int> climbStairsMem(46, -1);
vector<int> tribonacciMem(37, -1);

class Solution
{
public:
    // https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&id=dynamic-programming
    int climbStairs(int n)
    {
        if (n < 0)
            return 0;
        climbStairsMem[0] = 1;
        climbStairsMem[1] = 1;
        climbStairsMem[2] = 2;
        if (climbStairsMem[n] != -1)
            return climbStairsMem[n];
        else
            return climbStairsMem[n] = climbStairs(n - 2) + climbStairs(n - 1);
    }

    // https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&id=dynamic-programming
    int tribonacci(int n)
    {
        tribonacciMem[0] = 0;
        tribonacciMem[1] = 1;
        tribonacciMem[2] = 1;
        if (tribonacciMem[n] != -1)
            return tribonacciMem[n];
        else
            return tribonacciMem[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
    // https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&id=dynamic-programming
    int minCostClimbingStairsUtil(vector<int> &cost, int start, int minCost)
    {
        if (start >= cost.size())
            return minCost;
        return min(minCostClimbingStairsUtil(cost, start + 1, minCost + cost[start + 1]), minCostClimbingStairsUtil(cost, start + 2, minCost + cost[start + 2]));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int start = -1, minCost = 0;
        return minCostClimbingStairsUtil(cost, start, minCost);
    }
    // https://practice.geeksforgeeks.org/problems/geek-jump
    int minimumEnergyUtil(int index, vector<int> &height, vector<int> &dp)
    {
        if (index == 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int left = minimumEnergyUtil(index - 1, height, dp) + abs(height[index] - height[index - 1]);
        int right = INT_MAX;
        if (index > 1)
            right = minimumEnergyUtil(index - 2, height, dp) + abs(height[index] - height[index - 2]);
        return dp[index] = min(left, right);
    }
    int minimumEnergy(vector<int> &height, int n)
    {

        vector<int> dp(100001, -1);
        return minimumEnergyUtil(n - 1, height, dp);
        // Code here
    }
    int minimumEnergyTabulation(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(fs, ss);
        }
        return dp[n - 1];
    }
    int uniquePathsUtil(int start, int end, int m, int n)
    {

        if (start == m && end == n)
            return 1;
        else if (start > m || end > n)
            return 0;
        else
            return uniquePathsUtil(start + 1, end, m, n) + uniquePathsUtil(start, end + 1, m, n);
    }
    int uniquePaths(int m, int n)
    {
        return uniquePathsUtil(0, 0, m, n);
    }

    int uniquePathsDP(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid);
        int count = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            count += grid[i][0];
            grid[i][0] = count;
        }
        count = 0;
        for (int j = 0; j < n; j++)
        {
            /* code */
            count += grid[0][j];
            grid[0][j] = count;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
    int robUtil(int index, vector<int> nums, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];

        return dp[index] = max(nums[index] + robUtil(index + 2, nums, dp), robUtil(index + 1, nums, dp));
    }
    // https://leetcode.com/problems/house-robber/
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return robUtil(0, nums, dp);
    }
    int robTab(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[nums.size() - 1];
    }
    int robSpaceOpt(vector<int> &nums)
    {
        int prev2 = 0, prev = nums[0], curi = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notPick = prev;
            curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    // https://leetcode.com/problems/triangle/
    int minimumTotalRec(int index, int curRow, int n, vector<vector<int>> &triangle, vector<vector<int>> dp)
    {

        if (curRow == n - 1)
            return triangle[curRow][index];
        if (dp[curRow][index] != -1)
            return dp[curRow][index];
        return dp[curRow][index] = triangle[curRow][index] + min(minimumTotalRec(index + 1, curRow + 1, n, triangle, dp), minimumTotalRec(index, curRow + 1, n, triangle, dp));
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minimumTotalRec(0, 0, n, triangle, dp);
    }
    int minimumTotalTab(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int dp[n][n];
        for (int i = 0; i < n; i++)
            dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j + 1], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
    // https://practice.geeksforgeeks.org/problems/geeks-training/
    int maximumPointsRec(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                    maxi = max(maxi, points[0][i]);
            }
            return maxi;
        }
        if (dp[day][last] != -1)
            return dp[day][last];
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int point = points[day][i] + maximumPointsRec(day - 1, i, points, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return maximumPointsRec(n - 1, 3, points, dp);
        // Code here
    }
    int maximumPointsTab(vector<vector<int>> &points, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (i != last)
                    {
                        int point = points[day][i] + dp[day - 1][i];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
    int maximumPointsSpaceOpt(vector<vector<int>> &points, int n)
    {
        vector<int> prev(4, 0);
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][1], points[0][0]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (i != last)
                    {
                        int point = points[day][i] + prev[i];
                        temp[last] = max(temp[last], point);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
    // https://leetcode.com/problems/solving-questions-with-brainpower
    long long mostPointsRec(int index, vector<vector<int>> &questions, vector<int> dp)
    {
        if (index >= questions.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        return dp[index] = max(questions[index][0] + mostPointsRec(index + questions[index][1] + 1, questions, dp), mostPointsRec(index + 1, questions, dp));
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<int> dp(questions.size(), -1);
        return mostPointsRec(0, questions, dp);
    }
    int recForLongestSubsequence(int idx, int prev, int len, int difference, vector<int> &arr)
    {
        if (idx == arr.size())
            return len;
        if ((arr[idx] - prev) == difference)
            return recForLongestSubsequence(idx + 1, arr[idx], len + 1, difference, arr);
        else
            return recForLongestSubsequence(idx + 1, prev, len, difference, arr);
    }
    int longestSubsequenceREC(vector<int> &arr, int difference)
    {
        return recForLongestSubsequence(0, 0, 0, difference, arr);
    }
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> dp;
        for (int i = 0; i < n; i++)
        {
            dp[arr[i]] = 1 + dp[arr[i] - difference];
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }

    // https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
    int solveLenOfLongestAP(int idx, int diff, int A[])
    {
        if (idx < 0)
            return 0;
        int ans = 0;
        for (int i = idx - 1; i >= 0; i--)
        {
            if (A[idx] - A[i] == diff)
            {
                ans = max(ans, 1 + solveLenOfLongestAP(i, diff, A));
            }
        }
        return ans;
    }
    int lengthOfLongestAP(int A[], int n)
    {
        if (n <= 2)
            return n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, 2 + solveLenOfLongestAP(i, A[j] - A[i], A));
            }
        }
        return ans;
    }
    int lengthOfLongestAP(int A[], int n)
    {
        if (n <= 2)
            return n;
        int ans = 0;
        unordered_map<int, int> dp[n + 1];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j];
                int cnt = 1;
                if (dp[j].count(diff))
                    cnt = dp[j][diff];
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}