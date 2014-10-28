
/*
Project:  Inversion count using a modified merge sort
Created: 10/2014

Description:  For a given array of size n with distinct numbers, an inversion occurs when A[i] > A[j] where i<j.
Inversion count can be used to compare ranked arrays.  Example is comparing 2 ranked video list from different viewers and determine how similar between the viewers preferences.

Runtime:  O(nlg(n))
Memory: 2n (use extra memory of size n)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>


//global variable to keep track with number of inversion pairs
double countGlobal =0;

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

//Print array - for debugging
template <class T>
void print(T *begin, T* end)
{
	while(begin != end)
	{
		std::cout<<*begin<<" ";
		++begin;
	}
	std::cout<<std::endl;
}

//Compare functions - can be modified for multiple data type
template <class T>
bool compareTo(T L, T R)
{
	return L < R;
}

//Merge arrays
template <class T>
void merge(T* a, T* aX, const int lo, int mid, int hi)
{
	//copy array a to aX
	for(int i = lo; i != hi+1; i++) *(aX+i) = *(a+i);

	int l = lo;
	int r = mid+1;

	int current = lo;

	while(current <= hi )
	{		
		//std::cout<< lo <<" "<<mid<<" "<<hi<<" \t "<<l<<" "<<r<<" "<<current<<" \t "<<countGlobal;
		if(l > mid)							a[current++]	= 	aX[r++]; //left pointer hits midpoint
		else if(r > hi )					a[current++]	= 	aX[l++]; //right pointer hits high
		else if(compareTo(aX[l], aX[r])) 	a[current++] 	= 	aX[l++]; //copy left element
		else  
		{
			a[current++] = aX[r++];		//copy right element
			countGlobal = countGlobal +((mid) - (l-1));	//update inversion pair count
		}
	}
}

//Split and sort array
template <class T>
void sort(T* array, T* arrayX, int low, int high)
{
	if(high <= low) return;
	int mid = low + (high-low)/2;
	sort(array, arrayX, low, mid);
	sort(array, arrayX, mid+1, high);
	merge(array, arrayX, low, mid, high);

}	

//mergesort
template <class T>
void mergeSort(T* array, int size)
{
	T arrayX [size];
	sort(array, arrayX, 0, size-1);
}	

int main()
{
	//int array [] = {5,2,1,4,3};
	//int array [] = {4,2,3,6,5};
	//int array [] = {5,4,3,2,1};
	//int array [] = {3,4,6,1,2};
	//int array[] = {1,2,3,4,5};

	std::vector<int> vec = getInput("2014 IntegerArray.txt");
	int* array = &vec[0];
	int size = vec.size();

	//print(array, array+size);
	mergeSort(array, size);
	//print(array, array+size);
	std::cout<< std::fixed<<"Number of Inversion Pairs:  "<<countGlobal<<std::endl;

	return 0;
}