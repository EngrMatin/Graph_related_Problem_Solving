/*  https://www.eolymp.com/en/problems/1388  */

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9;

vector<pair<int, int>> adj[N];
int gas[N];
int dist[N];
bool visited[N];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> gas[i];
        dist[i] = INF;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto v : adj[u])
        {
            if (dist[v.first] > dist[u] + gas[u] * v.second)
            {
                dist[v.first] = dist[u] + gas[u] * v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;

    return 0;
}


