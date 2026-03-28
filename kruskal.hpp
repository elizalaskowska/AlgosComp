#include "graph_generator.hpp"
#include "union_find.hpp"
 
typedef vector < Edge > Edge_list;

void prepare_edge_list(const Graph &my_graph, Edge_list &my_edge_list);

void find_mst_kruskal (Graph &my_graph, Mst &my_mst, const int &num_of_vertices, const int &num_of_edges, int &result);

