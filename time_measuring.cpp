#include "time_measuring.hpp"

long long measure_time(void (*find_mst)(Graph&, Mst&, const int&, const int&, int&),Graph &my_graph, Mst &my_mst, const int &num_of_vertices, const int &num_of_edges, int &result){
    auto start = std::chrono::high_resolution_clock::now();
    find_mst (my_graph, my_mst, num_of_vertices, num_of_edges, result);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return duration.count();
} 