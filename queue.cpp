#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
    BstNode(int d) : data(d), left(nullptr), right(nullptr) {}
    BstNode(int d, BstNode *l, BstNode *r) : data(d), left(l), right(r) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> q;
    int maxVal = INT_MIN, lvl = 1, ans = 0;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size(), sum = 0;
        while (s--)
        {
            root = q.front();
            q.pop();
            sum += root->val;
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        if (sum > maxVal)
        {
            ans = lvl;
            maxVal = sum;
        }
        lvl++;
    }
    return ans;
}
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }
    while (q.size() != 1)
    {
        int x = k;
        while (x > 1)
        {
            int r = q.front();
            q.pop();
            q.push(r);
            x--;
        }
        q.pop();
    }
    return q.front();
}
int main()
{

    return 0;
}