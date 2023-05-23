/*  https://www.eolymp.com/en/problems/978  */

#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int parent[N + 1];
int rank_arr[N + 1];

int find(int i)
{
    if(parent[i] != i)
    {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void merge(int i, int j)
{
    int pi = find(i);
    int pj = find(j);

    if (pi == pj)
    {
        return;
    }

    if (rank_arr[pi] > rank_arr[pj])
    {
        parent[pj] = pi;
    }
    else
    {
        parent[pi] = pj;

        if (rank_arr[pi] == rank_arr[pj])
        {
            rank_arr[pj]++;
        }
    }
}

int main()
{
    int n, m;
    cin >>n>>m;

    vector<pair<int, pair<int, int>>> edges(m);

    for (int i=0; i<m; i++)
    {
        int u, v;
        cin >>u>>v;

        edges[i] = make_pair(1, make_pair(u, v));
    }

    sort(edges.begin(), edges.end());

    for (int i=1; i<=n; i++)
    {
        parent[i] = i;
        rank_arr[i] = 0;
    }

    vector<pair<int, int>> mst;

    for (int i=0; i<m; i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (find(u) != find(v))
        {
            merge(u, v);
            mst.push_back(make_pair(u, v));
        }
    }

    for (int i=0; i<n-1; i++)
    {
        cout << mst[i].first <<" "<< mst[i].second << endl;
    }

    return 0;
}
