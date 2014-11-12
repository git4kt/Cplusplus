
/*
Created: 11/2014

Description:  Implementation of breadth first search (BFS) for a graph.

Runtime:  <= O(V+E).  V is the number of nodes and E is the number of edges

Compile: g++ 04-1\ BFS.cpp GraphS.cpp -std=c++11
*/


#include "GraphS.h"
#include <vector>
#include <list>
#include <iterator>
#include <iostream>

class BFS
{
public:
	BFS(GraphS* graph, unsigned long s = 0);
	std::vector<unsigned long> getNodes(){return Nodes;}
private:
	std::vector<unsigned long> Nodes;
};

//Breadth first search
//Input graph, node to start traverse from
//Traverse path can be obtained from function: getNodes()
BFS::BFS(GraphS * graphS, unsigned long s)
{
	//Initialize
	auto graph = graphS->getGraph();									//require c++11
	std::vector<bool> check(graphS->size(), 0);				//vertices checklist set to unchecked
	std::list<unsigned long> deque;
	deque.push_back(s);
	
	
	//Traverse Graph
	while(!deque.empty())
	{
		unsigned long n = deque.front();			//Get current node

		Nodes.push_back(n);							//Store for printout
		deque.pop_front();								
		check[n] = true;								//Mark visited node
		std::list<unsigned long>::iterator it = graph[n].begin();
		//Iterate through all node edges
		for(; it != graph[n].end(); ++it)
		{
			if(check[*it] == false)
			{
				deque.push_back(*it);
				check[*it] = true;
			}
		}
		//end for loop
	}


}

//Test for BFS class
int main()
{
	
	GraphS *g = new GraphS(10);
	g->addEdge(0,3);					
	g->addEdge(0,2);
	g->addEdge(3,1);
	g->addEdge(2,1);
	g->addEdge(9,9);					

	BFS* bfs = new BFS(g, 0);					//traverse to 0,1,2,3
	//BFS* bfs = new BFS(g, 9);					//traverse to 9
	std::vector<unsigned long> nodes = bfs->getNodes();
	std::copy(nodes.begin(), nodes.end(), std::ostream_iterator<unsigned long>(std::cout, ", "));
	std::cout<<std::endl;

}

