
/*
Created: 11/2014

Project:  Strongly connected components (SCC)

Description:  SCC finds a group of nodes that can travel u<->v, but not u-> or v->u.  SCC can be applied to social networks.  We can find how strongly and large a person is connected to other people.

Goal:  Output the size of the 10 largest SCC for a given input file

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


Compile: g++ 04-5\ SCC.cpp GraphS.cpp SCC.cpp -std=c++11
*/

#include <vector>
#include <stack>
#include <iterator>
#include <iostream>
#include <string>
#include <fstream>		
#include <sstream>	
#include <algorithm>

#include "GraphS.h"
#include "SCC.h"



//load graph
GraphS* getGraph(unsigned long n, std::string filename)
{
	GraphS* graph = new GraphS(n);

	std::ifstream file;
	file.open(filename.c_str());
	std::string line;
	unsigned long v1,v2;
	while(getline(file, line))
	{
		std::stringstream stream(line);
		stream>>v1>>v2;
		graph->addEdge(v1,v2);
	}


	return graph;
}

//sorting instruction
bool sizeVectSort(std::vector<unsigned long> i, std::vector<unsigned long> j)
{
	return i.size() > j.size();
}

int main()
{


	GraphS* g = getGraph(875714, "../Test Data/SCC.txt");

	SCC* scc = new SCC(g);
	scc->findSCC();
	std::vector<std::vector<unsigned long> > results = scc->getSCC();
	std::sort(results.begin(), results.end(), sizeVectSort);
	std::cout<<"Size of 10 largest SCC: "<<std::endl;
	for(int i =0; i!= 10; ++i)
	{
		std::cout<<results[i].size()<<std::endl;
	}
}
