/*

Created 11/2014

Project:  sum of median for each new input mod with size of input.  
Example:  sum of median is m1 +m2 +...mN.  Where m1 is the median of first input.  m2 is the median of the 2 input.  mN is the median value for N inputs
Note:  if k is odd, median is (k+1)/2.  For k is even, median is (k/2)

Description:  Created a min and max priority queue to keep track of each median for each input
Runtime: O(n);

Answer: 3528
*/

#include <iostream>
#include <queue>
#include <iterator>

#include <fstream>
#include <string>



typedef unsigned long ul;



int main()
{


	//min and max priority queues
	std::priority_queue<ul> pqMax;											//holds buttom half
	std::priority_queue<ul, std::vector<ul>, std::greater<ul> > pqMin;		//holds upper half
	
	//open file	
	std::string filename = "../Test Data/Median.txt";
	std::fstream file;
	file.open(filename.c_str());

	std::istream_iterator<double> eos;
	std::istream_iterator<double> it(file);

	//insert to priority queue and compute median
	double median =0;
	double count = 0;
	while(it != eos)
	{
		//divide the priority queue into max and min
		if(pqMax.size() == pqMin.size())
		{
			pqMax.push(*it);
		}
		else
		{
			pqMax.push(*it);
			ul temp = pqMax.top();
			pqMin.push(temp);
			pqMax.pop();
		}
		++it;
		
		

		//Compute median
		/*
		if(pqMax.size() == pqMin.size()) 
		{
			//median = median + (pqMax.top() + pqMin.top())/2;
			median = median +pqMax.top();
		}
		else
		{
			median = median +pqMax.top();
		}*/
		median = median +pqMax.top();
		++count;


		
	}
	std::cout<<"Median Sum Value: "<<median<<std::endl;
	std::cout<<"Number of items: "<<count<<std::endl;
	std::cout<<"Median Sum Value mod with number of items: "<<  (int)median % (int)count <<std::endl;


}