/*  https://www.spoj.com/problems/FARIDA/  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        int n;
        cin >> n;


        if (n == 0)
        {
            cout << "Case " << cs << ": " << 0 << endl;
            continue;
        }

        vector<long long> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }

        vector<long long> dp(n);
        dp[0] = coins[0];
        dp[1] = max(coins[0], coins[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
        }

        cout << "Case " << cs << ": " << dp[n - 1] << endl;
    }

    return 0;
}
