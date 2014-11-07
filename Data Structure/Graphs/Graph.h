
//#ifndef GRAPH_H
//#define GRAPH_H

#include <vector>
#include <list>


class Graph
{

public:
	Graph(int size = 0);

	void addEdge(int src, int dst);						//add edge to graph
	void mergeNodes(int src, int dst);					//Merge nodes
	void removeNode(int node);							//remove node
	void removeSelfLoop(int node);						//remove self loops
	void printGraph();									//print out Graph
	void printNodes();									//Print out node list

	int numNodes();										//return number of nodes not removed
	std::vector<std::list<int> > & getGraph(){return graph;}	//return graph
	std::list<int>& getNodes() {return nodesList;}				//return node list

private:
	std::vector<std::list<int> > graph;					//Graph
	std::list<int> nodesList;							//List of nodes
};



//#endif