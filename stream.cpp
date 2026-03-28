#include "stream.hpp"
#include <fstream>

void Read_data(int &num_of_vertices, int &num_of_edges, int &max_weight){
    cin >> num_of_vertices;
    cin >> num_of_edges;
    cin >> max_weight;
}

void write_graph (const Graph &My_graph, const int &num_of_vertices, const int &num_of_edges){
    cout<<num_of_vertices<<" "<<num_of_edges<<'\n';
    for(int i=1; i<=num_of_vertices; i++){
        for(auto vert:My_graph[i]){
            if(i<vert.first)
                cout<<i<<" "<< vert.first <<" "<< vert.second<<'\n';
        }
    }
}

void write_graph_to_file (const Graph &My_graph, const int &num_of_vertices, const int &num_of_edges){
    ofstream data("graph.txt");
    if(data.is_open()){
        for(int i=1; i<=num_of_vertices; i++){
            for(auto vert:My_graph[i]){
                if(i<vert.first)
                    data<<i<<" "<< vert.first <<" "<< vert.second<<'\n';
            }
        }
        data.close();
    } 
}

void write_mst_to_file (const Mst &my_mst){
    ofstream data("mst.txt");
    if(data.is_open()){
        for(int i=0; i<my_mst.size(); i++)
            data  << my_mst[i].second.first << " "<< my_mst[i].second.second<< " " << my_mst[i].first<<'\n';
        data.close();
    } 
}

void print_mst(const Mst &my_mst){
    for(int i=0; i<my_mst.size(); i++)
        cout<<my_mst[i].second.first<<" "<<my_mst[i].second.second<<" "<<my_mst[i].first<<'\n';
}