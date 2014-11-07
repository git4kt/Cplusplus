

/*
Created: 10/2014
Description:  Created an adjacency list graph using an array and linked list.

Note:  an easier to read implementation is done using vectors and lists.  Refer to 03-3 Graph.cpp
*/


#include <iostream>


struct Node
{
	int vertex = 0;
	Node* next = nullptr;

	Node(){}
	Node(int vertex){this->vertex = vertex;}
};

struct LinkedList
{
	Node* first = nullptr;
	Node* current = nullptr;
};

struct Graph
{
	int nodes;
	LinkedList* verticesArray;

	//Create a new graph
	//Example:  graph* g = new graph(5);
	Graph(int nodes)
	{
		this->nodes = nodes;
		this->verticesArray = new LinkedList [nodes];
	}
};

//add an edge to graph.  src is the from vertex and dst is to vertex
void addEdge(Graph* g, int src, int dst)
{

}

//print out graph
void print(Graph* graph)
{
	for(int i =0; i != graph->nodes; ++i)
	{
		LinkedList* v = &(graph->verticesArray)[i];
		Node* current = v->current;
		std::cout<<"Vertex: "<< i<<" connected to: ";
		while(current != nullptr)
		{
			std::cout<<current->vertex<<", ";
			current = current->next;
		}
		std::cout<<std::endl;
	}
}


int main()
{

	Graph* g = new Graph(5);
	print(g);
	return 0;
}