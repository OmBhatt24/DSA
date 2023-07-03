
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int findPeakElement(vector<int> &nums)
//     {
//     }
// };

void subsequence(int i, vector<int> &ds, int arr[], int n)
{

    if (i >= n)
    {
        for (auto j : ds)
            cout << j << " ";
        cout << endl;
        return;
    }

    ds.push_back(arr[i]);
    subsequence(i + 1, ds, arr, n);
    ds.pop_back();
    subsequence(i + 1, ds, arr, n);
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    subsequence(0, ds, arr, n);
    return 0;
}