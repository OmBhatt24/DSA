#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : nums)
    {
        pq.push(i);
        if (pq.size() > k)
            pq.pop();
    }

    return pq.top();
}

// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
int maxProduct(vector<int> &nums)
{
    priority_queue<int> pq;
    for (auto i : nums)
    {
        pq.push(i);
    }
    int ans = 1;
    ans *= (pq.top() - 1);
    pq.pop();
    ans *= (pq.top() - 1);
    return ans;
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// https://leetcode.com/problems/smallest-number-in-infinite-set/
class SmallestInfiniteSet
{
public:
    priority_queue<int, set<int>, greater<int>> pq;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        int poped = pq.top();
        pq.pop();
        return poped;
    }

    void addBack(int num)
    {
        pq.push(num);
    }
};

int main()
{

    return 0;
}