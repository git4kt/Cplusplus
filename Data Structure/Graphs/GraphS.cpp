
/*
Created: 11/2014

Description:  A simplified graph using array of lists.  Nodes can't be removed.  However, it can contain an empty list (no edges).

Note:  Look at Graph.cpp for more advanced functions.
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

#include "GraphS.h"


GraphS::GraphS(unsigned long N)
{
	this->N = N;
	graph =  new std::list<unsigned long>[N];
}


void GraphS::addEdge(unsigned long v, unsigned long e)
{
	if(v >=N || e >= N) return;
	graph[v].push_back(e);
}


void GraphS::removeEdge(unsigned long v, unsigned long e)
{

	std::list<unsigned long>::iterator it = graph[v].begin();
	while(it != graph[v].end() )
	{
		if(*it == e)
		{
			graph[v].erase(it);
			return;
		}
		++it;
	}
}


void GraphS::print()
{
	for(unsigned long i = 0; i<N; ++i)
	{
		std::cout<<"Vertex "<< i<< " contains: "<<std::endl;
		std::copy(graph[i].begin(), graph[i].end(), std::ostream_iterator<unsigned long>(std::cout, ", ") );
		std::cout<<std::endl;
	}
}