
/*
Project:  Count Inversion
Created: 10/2014
Description:  For a given array of size n with distinct numbers, an inversion occurs when A[i] > A[j] where i<j.
Inversion count can be used to compare ranked arrays.  Example is comparing 2 ranked video list from different viewers and determine how similar between the viewers preferences.

Implementation:  Brute force with two "for" loops.  Run time: O(n^2)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>



//input file
std::vector<int> getInput(std::string filename = "test.txt")
{
	std::ifstream file;
	file.open(filename.c_str());
	std::istream_iterator<int> eos;
	std::istream_iterator<int> it(file);

	std::vector<int> intVec;
	std::copy(it, eos, back_inserter(intVec));

	return intVec;
}

//count number of inversion using brute force
template<class T>
double count(T *begin, T *end)
{

	double inversion =0;
	for(; begin != end; begin++)
	{
		//compare to all other elements of array
		for(T *current = begin+1; current != end; current++)
		{
			if(*begin >*current ) {++inversion;}
		}
	}

	return inversion;
}


int main()
{
	//int array [] = {5,2,1,4,3};
	//int array [] = {5,4,3,2,1};

	std::vector<int> vec = getInput("2014 IntegerArray.txt");
	int* array = &vec[0];
	int size = vec.size();
	
	double num = count(array, array+size );

	std::cout<<std::fixed <<num<<std::endl;
	return 0;
}