/*  https://www.eolymp.com/en/problems/1941  */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9;

vector<int> graph[N];
int level[N];
int rev_level[N];
int visited[N];

int cnt = 0;

void dfs(int src)
{
    level[src] = cnt++;
    visited[src] = 1;

    for(auto neighbor : graph[src])
    {
        dfs(neighbor);
    }

    rev_level[src] = cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int src = -1;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        int u;
        cin >> u;

        if(u != 0)
        {
            graph[u].push_back(i);
        }
        else
        {
            src = i;
        }
    }

    for(int i=1; i<=n; i++)
    {
        level[i] = INF;
        rev_level[i] = INF;
    }

    dfs(src);

    int m;
    cin >> m;

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        if(level[a] < level[b] && rev_level[a] > rev_level[b])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
