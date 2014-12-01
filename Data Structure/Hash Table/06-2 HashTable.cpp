
/*
Created: 11/2014

Project:  Given a text file with a list of number, compute the number of target value from the list such that x+y = t.  Where t is the value in range[-10,000, 10,000].  
Note:  the possible number of solution is between 0 and 20001.

Description:  A set was used to quickly find y, given x and t.
Runtime: 20,001 O(n)


Compile: g++ 06-2\ HashTable.cpp -std=c++11
Answer:  427
*/

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>


void load(std::string filename, std::set<double>& myset)
{
	std::fstream file;
	file.open(filename.c_str());

	std::istream_iterator<double> eos;
	std::istream_iterator<double> it(file);

	std::copy(it, eos, std::inserter(myset, myset.begin()));
}

template<class T>
void print(const T& container)
{
	for(auto it = container.begin(); it != container.end(); ++it)
	{
		std::cout<<*it<<std::endl;;
	}
}

int main()
{
	//Open data file
	std::set<double> set;
	load("../Test Data/2sum.txt", set);

	//count pair of 2sum for t = [-10,000 to 10,000]
	unsigned long count = 0;			//pair counter

	
	
	for(double t = -10000; t!= 10000; ++t)
	{		
		for(auto x:set)
		{
			double y = t-x;
			if(set.find(y) != set.end() ) 
			{
				++count;
				//std::cout<<x<<"\t"<<y<<"\t"<<t<<std::endl;
				goto exitXVariable;
			}
		}
		exitXVariable:;
	}

	//result
	std::cout<<count<<std::endl;
	//print(set);

}