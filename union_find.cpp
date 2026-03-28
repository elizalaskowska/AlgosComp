#include "union_find.hpp"

void prepare_dsu(vector<int> &representation, vector<int> &size_of_component, const int &num_of_vertices){
    for(int i=0; i<=num_of_vertices; i++){
        representation.push_back(i);
        size_of_component.push_back(1);
    }
}

int find_representant (vector < int > &representation, int vert){
    if( vert == representation [vert])
        return vert;
    return representation[vert] = find_representant (representation,  representation[vert]);
}

bool union_components (vector < int > &size_of_component, vector < int > &representation, const Edge &curr_edge){
    int vert_1 = find_representant (representation, curr_edge.second.first);
    int vert_2 = find_representant (representation, curr_edge.second.second);
    if (vert_1 == vert_2)
        return 0;
    if (size_of_component [vert_1] < size_of_component [vert_2])
        swap (vert_1, vert_2);
    size_of_component [vert_1] += size_of_component [vert_2];
    representation [vert_2] = vert_1;
    return 1;
}
