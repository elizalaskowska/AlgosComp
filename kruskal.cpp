#include "kruskal.hpp"

void prepare_edge_list(const Graph &my_graph, Edge_list &my_edge_list){
    for(int i=1; i<my_graph.size(); i++){
        for(int j=0; j<my_graph[i].size(); j++){
            if(i<my_graph[i][j].first)
                my_edge_list.push_back({my_graph[i][j].second, {i, my_graph[i][j].first}});
        }
    }
    sort(my_edge_list.begin(), my_edge_list.end(), greater < Edge >());
}

void find_mst_kruskal (Graph &my_graph, Mst &my_mst, const int &num_of_vertices, const int &num_of_edges, int &result){
    Edge_list my_edge_list;
    prepare_edge_list(my_graph, my_edge_list);
    vector < int > representation, size_of_component;
    prepare_dsu(representation, size_of_component, num_of_vertices);
    int components = num_of_vertices, cost_of_mst=0;
    Edge curr_edge;
    while (!my_edge_list.empty() && components > 1){
        curr_edge = my_edge_list.back();
        my_edge_list.pop_back(); 
        if(union_components (size_of_component, representation, curr_edge)){
            components--;
            my_mst.push_back(curr_edge);
            cost_of_mst+=curr_edge.first;
        }
    }
    result=cost_of_mst;
}
