// Shortest Path in Undirected & Unweighted graph
// Question link - https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//   *Imp*  To reduce TC - use vector<int> vis(n, 0);
//   But as index starts from 1 to n, so everywhere vis[x] ---> vis[x-1] ;

#include<bits/stdc++.h> 
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
#include<list>
#include<stack>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int e)
{
	unordered_map<int, list<int>> adj;
	vector<int> ans;
	queue<int>q;
	//vector<int>vis(n, 0);
	unordered_map<int, bool> vis;
    unordered_map<int, int> par;
	for(int i=0; i<m; i++)
	{
		int a=edges[i].first;
		int b=edges[i].second;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	q.push(s);
	vis[s]=1;
	par[s]=-1;
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(auto nbr:adj[front])
		{
			if(vis[nbr]==0)
			{
				q.push(nbr);
				par[nbr]=front;
				vis[nbr]=1;
			}
		}
	}
	int current=e;
	ans.push_back(current);
	while(current!=s)
	{
		current=par[current];
		ans.push_back(current);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
