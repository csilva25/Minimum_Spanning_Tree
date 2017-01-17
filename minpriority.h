/*
 @file minpriority.h Declaration of the minPriorityQ and Element classes.
 
 @author Cristian Silva
 
 @date 11/30/16
 */
#ifndef minpriority_h
#define minpriority_h
#include <string>
#include <vector>
using namespace std;

class minPriorityQ
{
public:
    //minPriorityQ(int);
    //~minPriorityQ();
    void insert(string,int);
    void decreaseKey (string, int);
    string extractMin();
    bool isMember(string);
    int size(){return (int)my_vector.size();}
private:
    void buildMinHeap();
    void minHeapify(int);
    class Element
    {
        public:
        string id;
        int key;

    };
    vector <Element> my_vector;
    int parent(int);
    int left(int);
    int right(int);
};

#endif //minpriority_h
