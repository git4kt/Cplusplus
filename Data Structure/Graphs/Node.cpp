

#include "Node.h"

template <class T>
Node<T>::Node(){}


template <class T>
Node<T>::Node(T value, Node* next)
{
	this->value = value;
	this->next = next;
}

template <class T>
void Node<T>::addNode(Node<T>* list, T value)
{
	
	while(list->next != nullptr || list != nullptr)
	{
		list = list->next;	
	}
	Node<T>* nodePTR = new Node<T>(value);
	list->next = nodePTR;

}