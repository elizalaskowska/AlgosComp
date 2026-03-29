#include "graph_generator.hpp"
#include "union_find.hpp"

void prepare_boruvka (Graph &my_graph, Edge_list &my_edge_list, vector<int> &min_edge, const int &num_of_vertices);

void find_mst_boruvka(Graph &my_graph, Mst &my_mst, const int &num_of_vertices, const int &num_of_edges, int &result);