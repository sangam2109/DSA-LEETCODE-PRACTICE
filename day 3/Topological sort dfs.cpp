#include <bits/stdc++.h>

void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s)
{
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, adj, s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {

        if (!visited[i])
        {
            dfs(i, visited, adj, s);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}