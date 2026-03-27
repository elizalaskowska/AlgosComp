#pragma once
#include "graph_generator.hpp"

void Read_data(int &num_of_vertices, int &num_of_edges, int &max_weight);

void write_graph (const Graph &My_graph, const int &num_of_vertices, const int &num_of_edges);

void write_graph_to_file (const Graph &My_graph, const int &num_of_vertices, const int &num_of_edges);

void write_mst_to_file (const Mst &my_mst);

void print_mst(const Mst &my_mst);