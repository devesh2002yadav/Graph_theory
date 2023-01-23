
void DFS(map<int, list<int>> &adjlist, vector<int> &vis, vector<int> &component, int node)
{
   component.push_back(node);
   vis[node]=1;
   for(auto x:adjlist[node])
   {
       if(vis[x]==0)
       {
           DFS(adjlist, vis, component, x);
       }
   }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    map<int, list<int>> adjlist;
    vector<int> vis(V, 0);
    vector<vector<int>> ans;
    for(int i=0; i<E; i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for(int i=0; i<V; i++)
    {
        if(vis[i]==0)
        {
            vector<int> component;
            DFS(adjlist, vis, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}