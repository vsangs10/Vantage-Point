#include "graph.h"
#include "linkedlist.h"

using namespace std;

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

int main() {
    Graph g(130);
    Node nodes[130];
    ifstream infile;
    char latitude[10];
    char longitude[10];
    char nodeNum[10];
    char adjNode[10];
    int i = 0;
    char discard[10];
    infile.open ("nodes.csv", ifstream::in);
    if (infile.is_open())
    {
        while (infile.good())
        {
            infile.getline(discard, 256, ',');
            infile.getline(latitude, 256, ',');
            nodes[i].latitude = atof(latitude);
            infile.getline(longitude, 256, '\n');
            nodes[i].longitude = atof(longitude);
            i++;
        }
        infile.close();
    }
  
    infile.open ("testadj.csv", ifstream::in);
    if (infile.is_open())
    {
        while (infile.good())
        {
            infile.getline(nodeNum, 256, ',');
            infile.getline(adjNode, 256, '\n');
            g.addEdge(atoi(nodeNum)-1,atoi(adjNode)-1,distanceEarth(nodes[atoi(nodeNum)-1].latitude,nodes[atoi(nodeNum)-1].longitude,nodes[atoi(adjNode)-1].latitude,nodes[atoi(adjNode)-1].longitude));
        }
        infile.close();
    }
    // g.addEdge(0, 1, 4.5);
    // g.addEdge(0, 2, 2.1);
    // g.addEdge(1, 2, 1.3);
    // g.addEdge(1, 3, 5.7);
    // g.addEdge(2, 3, 8.2);
    // g.addEdge(2, 4, 10.9);
    // g.addEdge(3, 4, 2.6);

    // g.printGraph();
    // cout << nodes[0].latitude << " " << nodes[0].longitude << " "<< distanceEarth(nodes[0].latitude,nodes[0].longitude,nodes[1].latitude,nodes[1].longitude);

    double ulat;
    double ulong;
    double destLat;
    double destLong;
    cout << "Enter your current latitude: ";
    cin >> ulat;
    cout << "Enter your current longitude: ";
    cin >> ulong;
    double uclosestDist = 1000000;
    double uclosest;
    for(int i = 0; i < 130; i++) {
      if(distanceEarth(ulat,ulong,nodes[i].latitude,nodes[i].longitude) < uclosestDist) {
        uclosestDist = distanceEarth(ulat,ulong,nodes[i].latitude,nodes[i].longitude);
        uclosest = i;
      }
    }

  
    cout << "Where do you want to go? Latitude: "; 
    cin  >> destLat;
    cout << "Where do you want to go? Longitude: "; 
    cin  >> destLong;
    double destclosestDist = 1000000;
    double destclosest;
    for(int i = 0; i < 130; i++) {
      if(distanceEarth(destLat,destLong,nodes[i].latitude,nodes[i].longitude) < destclosestDist) {
        destclosestDist = distanceEarth(destLat,destLong,nodes[i].latitude,nodes[i].longitude);
        destclosest = i;
      }
    }
// Test points, ulat:30.3045, ulong:-97.71083, destlat:30.29835, destlong:-97.7047
    g.dijkstra(uclosest, destclosest);
    return 0;
}

