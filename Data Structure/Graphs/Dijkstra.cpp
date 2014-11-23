

#include <iostream>
#include <iterator>
#include <algorithm>


#include "GraphM.h"
#include "Dijkstra.h"


Dijkstra::Dijkstra(GraphM* graph)
{
	this->graph = graph;
	n = graph->size();
	matrix = graph->getMatrix();
	visited = std::vector<bool>(n, false);
	cost = std::vector<double>(n, maxValue);

}



void Dijkstra::print(int sel)
{

	if(sel == 0) 
	{
		for(ul i = 0; i != n; ++i)
		{
			std::cout<<i+1<< " "<<cost[i]<<std::endl;
		}
	}
			
	else
	{
		for(ul i = 0; i != n; ++i)
		{
			std::cout<<i<< " "<<visited[i]<<std::endl;
		}
	}

	
//std::copy(cost.begin(), cost.end(), std::ostream_iterator<unsigned long>(std::cout, ","));		
//	std::cout<<std::endl;	
}


//Pick a starting postion
//first iteration always start at s
ul Dijkstra::getTailNode(ul s)
{
	if(visited[s] == false) 
	{
		visited[s] = true;
		return s;
	}
	

	for(ul i = 0; i !=n; ++i)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			return i;
		}
	}
}

void Dijkstra::computeCost(ul s)
{
	//set starting node to 0;
	cost[s] = 0;

	//Find shortest cost for each path
	for(ul c =0; c != n; ++c)
	{
		//Compute starting node
		ul u = getTailNode(s);

		//compute cost of each path
		for(ul v =0; v != n; ++v)
		{
			if(	matrix[u][v] &&							//edge weigh can't be 0
				cost[u] != maxValue &&					//all cost must start from 0 and increases
			   	cost[v] > cost[u]+matrix[u][v]			//new cost of path must be less than current cost
			  )
			{
				cost[v] = cost[u]+matrix[u][v];
				
			}// end if statement
		}// end cost compute between u and v
	}// 

}



