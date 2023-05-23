/* https://cses.fi/problemset/task/1666 */

#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool visited[100005];

void dfs(int node)
{
    if(visited[node])
    {
        return;
    }
    visited[node]=1;
    for(auto i: adj_list[node])
    {
        dfs(i);
    }
}

signed main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> vec;
    for(int i=1; i<nodes+1; i++)
    {
        if(!visited[i])
        {
            vec.push_back(i);
            dfs(i);
        }
    }

    cout<<vec.size()-1<<endl;

    for(int i=1; i<vec.size(); i++)
    {
        cout<<vec[i]<<" "<<vec[i-1]<<endl;
    }
}
