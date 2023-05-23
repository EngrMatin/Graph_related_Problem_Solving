/*  https://lightoj.com/problem/monkey-banana-problem  */

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
long long dp[N][N];

long long maxBanana(int row, int col, int n, const vector<vector<int>>& arr)
{
    if (row == 2 * n - 1)
    {
        return 0;
    }
    if (col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    long long ans = arr[row][col];

    if (row < n - 1)
    {
        ans += max(maxBanana(row + 1, col, n, arr), maxBanana(row + 1, col + 1, n, arr));
    }
    else
    {
        ans += max(maxBanana(row + 1, col, n, arr), maxBanana(row + 1, col - 1, n, arr));
    }

    dp[row][col] = ans;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    int cs = 0;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> arr(2 * n - 1, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
            }
        }

        int m = n - 1;
        for (int i = n; i < 2 * n - 1; i++, m--)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));

        cout << "Case " << ++cs << ": " << maxBanana(0, 0, n, arr) << endl;
    }

    return 0;
}
