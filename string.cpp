#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindrome/

bool checkPalindrome(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

int longestPalindrome(string s)
{
    int ans = 0;
    while (ans < s.length())
    {
        if (checkPalindrome(s.substr(0, ans)))
        {
            ans++;
        }
    }
    return ans;
}

// https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
int lengthOfLastWord(string s)
{
    stringstream ss(s);
    string lastWord;
    while (ss >> lastWord)
        ;
    return lastWord.length();
}
int lengthOfLastWordO(string s)
{
    int len = 0, tail = s.size() - 1;
    while (tail >= 0 && s[tail] == ' ')
        tail--;
    while (tail >= 0 && s[tail] != ' ')
    {
        len++;
        tail--;
    }
    return len;
}
string convert(string s, int numRows)
{
    int diagonal = (numRows == 1) ? 0 : numRows - 2, j = 0;
    string ans;
    ans += s[0];
    for (int i = 1; i <= numRows; i++)
    {
        while (j < s.size())
        {
            j += (i == 1 || i == numRows)
                     ? numRows + diagonal
                     : numRows + diagonal - (2 * i);
            if (j < s.size())
                ans += s[j];
        }

        j = i + 1;
    }
    return ans;
}
bool buddyStrings(string s, string goal)
{
    int n = s.length();
    if (s == goal)
    {
        set<char> st(s.begin(), s.end());
        return st.size() < goal.size();
    }
    int i = 0;
    int j = n - 1;
    while (i < j && s[i] == goal[i])
    {
        i++;
    }
    while (j <= 0 && s[j] == goal[j])
    {
        j--;
    }
    swap(s[i], s[j]);
    return s == goal;
}
string intToRoman(int num)
{

    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}
bool closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size())
        return false;
    unordered_map<char, int> hsw1, hsw2;
    for (auto i : word1)
        hsw1[i]++;
    for (auto i : word2)
        hsw2[i]++;
    if (hsw1 == hsw2)
        return true;
    else
    {
        for (auto i1 : hsw1)
        {
            for (auto i2 : hsw2)
            {
                if (i1.first != i2.first)
                {
                    int idx = word1.find(i1.first);
                    if (hsw1[i1.first] != hsw2[word2[idx]])
                        return false;
                }
            }
        }
        return true;
    }
}

vector<int> minOperations(string boxes)
{
    vector<int> ans;
    for (int i = 0; i < boxes.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < boxes.size(); j++)
        {
            if (boxes[j] == '1')
            {
                temp += abs(j - i);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
int balancedStringSplit(string s)
{
    int i = 0, n = s.size(), ans = 0, temp = 0;
    while (i < n)
    {
        if (s[i] == 'R')
            temp++;
        if (s[i] == 'L')
            temp--;
        if (temp == 0 && i > 0)
            ans++;
        i++;
    }
    return ans;
}
bool closeStrings(string word1, string word2)
{
    vector<int> v1(26, 0), v2(26, 0), v12(26, 0), v22(26, 0);
    for (auto i : word1)
    {
        v1[i - 'a']++;
        v12[i - 'a'] = 1;
    }
    for (auto i : word2)
    {
        v2[i - 'a']++;
        v22[i - 'a'] = 1;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1 == v2 && v12 == v22;
}
int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows);
    return 0;
}