/*
 @file graph.h Declaration of the Graph, Vertex, and Neighbor classes.
 
 @author Cristian Silva
 
 @date 12/5/16
 */
#ifndef Graph_h
#define Graph_h
#include <map>
#include <iostream>
#include <vector>
#include "minpriority.h"
using namespace std;
class Graph
{
public:
   // Graph();
    ~Graph();
    void addVertex(string);
    void addEdge (string, string, int);
    void mst (string);
    void sortVector();
private:
    
    class Vertex
    {
    public:
        Vertex()
        {pi = "NIL"; key = 100;}
        string pi;
        int key;
    };
    class Neighbor
    {
    public:
        Neighbor(string nm_name, int nm_weight)
        {name = nm_name; weight = nm_weight;}
        string name;
        int weight;
        bool operator<(const Neighbor& n) const { return name < n.name; }
    };
    map<string, Vertex*> vertices;
    map <string, vector<Neighbor> > adjList;
    minPriorityQ minQ;
    
    void quickSort (vector<Neighbor> &,int,int);
    int randomized_partition(vector<Neighbor> &, int , int );
    int partition(vector<Neighbor>& , int , int );
};

#endif /* Graph_h */
