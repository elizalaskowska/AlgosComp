#include "graph_generator.hpp"
#include "kruskal.hpp"
#include "boruvka.hpp"
#include "prim.hpp"
#include "chrono"

long long measure_time(void(*find_mst)(Graph&, Mst&, const int&, const int&, int&),Graph &my_graph, Mst &my_mst, const int &num_of_vertices, const int &num_of_edges, int &result);