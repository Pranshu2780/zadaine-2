#include <bits/stdc++.h>
using namespace std;

int V, E;
const int INF = 100000000;
vector<pair<int, int>> adj[100];
vector<int> dist;
vector<int> parent, vis;

void Dijkstra(int s, int t)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    dist[s] = 0;
    min_heap.push({0, s});
    while (!min_heap.empty())
    {
        int node = min_heap.top().second;
        min_heap.pop();
        vis[node] = 1;

        for (auto i : adj[node])
        {
            if (dist[node] + i.second < dist[i.first] && !vis[i.first])
            {
                dist[i.first] = dist[node] + i.second;
                parent[i.first] = node;
                min_heap.push({dist[i.first], i.first});
            }
        }
    }
    return;
}

int main()
{

    int n;
    cin >> n;
    map<int, int> vertices;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vertices[temp] = i;
    }

    int ne;
    cin >> ne;

    vector<vector<pair<int,int>>> graph(n);
    for (int i = 0; i < ne; i++) {
        int a, b,wt;
        cin >> a >> b>>wt;
        graph[vertices[a]].push_back({vertices[b],wt});
    }

    // cin >> V >> E;

    int source, target;

    dist.assign(V + 3, INF);
    parent.assign(V + 3, -1);
    vis.assign(V + 3, 0);

    // for (int i = 0; i < E; i++)
    // {
    //     int a, b, w;
    //     cin >> a >> b >> w;
    //     adj[a].push_back({b, w});
    //     adj[b].push_back({a, w});
    // }

    cin >> source >> target;
    Dijkstra(source, target);

    parent[source] = -1;

    cout << dist[target] << endl;

    int x = target;
    while (x != source)
    {
        cout << parent[x] << " ";
        x = parent[x];
    }
}
