#include "graph_generator.hpp"
#include "prim.hpp"
#include "stream.hpp"
#include "kruskal.hpp"
#include "boruvka.hpp"
#include "time_measuring.hpp"
#include <chrono>

void run_program(int num_of_vertices, int num_of_edges, int max_weight, int loops){
    Map my_map;
    Graph my_graph;
    Mst my_mst;
    int result=0;
    for(int i=0; i<loops; i++){
        generate_graph(my_map, my_graph, num_of_vertices, num_of_edges, max_weight); 

        result=0;
        my_mst.clear();
        cout<<measure_time(find_mst_prim,my_graph, my_mst, num_of_vertices, num_of_edges, result )<<endl;
    
        result=0;
        my_mst.clear();
        cout<<measure_time(find_mst_kruskal,my_graph, my_mst, num_of_vertices, num_of_edges, result )<<endl;
    
        result=0;
        my_mst.clear();
        cout<<measure_time(find_mst_boruvka, my_graph, my_mst, num_of_vertices, num_of_edges, result)<<endl;
        my_graph.clear();
        my_map.clear();
        cout<<endl;
    }
    
    

}

int main(){  
    int num_of_vertices, num_of_edges, max_weight, loops; 
    run_program(1000, 10000, 1000000, 5);
    cout<<'\n';
    run_program(1000, 100000, 10000000, 5);
    cout<<'\n';
    run_program(1000, 250000, 1000000, 5);
    cout<<'\n';
    run_program(1000, 400000, 1000000, 5);
 //   write_graph_to_file (my_graph, num_of_vertices, num_of_edges);
    
    
    //cout<<result<<endl;
    
    //cout<<result<<endl;
    //print_mst(my_mst);
   // write_mst_to_file(my_mst);
    
}