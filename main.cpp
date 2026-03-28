#include "graph_generator.hpp"
#include "prim.hpp"
#include "stream.hpp"

int main(){
    Map my_map;
    Graph my_graph;
    Mst my_mst;
    int num_of_vertices, num_of_edges, max_weight, result;
    Read_data(num_of_vertices, num_of_edges, max_weight);  
    generate_graph(my_map, my_graph, num_of_vertices, num_of_edges, max_weight); 
   // write_graph(my_graph, num_of_vertices, num_of_edges);
    write_graph_to_file (my_graph, num_of_vertices, num_of_edges);
    find_mst (my_graph, my_mst, num_of_vertices, result);
    print_mst(my_mst);
    write_mst_to_file(my_mst);
}