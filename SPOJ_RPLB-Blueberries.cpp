/*  https://www.spoj.com/problems/RPLB/  */

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main()
{
    int t, n, k;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> n >> k;

        int bush[n+1];

        for(int j = 1; j <= n; j++)
        {
            cin >> bush[j];
        }

        for(int j = 1; j <= n; j++)
        {
            for(int l = 0; l <= k; l++)
            {
                if(j == 1)
                {
                    if(bush[j] <= l)
                    {
                        dp[j][l] = bush[j];
                    }
                    else
                    {
                        dp[j][l] = 0;
                    }
                }
                else
                {
                    if(bush[j] <= l)
                    {
                        dp[j][l] = max(dp[j-1][l], bush[j] + dp[j-2][l-bush[j]]);
                    }
                    else
                    {
                        dp[j][l] = dp[j-1][l];
                    }
                }
            }
        }

        cout << "Scenario #" << i << ": " << dp[n][k] << endl;
    }

    return 0;
}
