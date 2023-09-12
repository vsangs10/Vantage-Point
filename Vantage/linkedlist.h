#include <string.h>
#include <string>
using namespace std; 
class location
{
public:
    double   longitude;
    double   latitude;

  location() {
    longitude = 0;
    latitude = 0;
  }
  bool equals(location ap) {
    if((longitude == ap.longitude) && (latitude == ap.latitude)) 
      return true;
      return false; 
  }
  void setLongitude(double value) {
    longitude = value; 
  }

  void setLatitude(double value) {
    latitude = value; 
  }
    
};

class n {
public: 
  location data;
  n *link; 

  n() { 
    data = location();
    link = NULL;
  }

  n(location d) {
    data = d; 
    link = NULL;
  }
  
};

class singlyLL {  
  public:
    n *head;
  
// Constructor
  singlyLL() {
    head = NULL; 
  }
// Destructor
  ~singlyLL() { 
  }
  
  void add(location data);
  void clear();
  bool equals(singlyLL);
  location get(int index);
  void insert(int index, location value);
  void exchg(int index1, int index2);
  void swap(int index1, int index2);
  bool isEmpty();
  void remove(int index);
  void set(int index, location value);
  int size();
  singlyLL subList(int start, int length);
  string toString();
};
