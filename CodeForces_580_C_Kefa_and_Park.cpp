/*  https://codeforces.com/problemset/problem/580/C  */

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, ans = 0;
int a[N], cnt[N];
vector<int> adj[N];

void dfs(int u, int p, int len)
{
    if(a[u])
    {
        len++;
    }
    else
    {
        len = 0;
    }

    if(len>m)
    {
        return;
    }

    if(u!=1 && adj[u].size() == 1)
    {
        ans++;
        return;
    }

    for(int v: adj[u])
    {
        if(v!=p)
        {
            dfs(v, u, len);
        }
    }
}

int main()
{
    cin >>n>> m;

    for(int i=1; i<=n; i++)
    {
        cin >>a[i];
    }

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    cout <<ans<<endl;
    return 0;
}

