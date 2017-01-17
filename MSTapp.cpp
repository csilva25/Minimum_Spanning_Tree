/*
 @file MSTapp.cpp
 
 @breif
 this file sets up the minimum spanning tree by calling the functions to do so
 and then runs the sort and mst. this is where main is.
 
 @author Cristian Silva
 
 @date 12/5/16
 */

#include <iostream>
#include <string>
#include <sstream>
#include "MSTapp.h"

using namespace std;

/*
 this main function creates an object and calls the readgraph function
 */
int main ()
{
    MSTapp mst;
    mst.readGraph();
}

/*
 readGraph, reads from the stardard input and creats a vertex, adds the edges,
 sorts the vector and finally calls mst which will create the minimum spanning
 tree and print to standard output as well.
 */
void MSTapp::readGraph()
{
    string first,start,sub,from,to;
    int weight;
    getline(cin,first);
    istringstream sin(first);
    sin >> start;
    myGraph.addVertex(start);
    while (sin.good())
    {
        sin >> sub;
        myGraph.addVertex(sub); 
    }
    
    while (cin >> from)
    {
        cin >> to;
        cin >> weight;
        myGraph.addEdge(from, to, weight);
        myGraph.addEdge(to, from, weight);
    }
    myGraph.sortVector();
    myGraph.mst(start);

}
