#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/equal-row-and-column-pairs/
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            // int k = 0;
            for (int j = 0; j < n; j++)
            {

                for (int k = j; k < n; k++)
                {
                    if (grid[i][j] == grid[k][j])
                        k++;
                    else
                        break;
                    if (k == n)
                        ans++;
                }
                cout << " i:" << i << " j:" << j << endl;
            }
        }
        return ans;
    }
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> mp;
        int n = grid.size(), ans = 0;
        for (int i = 0; i < n; i++)
            mp[grid[i]]++;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back(grid[j][i]);
            }
            ans += mp[v];
        }
        return ans;
    }
    // https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ijs;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    ijs.push_back({i, j});
                }
            }
        }
        for (auto ij : ijs)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][ij[1]] = 0;
            }
            for (int j = 0; j < n; j++)
            {
                matrix[ij[0]][j] = 0;
            }
        }
    }
    // https://leetcode.com/problems/game-of-life/?envType=study-plan-v2&envId=top-interview-150
    int getLiveNeighbour(vector<vector<int>> &board, int i, int j)
    {
        int count = 0;
        int m = board.size() - 1;
        int n = board[0].size() - 1;
        if (i == 0 && j == 0)
        {
            count += board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
        }
        else if (i == 0 && j == n)
        {
            count += board[i][j - 1] + board[i + 1][j - 1] + board[i + 1][j];
        }
        else if (i == m && j == 0)
        {
            count += board[i - 1][j] + board[i - 1][j + 1] + board[i][j + 1];
        }
        else if (i == 0)
        {
            count += board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1];
        }
        else if (j == 0)
        {
            count += board[i - 1][j] + board[i - 1][j + 1] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
        }
        else if (i == m && j == n)
        {

            count += board[i - 1][j - 1] + board[i - 1][j] + board[i][j - 1];
        }
        else if (i == m)
        {
            count += board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j - 1] + board[i][j + 1];
        }
        else if (j == n)
        {
            count += board[i - 1][j - 1] + board[i - 1][j] + board[i][j - 1] + board[i + 1][j - 1] + board[i + 1][j];
        }
        else if (i > 0 && j > 0 && i < m && j < n)
        {
            count += board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1];
        }
        return count;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<vector<int>> countMatrix;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(getLiveNeighbour(board, i, j));
            }
            countMatrix.push_back(temp);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = countMatrix[i][j];
                if (board[i][j])
                {
                    if (count < 2 || count > 3)
                        board[i][j] = 0;
                    if (count == 2 || count == 3)
                        board[i][j] = 1;
                }
                else
                {
                    if (count == 3)
                        board[i][j] = 1;
                }
            }
        }
    }

    // https://leetcode.com/problems/rotate-image/?envType=study-plan-v2&envId=top-interview-150
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(matrix[n - j - 1][i]);
            }
            ans.push_back(temp);
        }
        matrix = ans;
    }
    // https://leetcode.com/problems/spiral-matrix/?envType=study-plan-v2&envId=top-interview-150
    // top for the uppermost row, bottom for the downmost row, left for the leftmost column and right for the rightmost column.
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), start = 0, right = n - 1, bottom = m - 1, left = 0, top = 0;
        vector<int> ans;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i < right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            if (++top > bottom)
                break;
            for (int i = top; i < bottom; i++)
            {
                ans.push_back(matrix[i][right]);
                /* code */
            }
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
                /* code */
            }
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
                /* code */
            }

            if (++left > right)
                break;
        }
        return ans;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                
            }
            
        }
        
    }
};
int main()
{
    Solution s;
    return 0;
}