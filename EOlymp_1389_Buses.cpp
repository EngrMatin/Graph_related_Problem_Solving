/*    */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const int INF = 1e9;

struct bus
{
    int time1;
    int dest;
    int time2;
};

vector<bus> graph[N];
bool visited[N] = {0};
set<pair<int, int>> p;
vector<int> dist(N, INF);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v1, v2, r;
    cin >> n >> v1 >> v2 >> r;

    dist[v1] = 0;
    p.insert({0, v1});

    for (int i=0; i<r; i++)
    {
        int u, t1, v, t2;
        cin >> u >> t1 >> v >> t2;

        graph[u].push_back({t1, v, t2});
    }

    while(!p.empty())
    {
        int x;
        x = p.begin()->second;
        p.erase(p.begin());

        for(auto &[t1, b, t2] : graph[x])
        {
            if(dist[x]<=t1 && t2<dist[b])
            {
                p.erase({dist[b], b});
                dist[b] = t2;
                p.insert({dist[b], b});
            }

        }
    }

    if(dist[v2] != INF)
    {
        cout<<dist[v2];
    }
    else
    {
        cout<<-1;
    }

    return 0;
}


