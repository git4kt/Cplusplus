/*
Created:  11/2014

Description:  Graph initially designed for min-cut and can be modified for search.  

Assumption:  Each node is an element of a vector index.  
Limitation:  
- Graph used a vector of listed integer.  Removing a node doesn't remove the node from the vector.  A separate list is kep to keep track of nodes with connections.
- Graph can be redesign to be all pointers.  Current graph isn't memory efficient and some overhead processing for node removing.

*/


#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>


#include "Graph.h"

Graph::Graph(int size)
{
	graph.resize(size+1);
	//for(int i = 1; i != size+1; ++i){nodesList.push_back(i);}
}

void Graph::addEdge(int src, int dst)
{ 
	if(src >= graph.size() || dst >= graph.size() ) return;
	if(graph[src].size() == 0) nodesList.push_back(src);		//add node to list
	if(graph[dst].size() == 0) nodesList.push_back(dst);		//add node to list

	graph[src].push_back(dst);
	// push to both vertex direction (undirected graph)
	graph[dst].push_back(src);
}

//merges 2 nodes.  src nodes copied into dst nodes
void Graph::mergeNodes(int src, int dst)
{
	std::list<int>::iterator it = graph[src].begin();
	while(it != graph[src].end() )
	{
		if(*it != dst)	graph[dst].push_back(*it);
		++it;
	}
}

//removes node and edge
void Graph::removeNode(int node)
{
	//Remove from graph
	std::list<int>::iterator it = graph[node].begin();
	while( it != graph[node].end())
	{
		int connectedWith = *it;
		//Remove node from all other nodes connected to
		std::list<int>::iterator itErase= (graph[connectedWith]).begin();
		while(itErase != (graph[connectedWith]).end() )
		{
			if(*itErase == node)
			{
				graph[connectedWith].erase(itErase);
				break;
			}
			++itErase;
		}
		++it;	
	}


	//clear list
	graph[node].clear();

	//Remove from node list
	it = std::find(nodesList.begin(), nodesList.end(), node);
	nodesList.erase(it);
}


//remove selfloops
void Graph::removeSelfLoop(int node)
{
	std::list<int>::iterator it = graph[node].begin();
	while(it != graph[node].end() )
	{
		if(*it == node) it = graph[node].erase(it);
		++it;
	}
}

void Graph::printGraph()
{
	for(int i = 0; i!= graph.size(); ++i)
	{
		std::cout<<"vertex "<< i <<" connected to: ";
		std::copy(graph[i].begin(), graph[i].end(), std::ostream_iterator<int>(std::cout, ", ") );
		std::cout<<std::endl;
	}
}

void Graph::printNodes()
{
	std::copy(nodesList.begin(), nodesList.end(), std::ostream_iterator<int>(std::cout, ", ") );
	std::cout<<std::endl;
}

int Graph::numNodes()
{
	return nodesList.size();
}