
/*
Created:  11/2014

Description finds the number of min cut in a graph using randomized edge selection.  
*/

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <ctime>        //selectEdge
#include <cstdlib>      //selectEdge
#include <fstream>		//loadGraph
#include <sstream>		//loadGraph
#include <string>		//loadGraph

#include "Graph.h"




void loadGraph(Graph& graph, std::string filename)
{
	std::ifstream file;
	file.open(filename.c_str());

	std::string line;
	int v1, v2;
	while(getline(file, line))
	{
		
		std::stringstream stream(line); 
		stream>>v1;
		while(stream>>v2)	
		{
			graph.addEdge((int) v1,(int) v2);
		}
	}


}

//randomly select an edge on graph
void selectEdge(Graph& graph, int& src, int& dst)
{	
	srand(time(NULL));
	

	//Select a random src
	auto it = (graph.getNodes()).begin();
	std::advance(it, rand() % (graph.getNodes()).size());
	src = *it;

	//select a random dst
	it = (graph.getGraph())[src].begin();
	std::advance(it, rand() % (graph.getGraph())[src].size());
	dst = *it;

}

//removes edge and merge nodes from source to destination
void removeEdgeNode(Graph& graph, int src, int dst)
{
	graph.mergeNodes(src, dst);
	graph.removeNode(src);
	graph.removeSelfLoop(dst);
}


int main()
{
	Graph graph(200);

	//load graph
	loadGraph(graph, "../Test Data/kargerMinCut.txt");

	//graph.printGraph();


	//Remove edges until only 2 nodes remain
	while(graph.numNodes() > 2)
	{
		int src=0, dst=0;
		selectEdge(graph, src, dst);
		removeEdgeNode(graph, src, dst);
	}
	

	//Find number of min cuts
	auto it = (graph.getNodes()).begin() ;
	int a =(graph.getGraph())[*it].size();
	++it;
	int b = (graph.getGraph())[*it].size() ;
	int minCutNum = a >b ? a:b;
	std::cout<<"Number of Min cuts: "<< a <<" "<<b <<std::endl;


	return 0;
}