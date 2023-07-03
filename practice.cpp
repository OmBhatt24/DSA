#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int ans = 0, begin = 0, end = 0;
    unordered_map<int, int> window;
    while (end < fruits.size())
    {
        end++;
        for (int i = begin; i <= end; i++)
        {
            window[fruits[i]]++;
        }
        for (int i = end + 1; i < fruits.size(); i++)
        {
            if (window.count(fruits[i]) == 1)
                window[fruits[i]]++;
            else
            {
                int sum = 0;
                for (auto i : window)
                    sum += i.second;
                ans = max(ans, sum);
                window.clear();
                begin++;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> ans{1, 2, 1};
    cout << totalFruit(ans);
    return 0;
}