#include "graph_generator.hpp"
#include "prim.hpp"
#include "stream.hpp"
#include "kruskal.hpp"
#include "boruvka.hpp"

int main(){
    Map my_map;
    Graph my_graph;
    Mst my_mst;
    int num_of_vertices, num_of_edges, max_weight, result=0;
    Read_data(num_of_vertices, num_of_edges, max_weight);  
    generate_graph(my_map, my_graph, num_of_vertices, num_of_edges, max_weight); 
   // write_graph(my_graph, num_of_vertices, num_of_edges);
    write_graph_to_file (my_graph, num_of_vertices, num_of_edges);
    find_mst (my_graph, my_mst, num_of_vertices, result);
    cout<<result<<endl;
    result=0;
    my_mst.clear();
    find_mst_kruskal(my_graph, my_mst, num_of_vertices, num_of_edges, result);
    cout<<result<<endl;
    result=0;
    my_mst.clear();
    find_mst_boruvka(my_graph, my_mst, num_of_vertices, num_of_edges, result);
    cout<<result<<endl;
    //print_mst(my_mst);
    write_mst_to_file(my_mst);
    
}