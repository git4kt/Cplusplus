/*
Created:  11/2014

Description:  Generic linked list without node deletion.  Used to test code for graph implementation. 
*/


#include <iostream>

template <class T>
struct Node
{
	T data;
	Node<T>* next = nullptr;

	//Use of constructor instead of malloc to add a new node to link list
	//Example:  head->next = new Node<int>(2);
	Node(T data)
	{
		this->data=data;
	}
};



//print link list using recursion
template <class T>
void print(Node<T>* head)
{
	if(head == nullptr) {std::cout<<std::endl; return;}
	std::cout<<head->data<<" ";
	print(head->next);
}

int main()
{
	Node<int>* head = nullptr;
	Node<int>* current = nullptr;
	
	head = new Node<int>(1);
	current = head;

	//Add random integer to link list
	srand(time(nullptr));				//initialize random number
	for(int i = 0; i != 10; ++i)
	{
		current->next = new Node<int>(rand() %100);
		current = current->next;
	}
	

	print(head);
}