/*  https://www.eolymp.com/en/problems/1060  */

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
char grid[N][N];
pair<int, int> path[N][N];
int visited[N][N];

int n;

int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0, 1, -1};

bool isGrid(pair<int, int> coord)
{
    if(coord.first>=0 && coord.first<n && coord.second>=0 && coord.second<n)
    {
        return true;
    }

    return false;
}

bool isSafe(pair<int, int> coord)
{
    if(grid[coord.first][coord.second]=='.' || grid[coord.first][coord.second]=='@')
    {
        return true;
    }

    return false;
}

void bfs(pair<int, int> coord)
{
    visited[coord.first][coord.second] = 1;
    path[coord.first][coord.second] = {-1, -1};

    queue<pair<int, int>> q;
    q.push(coord);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();

        for (int i=0; i<4; i++)
        {
            int x = head.first + dx[i];
            int y = head.second + dy[i];

            if (isGrid({x,y}) && isSafe({x,y}) && !visited[x][y])
            {
                q.push({x, y});
                visited[x][y] = 1;
                path[x][y]= {head.first, head.second};
            }
        }
    }
}


int main()
{
    cin >> n;

    pair<int, int> src, dest;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin>>grid[i][j];

            if (grid[i][j] == 'X')
            {
                src = {i,j};
            }
            if (grid[i][j] == '@')
            {
                dest = {i,j};
            }
        }
    }

    bfs(src);

    if (visited[dest.first][dest.second])
    {
        cout << "Y"<<endl;

        pair<int,int> old = dest;

        while(true)
        {
            if(dest.first==src.first && dest.second==src.second)
            {
                break;
            }

            grid[dest.first][dest.second] = '+';
            dest = path[dest.first][dest.second];
        }

        grid[old.first][old.second] = '@';
        grid[src.first][src.second] = '+';

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"N"<<endl;
    }

    return 0;
}
