
/*
Project:  Mergesort
Created: 10/2014
Description:  Sorts array using divide and conquer paradigm
Runtime:  O(nlg(n))
Memory: 2n (use extra memory of size n)
*/

#include <iostream>



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
		//std::cout<< "Coordinates:  " <<l<<"  "<<*(aX+l) <<"  "<<r<<"  "<<*(aX+r)<<"  "<<current<<" " <<std::endl;
		if(l > mid)  a[current++] 						= 	aX[r++];		//left pointer hits midpoint
		else if(r > hi )  a[current++] 					= 	aX[l++];		//right pointer hits high
		else if(compareTo(aX[l], aX[r])) a[current++] 	= 	aX[l++];		//copy left element
		else  a[current++] 								= 	aX[r++];		//copy right element
		//std::cout<< "Coordinates:  " <<l<<"  "<<*(aX+l) <<"  "<<r<<"  "<<*(aX+r)<<"  "<<current<<" " <<std::endl;
		//print(a, a+5);	
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
	
	//int array [] = {4,2,3,6,5};
	int array [] = {5,4,3,2,1};
	//int array [] = {3,4,6,1,2};
	print(array, array+5);
	mergeSort(array, 5);
	print(array, array+5);


	return 0;
}