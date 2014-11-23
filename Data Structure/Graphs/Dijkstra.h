#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

#include "GraphM.h"


typedef unsigned long ul;
static const ul maxValue = 1000000;

class Dijkstra
{
public:
	Dijkstra(GraphM* graph);
	
	void computeCost(ul s=0);								//compute cost to all node starting at node s
	void print(int sel=0);									//prints cost(sel = 0) or weight(sel = 1).  

	std::vector<double>* getCost(){return &cost;}			//Returns the cost pointer
private:
	GraphM* graph;										//graph object
	ul n;												//number of nodes
	ul** matrix;										//graph matrix pointer copied form graph object
	std::vector<bool> visited;
	std::vector<double> cost;


	ul getTailNode(ul s);				//select a tail node
};

#endif