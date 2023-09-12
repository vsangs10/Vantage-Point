#include "graph.h"

  void Graph::addEdge(int u, int v, double w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  void Graph::printGraph() {
    for (int u = 0; u < numVertices; u++) {
      cout << "Vertex " << u << " is connected to:\n";
        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
          int v = (*i).first;
          double weight = (*i).second;
          cout << "\tVertex " << v << " with weight " << weight << endl;
      }
    }
  }

  vector<int> Graph::getPath(int dest, vector<int>& previous) {
    vector<int> path;
    int u = dest;
    while (u != -1) {
      path.insert(path.begin(), u);
      u = previous[u];
    }
    return path;
  }

  void Graph::dijkstra(int src, int dest) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<double> dist(numVertices, INF);
    vector<int> previous(numVertices, -1);
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = (*i).first;
        double weight = (*i).second;
        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          previous[v] = u;
          pq.push(make_pair(dist[v], v));
      }
    }
  }

        cout << "Shortest path from " << src << " to " << dest << ": ";
        vector<int> path = getPath(dest, previous);
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] + 1;
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Total distance: " << dist[dest] << endl;
        /* Using 10 mph -> 0.268224 km per minute as an estimate. This accounts for potential           traffic and other delays
        */
        cout << "Estimated Time of Arrival: " << dist[dest]/0.268224 << " minutes" << endl;
}