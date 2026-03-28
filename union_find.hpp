#pragma once
#include "graph_generator.hpp"

typedef pair < int, pair < int, int >> Edge;

void prepare_dsu(vector<int> &representation, vector<int> &size_of_component, const int &num_of_vertices);

int find_representant (vector < int > &representation, int vert);

bool union_components (vector < int > &size_of_component, vector < int > &representation, const Edge &curr_edge);