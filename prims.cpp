#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int INF = 1e9, N = 1000;
int v, e, a, b, wt, adj[N][N];
vector<int> cost(N), parent(N);
vector<bool> visited(N);

void prim(int source)
{
    cost[source] = 0;
    parent[source] = -1;

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({0, source});

    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        pq.pop();

        if (visited[currentNode])
            continue;

        visited[currentNode] = true;

        for (int j = 0; j <= v; j++)
        {
            if (adj[currentNode][j] && !visited[j] && adj[currentNode][j] < cost[j])
            {
                parent[j] = currentNode;
                cost[j] = adj[currentNode][j];
                pq.push({cost[j], j});
            }
        }
    }

    int totalcost = 0;

    for (int i = 0; i <= v; i++)
    {
        if (i == source || !adj[i][parent[i]])
            continue;
        cout << parent[i] << " --> " << i << "\t\tcost - " << adj[i][parent[i]] << " \n";

        totalcost += adj[i][parent[i]];
    }

    cout << "Total Cost -->  " << totalcost;
}

int main()
{

    cin >> v >> e;

    cost.assign(N, INF);
    visited.assign(N, false);

    for (int i = 0; i <= v; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> wt;
        adj[a][b] = wt;
        adj[b][a] = wt;
    }

    int source;
    cout << "Enter the source node\n";
    cin >> source;

    prim(source);
    return 0;
}