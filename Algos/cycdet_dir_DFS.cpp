#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include<list>

bool cyc_dfs(int node, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &vis,
 unordered_map<int, bool> &dfsvis)
 {
   vis[node]=1;
   dfsvis[node]=1;
   for(auto nbr:adjlist[node])
   {
     if(!vis[nbr])
     {
       bool det=cyc_dfs(nbr, adjlist, vis, dfsvis);
       if(det)
       {
         return true;
       }
     }
     else if(dfsvis[nbr])
     {
       return true;
     }
   }
  dfsvis[node]=0;
  return false;
 }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
   unordered_map<int, list<int>> adjlist;
   unordered_map<int, bool> vis;
   unordered_map<int, bool> dfsvis;
   for(int i=0; i<edges.size(); i++)
   {
     int a=edges[i].first;
     int b=edges[i].second;
     adjlist[a].push_back(b);
   }
   for(int i=1; i<=n; i++)
   {
     if(!vis[i])
     {
       bool bo=cyc_dfs(i, adjlist, vis, dfsvis);
       if(bo)
       {
        return true;
       }
     }
   }
   return false;
}