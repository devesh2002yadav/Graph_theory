#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <list>
#include <set>

void BFS_logic(map<int, set<int>>&adjlist, vector<int>&vis, vector<int>&ans, int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    while(q.empty()==0)
    {
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto x:adjlist[front])
        {
            if(vis[x]==0)
            {
                q.push(x);
                vis[x]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    map<int, set<int>>adjlist;
    vector<int>ans;
    vector<int>vis(vertex, 0);
    for(int i=0; i<edges.size(); i++)
    {
        int a=edges[i].first;
        int b=edges[i].second;
        adjlist[a].insert(b);
        adjlist[b].insert(a);
    }
    for(int i=0; i<vertex; i++)
    {
        if(vis[i]==0)
        {
            BFS_logic(adjlist, vis, ans, i);
        }
    }
    return ans;
}