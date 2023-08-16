

#include <bits/stdc++.h>
using namespace std;

void pattern()
{
    int numRows, numCols;

    cout << "Enter the number of rows: ";
    cin >> numRows;

    for (int i = 0; i < numRows; ++i)
    {
        int numCols = numRows * 2 - 1;
        for (int j = 0; j < numCols; ++j)
        {
            if (j >= (numCols - numRows + i) / 2 && j < (numCols + numRows - i - 1) / 2)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        cout << endl;
    }
}

int main()
{
    pattern();
    return 0;
}
