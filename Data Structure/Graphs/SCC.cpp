
/*
Created: 11/2014

Project:  Strongly connected components (SCC)

Description:  SCC finds a group of nodes that can travel u<->v, but not u-> or v->u.  SCC can be applied to social networks.  We can find how strongly and large a person is connected to other people.

Implementation:  SCC was constructed using Korsaraaju's algorithm using depth first search (DFS).

Psuedo Code:
	peform dfs
		for each node (n) on graph
			if(node not visited)
				dfs(n)
		push nodes into a stack(order of stack determine time it took to reach a node)
	reverse graph
	peform dfs on reverse graph 
		for each node (n) from stack
			if(node not visited)
				dfs(n)


Runtime:  O(V+E) v= number of vertices, e = number of edges.

*/

#include <vector>
#include <stack>
#include <iterator>
#include <iostream>

#include "SCC.h"
#include "GraphS.h"


//Reverse graph by creating a new graph
GraphS* SCC::getGraphReversed()
{
	GraphS* gN = new GraphS(graph->size());
	for(unsigned long i =0; i<graph->size(); ++i)
	{
		auto g = graph->getGraph();
		auto it = g[i].begin();
		for(; it != g[i].end(); ++it) gN->addEdge(*it, i);
	}

	return gN;
} 

void SCC::DFSRev(unsigned long s, std::vector<unsigned long>& path)
{
	auto g = graph->getGraph();
	check[s] = true;
	path.push_back(s);
	

	auto it = g[s].begin();
	for(; it != g[s].end(); ++it)
	{
		if(check[*it] == false) DFSRev(*it, path);

	}

}

void SCC::DFS(unsigned long s, std::vector<unsigned long>& ordered)
{
	auto g = graph->getGraph();
	check[s] = true;

	auto it = g[s].begin();
	for(; it != g[s].end(); ++it)
	{
		if(check[*it] == false) DFS(*it, ordered);

	}
	ordered.push_back(s);
}

//Find path for a given node - Used for debugging
void SCC::DFS(unsigned long s)
{
	std::vector<unsigned long> ordered;
	DFS(s, ordered);


}


void SCC::printSCC()
{
	for(unsigned long i = 0; i != scc.size(); ++i)
	{
		std::copy(scc[i].begin(), scc[i].end(), std::ostream_iterator<unsigned long>(std::cout, ","));
		std::cout<<std::endl;
	}
}

void SCC::findSCC()
{
	//perform first DFS pass
	check = std::vector<bool>(graph->size(), false);			//allocated space for visited nodes
	std::vector<unsigned long> ordered;							//ordered stack
	//obtained ordered list	
	for(unsigned long i=0; i<graph->size(); i++)
	{
		if(check[i] == false) 
		{
			DFS(i, ordered);
		}
	}
 	
	//reverse graph
	GraphS* gR =  getGraphReversed();
	delete(graph);
	graph = gR;

	//pass reversed graph through DFS
	check.clear();
	check = std::vector<bool>(graph->size(), false);	

	for(unsigned long i=0; i<graph->size(); i++)
	{
		unsigned long n = ordered.back();
		ordered.pop_back();
		if(check[n] == false) 
		{
			std::vector<unsigned long> path;
			DFSRev(i,path);
			scc.push_back(path);

		}
	}


	
}