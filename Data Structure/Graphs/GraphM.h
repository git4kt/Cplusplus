
#ifndef GRAPHM_HEADER
#define GRAPHM_HEADER

class GraphM
{

public:
	typedef unsigned long ul;

	GraphM(ul v);						//Create a matrix of size v-by-v
	~GraphM();							//Delete matrix
	void addEdge(ul i, ul j, ul w);		//Add weight to edge connection
	
	ul size(){return v;};				//Return number of vertices
	ul** getMatrix(){return matrix;};	//return matrix pointer

	void print();									//prints graph
private:
	ul v;								//Number of vertices
	ul** matrix; 						//Matrix Pointer 
};

#endif

