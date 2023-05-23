/*  https://cses.fi/problemset/task/1194/  */

#include<bits/stdc++.h>
using namespace std;

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char go[] = {'U', 'D', 'R', 'L'};
int maze[1005][1005];

int main()
{
    int n,m;
    cin>>n>>m;

    vector<string> vstring(n);

    for (auto &i: vstring)
    {
        cin>>i;
    }

    queue<pair<int,int>> q;
    int x,y;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (vstring[i][j] == 'M')
            {
                q.push({i,j});
            }
            else if (vstring[i][j] == 'A')
            {
                x = i, y = j;
            }
        }
    }

    q.push({x,y});
    maze[x][y] = -1;

    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();

        if (vstring[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1))
        {
            cout<<"YES"<<endl;

            string ans;

            int d = maze[x][y];
            while(d != -1)
            {
                ans += go[d];
                x -= fx[d];
                y -= fy[d];
                d = maze[x][y];
            }

            reverse(ans.begin(), ans.end());
            cout<<ans.size()<<endl;
            cout<<ans;
            return 0;
        }

        for (int i=0; i<4; i++)
        {
            int xx = x + fx[i],
            yy = y + fy[i];
            if (xx<0 || xx>=n || yy<0 || yy>=m || vstring[xx][yy] != '.' )
            {
                continue;
            }
            else
            {
                vstring[xx][yy] = vstring[x][y];
                if (vstring[xx][yy] == 'A') maze[xx][yy] = i;
                q.push({xx,yy});
            }
        }
    }

    cout<<"NO"<<endl;
}
