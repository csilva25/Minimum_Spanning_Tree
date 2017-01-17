/*
 @file MSTapp.h Declaration of the MSTapp class.
 
 @author Cristian Silva
 
 @date 12/5/16
 */

#ifndef MSTapp_h
#define MSTapp_h

#include <iostream>
#include "Graph.h"

class MSTapp
{
public:
    void readGraph();
private:
    Graph myGraph;
};
#endif /* MSTapp_h */
