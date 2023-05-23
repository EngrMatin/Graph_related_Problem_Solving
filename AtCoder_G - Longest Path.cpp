/*  https://atcoder.jp/contests/dp/tasks/dp_g  */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    int inDegree[n+1];

    memset(inDegree,0,sizeof(inDegree));

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        inDegree[y]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(inDegree[i]==0) q.push(i);
    }

    int dp[n+1];
    memset(dp,0,sizeof(dp));

    int ans=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v:adj[u])
        {
            inDegree[v]--;
            dp[v]=max(dp[v],dp[u]+1);
            ans=max(ans,dp[v]);

            if(inDegree[v]==0)
            {
                q.push(v);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
