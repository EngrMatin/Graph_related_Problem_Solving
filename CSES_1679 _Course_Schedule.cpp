#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, m;
vector<int> adj[N];
int inDegree[N];

vector<int> bfs()
{
    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return order;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> order = bfs();

    if (order.size() == n)
    {
        for (int i : order)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
