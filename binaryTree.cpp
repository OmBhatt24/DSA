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
BstNode *insert(BstNode *root, int data)
{
    if (!root)
        return root = new BstNode(data);
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
vector<string> fizzBuzz(int n)
{
    vector<string> ans;
    string temp;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            temp = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            temp = "Fizz";
        }
        else if (i % 5 == 0)
        {

            temp = "Buzz";
        }
        else
        {
            temp = to_string(i);
        }
        ans.push_back(temp);
    }
    return ans;
}
bool search(BstNode *root, int data)
{
    if (!root)
        return false;
    if (root->data == data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else if (data > root->data)
        return search(root->right, data);
}
int minEleInBst(BstNode *root)
{
    return !root->left ? root->data : minEleInBst(root->left);
}
int maxEleInBst(BstNode *root)
{
    return !root->right ? root->data : maxEleInBst(root->right);
}
int heightOfBst(BstNode *root)
{
    if (!root)
        return -1;
    else
        return 1 + max(heightOfBst(root->left), heightOfBst(root->right));
}
void DFSinOrder(BstNode *root)
{
    if (!root)
        return;
    DFSinOrder(root->left);
    cout << root->data << " , ";
    DFSinOrder(root->right);
}
void DFSpreOrder(BstNode *root)
{
    if (!root)
        return;
    cout << root->data << " , ";
    DFSpreOrder(root->left);
    DFSpreOrder(root->right);
}
void DFSpostOrder(BstNode *root)
{
    if (!root)
        return;
    DFSpostOrder(root->left);
    DFSpostOrder(root->right);
    cout << root->data << " , ";
}
void BFS(BstNode *root)
{
    if (!root)
        return;
    queue<BstNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BstNode *poped = q.front();
        cout << poped->data << " ";
        if (poped->left)
            q.push(poped->left);
        if (poped->right)
            q.push(poped->right);
        q.pop();
    }
}
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
void dfs(BstNode *root, vector<int> &ans)
{
    if (!root)
        return;
    dfs(root->left, ans);
    ans.push_back(root->data);
    dfs(root->right, ans);
}
int kthSmallest(BstNode *root, int k)
{
    vector<int> ans;
    dfs(root, ans);
    return ans[k - 1];
}
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

BstNode *sortedArrayToBSTUtil(vector<int> &nums, int start, int end)
{
    if (end <= start)
        return NULL;
    int mid = (start + end) / 2;
    BstNode *head = new BstNode(nums[mid]);
    head->left = sortedArrayToBSTUtil(nums, start, mid);
    head->right = sortedArrayToBSTUtil(nums, mid + 1, end);
    return head;
}
BstNode *sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBSTUtil(nums, 0, nums.size());
}

// https : // leetcode.com/problems/symmetric-tree/
bool isSymmetric(TreeNode *root)
{
    if (!root || !root->left || !root->right)
        return true;
    ///,,,,,,,,,,,,,,,,
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        TreeNode *node = q.front();
        for (int i = 0; i < q.size(); i++)
        {
            temp.push_back(node->val);
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

// https://leetcode.com/problems/diameter-of-binary-tree/
int diameterOfBinaryTree(TreeNode *root)
{
}
// https://leetcode.com/problems/balanced-binary-tree/
bool isBalanced(BstNode *root)
{
    if (!root)
        return true;
    return (abs(heightOfBst(root->left) - heightOfBst(root->right)) > 1) ? false : (isBalanced(root->left) && isBalanced(root->right));
}
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
int getMinimumDifference(BstNode *root)
{
    vector<int> ans;
    dfs(root, ans);

    int dif = ans[0], minDiff = INT_MAX;
    int i = 0, j = 1;
    while (j < ans.size())
    {
        dif = abs(dif - ans[j]);
        if (j - i + 1 == 2)
        {
            minDiff = min(minDiff, dif);
            dif += ans[i++];
        }
        j++;
    }
    return minDiff;
}
BstNode *prevForDfsForGetMinimumDifference = NULL;
int diffForDfsForGetMinimumDifference = INT_MAX;

void dfsForGetMinimumDifference(BstNode *root)
{
    if (root->left)
        dfsForGetMinimumDifference(root->left);
    if (prevForDfsForGetMinimumDifference)
        diffForDfsForGetMinimumDifference = min(diffForDfsForGetMinimumDifference, abs(prevForDfsForGetMinimumDifference->data - root->data));
    prevForDfsForGetMinimumDifference = root;
    if (root->right)
        dfsForGetMinimumDifference(root->right);
}
int getMinimumDifference(BstNode *root)
{

    dfsForGetMinimumDifference(root);
    return diffForDfsForGetMinimumDifference;
}

vector<double> averageOfLevels(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<double> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size(), sum = 0, s = size;
        while (s--)
        {
            TreeNode *t = q.front();
            sum += t->val;
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            q.pop();
        }
        ans.push_back((sum + 0.0) / size);
    }
    return ans;
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (p->val != q->val)
        return false;
    else
    {
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);
    }
    return true;
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }

    if (!root && targetSum == 0 && root->val)
        return true;
    else
        return false;
    if (targetSum < 0)
        return false;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

vector<TreeNode *> allPossibleFBT(int n)
{
}
int main()
{
    BstNode *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 5);
    cout << search(root, 5) << endl;
    cout << "Minimum element in BST:" << minEleInBst(root) << endl;
    cout << "Max element in BST:" << maxEleInBst(root) << endl;
    cout << "Height of BST:" << heightOfBst(root) << endl;
    cout << "BFS: ";
    DFSinOrder(root);
    cout << endl;
    cout << "BFS :";
    BFS(root);

    return 0;
}