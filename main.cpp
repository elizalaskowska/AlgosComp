#include "graph_generator.hpp"
#include "prim.hpp"
#include "stream.hpp"
#include "kruskal.hpp"
#include "boruvka.hpp"
#include "time_measuring.hpp"
#include <chrono>
#include <fstream>
#include <utility>

void run_program(int&& num_of_vertices, int&& num_of_edges, int&& max_weight, int&& loops, ofstream& file){
    Map my_map;
    Graph my_graph;
    Mst my_mst;
    int result=0;
    unsigned long long av_1=0, av_2=0, av_3=0;
    for(int i=0; i<loops; i++){
        generate_graph(my_map, my_graph, num_of_vertices, num_of_edges, max_weight); 
        result=0;
        my_mst.clear();
        av_1+=measure_time(find_mst_prim, my_graph, my_mst, num_of_vertices, num_of_edges, result );
    
        result=0;
        my_mst.clear();
        av_2+=measure_time(find_mst_kruskal, my_graph, my_mst, num_of_vertices, num_of_edges, result );
    
        result=0;
        my_mst.clear();
        av_3+=measure_time(find_mst_boruvka, my_graph, my_mst, num_of_vertices, num_of_edges, result);
        my_graph.clear();
        my_map.clear();
    }
    av_1/=loops;
    av_2/=loops;
    av_3/=loops;
    file <<num_of_vertices<<" "<<num_of_edges<<'\n';
    file<<av_1<<" "<<av_2<<" "<<av_3<<'\n';
    
}

int main(){  
    int num_of_vertices, num_of_edges, max_weight, loops; 
    ofstream file("results.txt");
    run_program(1000, 20000, 100000, 10, file);
    
    run_program(1000, 50000, 100000, 10, file);
    
    run_program(1000, 100000, 100000, 10, file);
    
    run_program(1000, 250000, 100000, 10, file);
 //   write_graph_to_file (my_graph, num_of_vertices, num_of_edges);
    
    
    //cout<<result<<endl;
    
    //cout<<result<<endl;
    //print_mst(my_mst);
   // write_mst_to_file(my_mst);
    
}