/*  https://cses.fi/problemset/task/1669/  */

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
bool visited[N];
int parent[N];

void dfs(int node, int par)
{
    visited[node] = true;
    parent[node] = par;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbor = adj[node][i];
        if (!visited[neighbor])
        {
            dfs(neighbor, node);
        }
        else if (visited[neighbor] && parent[node] != neighbor)
        {
            vector<int> cycle;
            cycle.push_back(neighbor);
            int cur = node;
            while (cur != neighbor)
            {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(neighbor);

            cout << cycle.size() << endl;
            for (int i = cycle.size() - 1; i >= 0; i--)
            {
                cout << cycle[i] << " ";
            }
            exit(0);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}

/*
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3

*/
