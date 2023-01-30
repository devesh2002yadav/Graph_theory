#include<bits/stdc++.h> 
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include<list>
#include<stack>

void TPS(int node, vector<vector<int>> &adjlist, vector<int> &vis, stack<int> &st)
{
    vis[node]=1;
    for(auto nbr:adjlist[node])
    {
        if(vis[nbr]==0)
        {
            TPS(nbr, adjlist, vis, st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    // unordered_map<int, list<int>> adjlist;
    vector<vector<int>> adjlist(v);
    // unordered_map<int, bool> vis;
    vector<int> vis(v, 0);
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<e; i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        adjlist[a].push_back(b);
    }
    for(int i=0; i<v; i++)
    {
        if(vis[i]==0)
        {
            TPS(i, adjlist, vis, st);
        }
    }
    while(st.empty()==0)
    {
        int top=st.top();
        ans.push_back(top);
        st.pop();
    }
    return ans;
}