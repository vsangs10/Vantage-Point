#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cmath> 

using namespace std;

const double INF = numeric_limits<double>::infinity();

struct Node {

  public:
    double latitude;
    double longitude;


    Node() {
      latitude = 0;
      longitude = 0;
    }


    Node(double lat, double lon) {
        latitude = lat;
        longitude = lon;
    }

};

class Graph {
private:
    int numVertices; // number of vertices
    vector<pair<int, double>> *adj; 

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adj = new vector<pair<int, double>>[numVertices];
    }

    void addEdge(int u, int v, double w);
    void printGraph();
    vector<int> getPath(int dest, vector<int>& prev);


/* 
Dijkstra's Algorithm: Computes the shortest path from a given node to any other node
*/
    void dijkstra(int src, int dest);
};