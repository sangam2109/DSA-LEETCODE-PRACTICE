#include <unordered_map>
#include <set>
#include <list>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.

    // make adj list for data
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // using dist for finding least distance
    vector<int> dist(vertices);
    // using set for getting least distance relax
    set<pair<int, int>> st;
    // intialising distance with ifninity
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    // intialising source with 0 distance
    dist[source] = 0;
    st.insert(make_pair(0, source));

    // while stack not empty goes on
    while (!st.empty())
    {
        // get the top element means relaxing the least distance one
        auto top = *(st.begin());
        int node = top.second;
        int distance = top.first;
        // erase those who relaxed
        st.erase(st.begin());
        for (auto neighbour : adj[node])
        {
            if ((distance + neighbour.second) < dist[neighbour.first])
            {
                // if record already in set
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                dist[neighbour.first] = distance + neighbour.second;
                // add updated relaxed pair in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
