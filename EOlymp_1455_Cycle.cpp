/*    */

#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int N1 = 1e5;
const int INF = 1e9;

int n;
int adj_mat[N][N];
int dist[N1];
int parent[N1];

vector<pair<int,int>> adj_list[N1];

int main()
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> adj_mat[i][j];
        }
    }

    //memset(dist, INF, sizeof(dist));

    for(int i=1; i<=n; i++)
    {
        dist[i] = INF;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adj_mat[i][j] == 0 || adj_mat[i][j] == 100000 || adj_mat[i][j] == -100000)
            {
                continue;
            }

            adj_list[i+1].push_back({j+1, adj_mat[i][j]});
        }
    }

    int src = 1;
    dist[src] = 0;

    bool negative_cycle = false;
    int last_updated_node = -1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(pair<int,int> adj_node: adj_list[j])
            {
                int u = j;
                int v = adj_node.first;
                int w = adj_node.second;

                if(dist[u]+w < dist[v])
                {
                    dist[v] = dist[u]+w;
                    parent[v] = u;

                    if(i == n)
                    {
                        negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if(negative_cycle)
    {
        cout << "YES"<<"\n";
        int selected_node = last_updated_node;
        for(int i=1; i<=n-1; i++)
        {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;

        vector<int> path;
        path.push_back(selected_node);

        while(true)
        {
            selected_node = parent[selected_node];
            path.push_back(selected_node);

            if(selected_node == first_node)
            {
                break;
            }
        }

        cout << path.size() << "\n";

        reverse(path.begin(), path.end());

        for(int node: path)
        {
            cout<<node<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"NO"<<"\n";
    }

    return 0;
}
