/*  https://www.eolymp.com/en/problems/4369  */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >>n>>m;

    vector<vector<int>> adj_list(n);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >>u>>v;
        u--;
        v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int k;
    cin >> k;

    vector<int> fired(k);
    for (int i=0; i<k; i++)
    {
        cin >> fired[i];
        fired[i]--;
    }

    vector<int> dist(n, INF);
    queue<int> q;
    for (int i=0; i<k; i++)
    {
        dist[fired[i]] = 0;
        q.push(fired[i]);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj_list[u])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int last_vertex = 0;
    for (int i = 1; i < n; i++)
    {
        if (dist[i] > dist[last_vertex])
        {
            last_vertex = i;
        }
    }

    cout <<dist[last_vertex]<<endl;
    cout <<last_vertex+1<<endl;

    return 0;
}


