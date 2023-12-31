#include <bits/stdc++.h>
using namespace std;
int cutRod(int price[], int n)
{
    // code here
    vector<int> length;
    for (int i = 1; i <= n; i++)
        length.push_back(i);
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][n];
}
int main()
{

    return 0;
}