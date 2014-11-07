

/*
Created: 10/2014
Description:  Performs quicksort for distinct numbers in an array
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

//Returns position of pivot point
// n = size of array
int getPivot(int n)
{
	return 0;
}


//swap
template <class T>
void swap(T* array, int i, int j)
{
	T temp = *(array+i);
	*(array+i) = *(array+j);
	*(array+j) = temp;
}

//partions array around pivot point
template <class T>
int partition(T* array, const int p, const int l, const int r)
{
	//find pivot point
	T pivot = *(array+p+l);

	//Partion array around pivot point
	int i=l+1;
	for(int j = l+1; j != r+1; ++j)
	{
		if(*(array+j) < pivot ) swap(array, i++, j);  
	}
	--i;	//reduce back to previous element
	swap(array, l,i);
	return i;
}

template <class T>
void sort(T* array, int l, int r)
{
	
	if(r-l <= 0) return;
	int p = getPivot(r-l);
	p = partition(array, p,l,r);
	sort(array, l,p-1);
	sort(array, p+1,r);

}


template <class T>
void quickSort(T* array, int size)
{
	sort(array, 0, size-1);
}




int main()
{
	//int array [] = {5,2,1,3,6,4};
	//int array [] = {1,2,3,4,5,6};
	//int array [] = {6,5,4,3,2,1};
	//int array [] = {3,1,4,6,5,2};
	int array [] = {3,9,8,4,6,10,2,5,7,1};
	print(array, array+10);
	quickSort(array, 10);
	print(array, array+10);
}