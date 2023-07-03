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
int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows);
    return 0;
}