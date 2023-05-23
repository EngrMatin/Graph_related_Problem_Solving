/*  https://www.eolymp.com/en/problems/992  */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int matrix[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(matrix[i][j] == 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
