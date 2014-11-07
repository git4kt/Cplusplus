#ifndef NODEHEADER	
#define NODEHEADER

template<class T>
class Node
{
public:
	Node();
	Node(T value, Node* next = nullptr);
	void addNode(Node<T>* list, T value);




private:
	T value;
	Node* next;

};

#endif
