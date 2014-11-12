
#ifndef GRAPHS_HEADER 
#define GRAPHS_HEADER


/*
Created: 11/2014

Description:  A simplified graph using array of lists.  Nodes can't be removed.  However, it can contain an empty list (no edges).

Note:  Look at Graph.cpp for more advanced functions.
*/


#include <list>
#include <iostream>

class GraphS
{
public:
	//Construct and modify graph
	GraphS(unsigned long N= 0);								//Construct an array of list of size N
	~GraphS(){std::cout<<"object destroyed"<<std::endl;};
	void addEdge(unsigned long v, unsigned long e);			//add edge
	void removeEdge(unsigned long v, unsigned long e);		//remove edge

	//Access Graph
	std::list<unsigned long>* getGraph(){return graph;}		//pointer to graph
	unsigned long size(){return N;}							//returns the number of vertices
	void print();											//print graph (display connected edges for each vertices)

private:	
	unsigned long N;								//number of vertices
	std::list<unsigned long>* graph;				//array of list

};


#endif