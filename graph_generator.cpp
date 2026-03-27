#include "graph_generator.hpp"

void Generate_map (Map &My_map, const int &num_of_vertices, const int &num_of_edges, const int &max_weight){
    mt19937 Generator (random_device{}());
    // tree generation
    int vert_1, vert_2, value;
    uniform_int_distribution<int> Weight (1, max_weight);
    for(int i=2; i<=num_of_vertices; i++){
        uniform_int_distribution<int> Vertex (1, i-1);
        vert_1 = Vertex (Generator);
        value = Weight (Generator);
        My_map[{vert_1, i}]=value;
    }
    // rest of the graph
    uniform_int_distribution<int> Vertex (1, num_of_vertices);
    for(int i=0; i<num_of_edges-(num_of_vertices-1); i++){
        vert_1=Vertex(Generator);
        value=Weight(Generator);
        do{
            vert_2=Vertex(Generator);
        }while(vert_2==vert_1 || My_map[{min(vert_1, vert_2), max(vert_1, vert_2)}]!=0);
        My_map[{min(vert_1, vert_2), max(vert_1, vert_2)}]=value;
    } 
}       

void make_graph (const Map &My_map, Graph &My_graph, const int &num_of_vertices, const int &num_of_edges){
    vector<pair<int, int>> Node;
    for(int i=0; i<=num_of_vertices; i++)
        My_graph.push_back(Node);
    for(const auto& [key, value]:My_map){
        My_graph[key.first].push_back({key.second, value});
        My_graph[key.second].push_back({key.first, value});
    }
}

void generate_graph(Map &My_map, Graph &My_graph, int &num_of_vertices, int &num_of_edges, int &max_weight){
    Generate_map (My_map, num_of_vertices, num_of_edges, max_weight);
    make_graph(My_map, My_graph, num_of_vertices, num_of_edges); 
}
