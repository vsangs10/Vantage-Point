#include "linkedlist.h"
#include <stdlib.h>
#include <iostream>
/*
Class Library File
*/


// add(value)				//Adds a new value to the end of this list.
  // void singlyLL::add(location data) {
  //   n *temp = head;
  //   if(head == NULL) {
  //     head = n; 
  //     return;
  //   }
  //   while(temp->link != NULL) {
  //     temp = temp->link;    
  //   }
  //   temp->link = n;
  // }
// clear()					//Removes all elements from this list.
  void singlyLL::clear() {
    n *current = head; 
    n *nextPointer = NULL; 
    while(current != NULL) {
      nextPointer = current->link; 
      delete(current); 
      current = nextPointer;
    }
  }
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
  bool singlyLL::equals(singlyLL ll) {
    n *temp1 = head->link; 
    n *temp2 = ll.head->link;
    while(temp1->link != NULL && temp2->link != NULL) {
      if(!(temp1->data.equals(temp2->data))) {
        return false;
      }
      temp1 = temp1->link; 
      temp2 = temp2->link; 
    }
    if(temp1 == NULL && temp2 == NULL)
      return true;
  
    return false; 
  }

//get(index)				//Returns the element at the specified index in this list.
  location singlyLL::get(int index) {
    int count = 0;
    n *temp = head; 
    while(temp->link != NULL) {
      if(count == index) {
        return temp->data; 
      }
      temp = temp->link;
      count++;
    }
    return head->data;
  }
//insert(index, value)		//Inserts the element into this list before the specified index.
  // void singlyLL::insert(int index, location value) {
  //   int count = 0;
  //   n *prev = new n();
  //   n *current = new n(); 
  //   current = head; 

  //   while(current->link != NULL && count != index) {
  //     prev = current;
  //     current = current->link;
  //     count++;
  //   }
  //   if(index == 0) {
  //     add(value);
  //   }
  //   else if(current->link == NULL && count == index) {
  //     add(value);
  //   }
  //   else if(index > count) {
  //     cout << "Index is too big";
  //   }
  //   else {
  //     prev->link = n;  
  //     n->link = current;
  //   }
  // }
//exchg(index1, index2)		//Switches the payload data of specified indexex.
  void singlyLL::exchg(int index1, int index2) {
    location temp1;
    location temp2; 
    int count = 0; 
    n *node1 = head; 
    n *node2 = head;
    while(node1->link != NULL && count != index1) {
      node1 = node1->link;
      count++;
    }
    temp1 = node1->data;
    count = 0;
    
    while(node2->link != NULL && count != index2) {
      node1 = node1->link;
      count++;
    }
    temp2 = node2->data; 

    node1->data = temp2;
    node2->data = temp1; 
  }
//swap(index1,index2)		//Swaps node located at index1 with node at index2
  void singlyLL::swap(int index1, int index2) {
    n *prev1 = new n();
    n *current1 = head; 
    int count1 = 0;
    while(count1 != index1 && current1 != NULL) {
      prev1 = current1; 
      current1 = current1->link;
      count1++;
    }

    n*prev2 = new n();
    n *current2 = head; 
    int count2 = 0;
    while(count2 != index2 && current2 != NULL) {
      prev2 = current2; 
      current2 = current2->link;
      count2++;
    }

    n *temp = current2->link;
    current2->link = current1->link;
    current1->link = temp; 
  }

// isEmpty()				//Returns true if this list contains no elements.
  bool singlyLL::isEmpty() {
    if(head == NULL) {
      return true;
    }
    return false; 
  }
// remove(index)			//Removes the element at the specified index from this list.
  void singlyLL::remove(int index) {
    int count = 0;
    n *node = head;
    while(node->link != NULL && count!=index) {
      node = node->link;
      count++;
    }
    node->link = node->link->link; 
  }
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
  void singlyLL::set(int index, location value) {
    n *node = head; 
    int count = 0;
    while(node->link != NULL && count != index) {
      node = node->link;
      count++;
    }
    node->data = value;
  }
// size()					//Returns the number of elements in this list.
  int singlyLL::size() {
    int count = 0; 
    n *temp = head;
    while(temp->link != NULL) {
      count++;
      temp = temp->link;
    }
    return count; 
  }
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
  singlyLL singlyLL::subList(int start, int length) {
    singlyLL newLL;
   n *node = head; 
    int count = 0;
    while(node->link != NULL && count != start) {
      node = node->link;
    }
    n*node2 = newLL.head; 
    for(int i = 0; i < length; i++) {
      node2 = node->link; 
      node = node->link; 
    }
    return newLL;
  }
// toString()				//Converts the list to a printable string representation.
  string singlyLL::toString() {
    n*node = head;
    string s = "";
    while(node->link != NULL) {
      s = s + to_string((node->data).latitude) + " " + to_string((node->data).longitude) + "\n"; 
      node = node->link;
    }
    return s;
  }