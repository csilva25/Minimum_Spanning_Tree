/*
 @file Graph.cpp
 
 @breif
 this file holds all the functions necessery to make a minimum spanning tree.
 
 @author Cristian Silva
 
 @date 12/5/16
 */
#include "Graph.h"
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using std::sort;


Graph::~Graph()
{
    for (map<string,Vertex*>:: iterator i = vertices.begin();
         i!=vertices.end(); i++ )
        delete vertices[i->first];
}
/*
 this is the sorting function that grabs the adjecency list, sorts it from 
 the beginning to the end of it in order and then finishes
 */

void Graph::sortVector()
{
    for (map<string, vector<Neighbor> >:: iterator i = adjList.begin();
         i != adjList.end(); i++)
        std:: sort (i->second.begin(), i->second.end());
}

/*
 this function adds a vertex. the parent and weight are pre-set in the 
 constructor as nil and 100
 
 @param string name
    this is the name in which the vertex will be saved and refeneced as later
 */

void Graph::addVertex(string name)
{
    vertices[name] = new Vertex();
}

/*
 addEdge makes a neighbor and pushes it back into the adjecency list.
 
 @param from
    the string in which the adencejy list renences the vertex to pushback on 
 @param to
    the string in which the neighbor is going to know who it is coming from
 @param weight
    the weight of the vertex at that paticular moment
 */

void Graph::addEdge(string from, string to, int weight)
{
    Neighbor neighbor(to , weight);
    adjList[from].push_back(neighbor);
    
}

/*
 this function uses prims minimum spanning tree. the paramater is a string that 
 its going to refenece and know where it will start from then makes a vertex
 with the key 0. follwoing so, it adds the vertices to the minQ which is the 
 minimum priority queue. it does this doing the smallest to largest vertex until 
 there is no more to do. also, as i do this, the total weight of the list is 
 added to its self so find the total weight of the tree.
 
 @param string
    the string which we know where to start the process from.
 */


void Graph::mst(string name)
{
     int totalWeight = 0;
    vertices[name]->key = 0;
    
    for (map<string,Vertex*>:: iterator i = vertices.begin();
         i!=vertices.end(); i++ )
        minQ.insert(i->first, i->second->key);
    
    minQ.decreaseKey(name, 0);
    while (minQ.size() > 0)
    {
        string temp_name = minQ.extractMin();
        totalWeight+= vertices[temp_name] -> key;
        cout << temp_name << " " << vertices[temp_name] -> pi << " " <<
        vertices[temp_name] -> key << endl;
        for (unsigned i = 0; i < adjList[temp_name].size(); i++)
        {
            Neighbor neighbor =adjList[temp_name][i];
            if (minQ.isMember(neighbor.name) &&
                neighbor.weight < vertices[neighbor.name] -> key)
            {
                minQ.decreaseKey(neighbor.name, neighbor.weight);
                vertices[neighbor.name] -> pi = temp_name;
                vertices[neighbor.name] -> key = neighbor.weight;
            }
        }
    }
    
    cout << totalWeight << endl;
 
}


