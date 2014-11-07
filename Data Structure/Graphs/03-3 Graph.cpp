

/*
Created: 11/2014
Description:  Created an adjacency list un-direct graph using a vector and linked lists.  Another option is to use linked list and array build using a struct

Assumption:  Nodes are not removed and all nodes have been counted chronologically.

Extension:  To removed nodes with better memory management, look at min cut code.  


*/

#include <iostream>
#include <vector>
#include <list>

#include <iterator>



//add edges
void addEdge(std::vector<std::list<int> >& graph, int src, int dst)
{
	if(src >= graph.size() || dst >= graph.size() ) return;

	graph[src].push_back(dst);
	// push to both vertex direction (undirected graph)
	graph[dst].push_back(src);
}

void print(std::vector<std::list<int> >& graph)
{
	for(int i =0; i < graph.size(); ++i)
	{
		std::cout<<"vertex "<< i <<" connected to: ";
		std::copy(graph[i].begin(), graph[i].end(), std::ostream_iterator<int>(std::cout, ", ") );
		std::cout<<std::endl;
	}
}


//Test simply undirect graph data structure with inability to remove nodes and edges
int main()
{
	
	//create graph
	std::vector<std::list<int> > graph(5);

	//add edges
	addEdge(graph, 0,1);
	addEdge(graph, 5,5);	//will not add
	addEdge(graph, 2,1);
	addEdge(graph, 4,4);
	addEdge(graph, 2,3);
	addEdge(graph, 1,5);	//will not add
	addEdge(graph, 7,2);	//will not add
	print(graph);
}