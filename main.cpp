#include "graph_generator.hpp"
#include "prim.hpp"
#include "print.hpp"

int main(){
    Map my_map;
    Graph my_graph;
    Mst my_mst;
    int num_of_vertices, num_of_edges, max_weight;
    Read_data(my_map, my_graph, num_of_vertices, num_of_edges, max_weight);   
    find_mst (my_graph, my_mst, num_of_vertices);
   // print_mst(my_mst)
}