#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void insertNonDecreasing(stack<int> &s, int data)
    {
        if (s.empty() || s.top() <= data)
            s.push(data);
        else if (s.top() > data)
        {
            int greater = s.top();
            s.pop();
            insertNonDecreasing(s, data);
            s.push(greater);
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            insertNonDecreasing(s, nums[i]);
        }
        for (int i = 1; i < k; i++)
        {
            s.pop();
        }
        return s.top();
    }

    string simplifyPath(string path)
    {
        stack<char> s;
        for (auto c : path)
        {
            if (c == '/' && s.top() != '/' || isalpha(c))
                s.push(c);
        }
        if (s.top() == '/')
            s.pop();
        string ans;
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<string> s;

        for (auto token : tokens)
        {
            if (token != "*" || token != "/" || token != "+" || token != "-")
            {
                s.push(token);
            }
            else
            {
                int ans;
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();
                if (token == "*")
                    ans = first * second;

                else if (token == "/")
                    ans = first / second;
                else if (token == "+")
                    ans = first + second;
                else if (token == "-")
                    ans = first - second;
                s.push(to_string(ans));
            }
        }
        return stoi(s.top());
    }
};
int main()
{

    return 0;
}