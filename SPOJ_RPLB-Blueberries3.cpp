/*  https://www.spoj.com/problems/RPLB/  */

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, k, memo[N][N], bushes[N];

int maxBlueberries(int pos, int rem)
{
    if (pos >= n || rem == 0)
    {
        return 0;
    }

    if (memo[pos][rem] != -1)
    {
        return memo[pos][rem];
    }

    int ans = maxBlueberries(pos+1, rem);
    if (rem >= bushes[pos])
    {
        ans = max(ans, maxBlueberries(pos+2, rem-bushes[pos]) + bushes[pos]);
    }

    memo[pos][rem] = ans;

    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        memset(memo, -1, sizeof memo);
        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            cin >> bushes[j];
        }

        cout << "Scenario #" << i << ": " << maxBlueberries(0, k) << endl;
    }

    return 0;
}
