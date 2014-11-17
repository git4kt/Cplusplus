#include <vector>
#include <stack>
#include <iterator>
#include <iostream>

#include "GraphS.h"


class SCC
{
public:
	SCC(GraphS* graph){this->graph = graph;};				//set graph
	void findSCC();		//get strongest component
	void printSCC();		//prints strongest components
	std::vector<std::vector<unsigned long> > getSCC(){return scc;};

private:
	GraphS* graph;	
	std::vector<std::vector<unsigned long> > scc;			//strongest connected component result
	std::vector<bool> check;								//nodes that has been traversed to

	void DFS(unsigned long s);
	void DFS(unsigned long s, std::vector<unsigned long>& ordered);
	void DFSRev(unsigned long s, std::vector<unsigned long>& path);
	GraphS* getGraphReversed();
};
