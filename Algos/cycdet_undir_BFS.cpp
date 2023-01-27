#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include<list>

bool cycleBFS(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &vis, int source)
{
    unordered_map<int, int> parent;
    queue<int> q;
    parent[source]=-1;
    q.push(source);
    vis[source]=1;
    while(!q.empty()) //q.empty()==0
    {
        int front=q.front();
        q.pop();
        for(auto nbr:adjlist[front])
        {
            if(vis[nbr]==1&&nbr!=parent[front])
            {
                return true;
            }
            else if(vis[nbr]==0)
            {
                q.push(nbr);
                vis[nbr]=1;
                parent[nbr]=front;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> vis;
    for(int i=0; i<m; i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for(int i=0; i<n; i++)
    {
        if(vis[i]==0)
        {
            bool bo=cycleBFS(adjlist, vis, i);
            if(bo==true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
