
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/one_bit_color_map.hpp>
#include <boost/graph/stoer_wagner_min_cut.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/typeof/typeof.hpp>

#include <fstream>    //loadGraph
#include <sstream>    //loadGraph
#include <string>   //loadGraph

struct edge_t
{
  unsigned long first;
  unsigned long second;
};


void loadGraph(std::vector<edge_t>& vec, unsigned long& count)
{
  std::string filename = "../Test Data/kargerMinCut.txt";
  std::ifstream file;
  file.open(filename.c_str());

  std::string line;
  unsigned long v1, v2;
  while(getline(file, line))
  {
    
    std::stringstream stream(line); 
    stream>>v1;
    while(stream>>v2) 
    {
      edge_t edge = {v1-1, v2-1};
      vec.push_back(edge);
      ++count;
    }
  }

}


// A graphic of the min-cut is available at <http://www.boost.org/doc/libs/release/libs/graph/doc/stoer_wagner_imgs/stoer_wagner.cpp.gif>
int main()
{
  using namespace std;
  
  typedef boost::adjacency_list<boost::vecS, 
                                boost::vecS, 
                                boost::undirectedS,
                                boost::no_property, 
                                boost::property<boost::edge_weight_t, int> > undirected_graph;
  typedef boost::graph_traits<undirected_graph>::vertex_descriptor vertex_descriptor;
  typedef boost::property_map<undirected_graph, 
                              boost::edge_weight_t>::type weight_map_type;
  typedef boost::property_traits<weight_map_type>::value_type weight_type;
  
  // define the 16 edges of the graph. {3, 4} means an undirected edge between vertices 3 and 4.
  std::vector<edge_t> vec;
  unsigned long count = 0;
  loadGraph(vec, count);
 
  edge_t* edges = &vec[0];
  //edge_t edges[] = {{3, 4}, {3, 6}, {3, 5}, {0, 4}, {0, 1}, {0, 6}, {0, 7},
   // {0, 5}, {0, 2}, {4, 1}, {1, 6}, {1, 5}, {6, 7}, {7, 5}, {5, 2}, {3, 4}};
  
  // for each of the 16 edges, define the associated edge weight. ws[i] is the weight for the edge
  // that is described by edges[i].
  //weight_type ws[] = {0, 3, 1, 3, 1, 2, 6, 1, 8, 1, 1, 80, 2, 1, 1, 4};
  std::vector<weight_type> vecWeight(count, 1);
  weight_type* ws = &vecWeight[0];


  // construct the graph object. 8 is the number of vertices, which are numbered from 0
  // through 7, and 16 is the number of edges.
  //undirected_graph g(edges, edges + 16, ws, 8, 16);
  undirected_graph g(edges, edges + count, ws, 200, count);
  
  // define a property map, `parities`, that will store a boolean value for each vertex.
  // Vertices that have the same parity after `stoer_wagner_min_cut` runs are on the same side of the min-cut.
  BOOST_AUTO(parities, boost::make_one_bit_color_map(num_vertices(g), get(boost::vertex_index, g)));
  
  // run the Stoer-Wagner algorithm to obtain the min-cut weight. `parities` is also filled in.
  int w = boost::stoer_wagner_min_cut(g, get(boost::edge_weight, g), boost::parity_map(parities));
  
  cout << "The min-cut weight of G is " << w << ".\n" << endl;
  //assert(w == 4);
  
  cout << "One set of vertices consists of:" << endl;
  size_t i;
  for (i = 0; i < num_vertices(g); ++i) {
    if (get(parities, i))
      cout << i << endl;
  }
  cout << endl;
  
  cout << "The other set of vertices consists of:" << endl;
  for (i = 0; i < num_vertices(g); ++i) {
    if (!get(parities, i))
      cout << i << endl;
  }
  cout << endl;
  
  return EXIT_SUCCESS;
}