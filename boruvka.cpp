#include "boruvka.hpp"

void prepare_boruvka (Graph &my_graph, Edge_list &my_edge_list, vector<int> &min_edge, const int &num_of_vertices){
    for(int i=1; i<=num_of_vertices; i++){
        for(int j=0; j<my_graph[i].size(); j++){
            if(i<my_graph[i][j].first)
                my_edge_list.push_back({my_graph[i][j].second, {i, my_graph[i][j].first}});
        }
        min_edge.push_back(-1);
    }
    min_edge.push_back(-1);
}

void find_mst_boruvka(Graph &my_graph, Mst &my_mst, const int &num_of_vertices, const int &num_of_edges, int &result){
    vector<int> representation, size_of_component;
    prepare_dsu(representation, size_of_component, num_of_vertices);
    Edge_list my_edge_list;
    vector <int> min_edge;
    prepare_boruvka (my_graph, my_edge_list, min_edge, num_of_vertices);

    int vert_1, vert_2, cost;
    int components = num_of_vertices;
    while(components>1){
        for(int i=0; i<my_edge_list.size(); i++){
            vert_1=my_edge_list[i].second.first;
            vert_2=my_edge_list[i].second.second;
            cost = my_edge_list[i].first;
            vert_1=find_representant(representation, vert_1);
            vert_2=find_representant(representation, vert_2);
            if(vert_1!=vert_2){
                if(min_edge[vert_1]==-1)
                    min_edge[vert_1]=i;
                else if(cost < my_edge_list[min_edge[vert_1]].first)
                    min_edge[vert_1]=i;
                if(min_edge[vert_2]==-1)
                    min_edge[vert_2]=i;
                else if(cost < my_edge_list[min_edge[vert_2]].first)
                    min_edge[vert_2]=i;
            }
        }
        for(int i=1; i<=num_of_vertices; i++){
            if(min_edge[i]!=-1){
                vert_1=my_edge_list[min_edge[i]].second.first;
                vert_2=my_edge_list[min_edge[i]].second.second;
                cost = my_edge_list[min_edge[i]].first;
                vert_1 = find_representant(representation, vert_1);
                vert_2 = find_representant(representation, vert_2);
                if(vert_1!=vert_2){
                    union_components(size_of_component, representation, my_edge_list[min_edge[i]]);
                    my_mst.push_back(my_edge_list[min_edge[i]]);
                    result+=cost;
                    components--;
                }
                min_edge[i]=-1;
            }
        }
    }

}