
/*
Created:  11/2014
Description:  Uses a Dijkstra to find shortest path in a graph

compile: g++ 05-1\ Dijkstra.cpp GraphM.cpp Dijkstra.cpp -std=c++11


*/

#include <iterator>
#include <iostream>
#include <string>
#include <fstream>		
#include <sstream>	
#include <vector>


#include "GraphM.h"
#include "Dijkstra.h"

//Load Graph by parsing comma, white space, and new line
//Assumes graph nodes starts at 0.  make adjustment to line(*) if not
GraphM* loadGraph(unsigned long n, std::string filename)
{
	GraphM* g = new GraphM(n);
	std::ifstream file;
	file.open(filename.c_str());

	std::string line, piece;
	unsigned long v1,v2;
	while(getline(file, line))
	{
		std::stringstream stream(line);
		stream >> v1;		//Tail vertex
		//Extract vertex and weigh from comma and space
		while(stream >>piece)
		{
			std::stringstream stream2(piece);
			
			//Parse Comma 
			std::vector<unsigned long> v2vec;
			while(stream2 >> v2)
			{
				
				if(stream2.peek() == ',') stream2.ignore();	
				v2vec.push_back(v2);
			}
			//Add to graph
			//g->addEdge(v1, v2vec[0], v2vec[1]);			//graph starts at 0 line(*)
			g->addEdge(v1-1, v2vec[0]-1, v2vec[1]);		//graph starts at 1
		}
	}

	return g;
}







int main()
{
	GraphM* g = loadGraph(200, "../Test Data/dijkstraData.txt");
	//g->print();

	Dijkstra* d = new Dijkstra(g);
	d->computeCost();
	d->print();

	delete(g);
}



