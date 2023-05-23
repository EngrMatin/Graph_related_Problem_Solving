/*  https://www.eolymp.com/en/problems/2470  */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int adj_matrix[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> adj_matrix[i][j];
        }
    }

    bool is_simple_undirected_graph = true;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(adj_matrix[i][j]!=adj_matrix[j][i] || (adj_matrix[i][j]==1 && i==j))
            {
                is_simple_undirected_graph = false;
                break;
            }
        }

        if(!is_simple_undirected_graph)
        {
            break;
        }
    }

    if(is_simple_undirected_graph)
    {
        cout <<"YES"<<endl;
    }
    else
    {
        cout <<"NO"<<endl;
    }

    return 0;
}
