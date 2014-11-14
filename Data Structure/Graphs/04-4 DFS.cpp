

/*
created: 11/2014

Description:  Loads a graph and performs depth first search to traverse all vertices connected to a starting vertex.

Compile:  g++ 04-4\ DFS.cpp GraphS.cpp -std=c++11
Execute: ./a.out
*/


#include <vector>
#include <stack>
#include <iterator>
#include <iostream>

#include "GraphS.h"


class DFS
{
public:
	DFS(){};
	void set(GraphS* graph, unsigned long s);
	void traverse(GraphS* graph, unsigned long s, std::vector<bool>& check);
	std::vector<unsigned long> getVisited() {return visited;};		//return vector of visited nodes connected to node s
private:
	std::vector<unsigned long> visited;								//traversed vertices
};



//traverse using recursion
void DFS::traverse(GraphS* graph, unsigned long s, std::vector<bool>& check)
{
	auto g = graph->getGraph();
	check[s] = true;							//mark vertex visited
	visited.push_back(s);						//keep record of visited nodes

	//aggressively traverse through graph
	auto it  = g->begin();
	for(; it != g->end(); ++it)
	{
		if(check[*it] == false) traverse(graph, *it, check);

	}
}

//depth first search
void DFS::set(GraphS* graph, unsigned long s)
{
	std::vector<bool> check(graph->size(), false);
	visited.clear();
	traverse(graph,s,check);
}

//test class.  Remove main to use DFS
int main()
{
	GraphS* g = new GraphS(6);
	g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 3);

    //Print Graph
    //g->print();

    //Start from vertex 0
    DFS dfs;
    dfs.set(g,0);
	std::vector<unsigned long> nodes = dfs.getVisited();
	std::copy(nodes.begin(), nodes.end(), std::ostream_iterator<unsigned long>(std::cout, ", "));
	std::cout<<std::endl;

	//Start from vertex 1
	dfs.set(g,1);
	nodes = dfs.getVisited();
	std::copy(nodes.begin(), nodes.end(), std::ostream_iterator<unsigned long>(std::cout, ", "));
	std::cout<<std::endl;

}