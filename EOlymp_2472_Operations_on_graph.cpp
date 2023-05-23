/*  https://www.eolymp.com/en/problems/2472  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >>n>>k;

    vector<vector<int>> adj_list(n);

    for (int i=0; i<k; i++)
    {
        int op, u, v;
        cin >>op>>u;

        if(op==1)
        {
            cin >> v;
            u--;
            v--;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        else
        {
            u--;
            for(int j=0; j<adj_list[u].size(); j++)
            {
                cout <<adj_list[u][j]+1<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

