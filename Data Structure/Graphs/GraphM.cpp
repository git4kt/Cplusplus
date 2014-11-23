

/*
Created:  11/2014
Description:  Create a graph using a matrix
*/


#include <iostream>
#include <vector>
#include "GraphM.h"

GraphM::GraphM(ul v)
{
	this->v = v;



	matrix = new ul* [v];

	//Initialize matrix with all 0's
	for(ul i =0; i!=v; ++i)
	{
		matrix[i] = new ul[v];
		for(ul j=0; j != v; ++j)
		{
			matrix[i][j] = 0;
		}
	}

}

GraphM::~GraphM()
{
	for(size_t i = 0; i < v; ++i)
    	delete matrix[i];

	delete matrix;
}



//Add weighted edge
void GraphM::addEdge(ul i, ul j, ul w)
{
	if(i >=v || j >=v ) return;
	matrix[i][j] = w;
}

void GraphM::print()
{
	for(ul i = 0; i != v; ++i)
	{
		for(ul j = 0; j != v; ++j)
		{
			std::cout<< matrix[i][j]<< ", ";
		}	
		std::cout<<std::endl;
	}
}