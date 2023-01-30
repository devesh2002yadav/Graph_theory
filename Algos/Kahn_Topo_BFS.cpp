#include<bits/stdc++.h> 
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include<list>
#include<stack>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    // unordered_map<int, list<int>> adjlist;
    vector<vector<int>> adjlist(v);
    vector<int> indeg(v, 0);
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<e; i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        adjlist[a].push_back(b);
    }
    for(auto i:adjlist)
    {
        for(auto j:i)
        {
            indeg[j]++;
        }
    }
    for(int i=0; i<v; i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    while(q.empty()==0)
    {
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto nbr:adjlist[front])
        {
            indeg[nbr]--;
            if(indeg[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}