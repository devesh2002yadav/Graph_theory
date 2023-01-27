#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include<list>

bool cycleDFS(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &vis, int node, int parent)
{
    vis[node]=1;
    for(auto nbr:adjlist[node])
    {
        if(vis[nbr]==0)
        {
            bool check=cycleDFS(adjlist, vis, nbr, node);
            if(check==true)
            {
                return true;
            }
        }
        else if(nbr!=parent)
        {
            return true;
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
            bool bo=cycleDFS(adjlist, vis, i, -1);
            if(bo==true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
