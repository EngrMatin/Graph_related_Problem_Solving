/*  https://www.spoj.com/problems/ABCPATH/  */

#include<bits/stdc++.h>
using namespace std;

const int MAX_H = 50;
const int MAX_W = 50;

char grid[MAX_H][MAX_W];
int memo[MAX_H][MAX_W];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int h, w, ans;

int dfs(int x, int y)
{
    if (memo[x][y] != -1)
    {
        return memo[x][y];
    }

    int res = 1;
    for (int i=0; i<8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == grid[x][y] + 1)
        {
            res = max(res, dfs(nx, ny) + 1);
        }
    }

    memo[x][y] = res;
    return res;
}

int main()
{
    int caseNum = 1;
    while (cin>>h>>w && h!=0 && w!=0)
    {
        ans = 0;
        memset(memo, -1, sizeof(memo));
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {
                cin >> grid[i][j];
            }
        }

        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {
                if (grid[i][j] == 'A')
                {
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        cout <<"Case "<<caseNum++<<": "<<ans<<endl;
    }
    return 0;
}

