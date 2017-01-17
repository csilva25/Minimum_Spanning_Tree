/*
 @file minpriority.cpp
 
 @breif
 this file creates a minheap using vectors.
 
 @author Cristian Silva
 
 @date 11/30/16
 */

#include "minpriority.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

/*
 function insert takes in the two parameters that is the id and the key and 
 puts them in an element then add it into the vector. after this is done, 
 the vector calles the minHeapify function which will reorder the vector 
 in the correct order.
 
 @param string id 
 the string that hold the name of the element object
 @param int key
 is the position of the element object
 */
void minPriorityQ::insert(string id, int key)
{
    Element element;
    element.id= id;
    element.key = key;
    my_vector.push_back(element);
    minHeapify(0);
}

/*
 function decreaseKey firsts looks through the vector and located the matching
 id which the one that we are trying to decrease, then if its less then its
 current key, it positions the element in the new proper position.
 
 @param string id 
 the string that hold the name of the element object
 @param int key
 is the position of the element object

 */

void minPriorityQ::decreaseKey(string id, int newKey)
{
    for (int i = 0 ; i < my_vector.size(); i++)
    {
        if ( my_vector[i].id == id )
        {
            //cout << my_vector[i].id << endl;
            if (newKey < my_vector[i].key)
            {
              //  cout << "in if " << endl;
                my_vector[i].key = newKey;
                while (i > 0 && my_vector[parent(i)].key > my_vector[i].key)
                {
                        //      cout << "in while " << endl;
                    Element temp = my_vector[i];
                    my_vector[i] = my_vector[parent(i)];
                    my_vector[parent(i)] = temp;
                    i = parent(i);
                }
            }
        }
    }
    

}

/*
 extractMin function simply sames the first element's id to a string, which it 
 will print later, then it deletes the first element, then it reaarrenges the 
 vector in the proper order. in addition, if the vector is empty, then this 
 function returns empty.
 */


string minPriorityQ::extractMin()
{
    string id;
    id = my_vector[0].id;
    if (!my_vector.empty())
    {
        my_vector.erase(my_vector.begin());
        minHeapify(0);
        return id;
    }
        else return "empty";
    
}

/*
 this function checks that the id passed is in the vector.
 
 @param id
 the string name of the element that will be compared to each
 element id
 */

bool minPriorityQ::isMember(string id)
{
    Element element;
    for (int i = 0 ; i != my_vector.size(); i++)
    {
        element = my_vector[i];
        if (id == element.id)
            return true;
    }
    return false;
}

/*
 this function is the parent of the last index
 
 @param int i 
 the interger which will search for its parent from this postion
 */

int minPriorityQ::parent(int i)
{
    return (i-1)/2;
}
/*
 this function returns the left child of the index
 
 @param int i
 the interger which will search for its left from this postion
 */
int minPriorityQ::left(int i)
{
    return 2i+1;
}
/*
  this function returns the right child of the index
 
 @param int i
 the interger which will search for its right from this postion
 */
int minPriorityQ::right(int i)
{
  
    return 2i+2;
}
/*
 buildMinHeap is meant to make a heap with everyting in the correct order but
 this function is not used yet in this case
 
 */

void minPriorityQ::buildMinHeap()
{
    
    for (int i = (int)my_vector.size()/2 ; i!= 1; i-- )
        minHeapify(i);
    
}

/*
 this functions rearaged the subtree in its approrate position. it does this by
 making sure that the parents left child will be than it and right child will
 be greater than the parent in the subtree of the index that was passed in.
 
 @param int i
 index that is being used for all loops in this function. it dictates the left,
 right, and parent of the index, as well as the vector that those positions are
 being compared too in order to find the true smallest interger
 */
void minPriorityQ::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = 0;
    
    if (l < my_vector.size() && my_vector[l].key < my_vector[i].key)
    {
        smallest = l;
      //  cout << 1 << endl;
    }
    else
    {
        smallest = i;
        //cout << 2 << endl;
    }
    
    if (r < my_vector.size() && my_vector[r].key < my_vector[smallest].key)
    {
        smallest = r;
        //cout << 3 << endl;
    }
    if (smallest != i)
    {
        Element temp = my_vector[i];
        my_vector[i] = my_vector[smallest];
        my_vector[smallest] = temp;
        //cout << 4 << endl;
        minHeapify(smallest);
    }
}

