/*  https://lightoj.com/problem/country-roads  */

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;
const int N = 505;
vector<pii> adj[N];
int dist[N];

void dijkstra(int s, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    fill(dist, dist+n, INF);
    dist[s] = 0;

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d>dist[u])
        {
            continue;
        }

        for(auto [v, w] : adj[u])
        {
            int nd = max(d, w);
            if(nd<dist[v])
            {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, m, u, v, w, s;
    cin >> t;

    for(int cs=1; cs<=t; cs++)
    {
        cin >>n>>m;

        for(int i=0; i<n; i++)
        {
            adj[i].clear();
        }

        while(m--)
        {
            cin >>u>>v>>w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        cin >> s;
        dijkstra(s, n);

        cout <<"Case "<<cs<<":\n";
        for(int i=0; i<n; ++i)
        {
            if(dist[i] == INF)
            {
                cout <<"Impossible\n";
            }
            else
            {
                cout <<dist[i]<<"\n";
            }
        }
    }
    return 0;
}

