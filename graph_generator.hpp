#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

struct pair_hash {
    // T1, T2 can be any type
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1);
    }
};

typedef vector <vector < pair < int, int >>> Graph;
typedef unordered_map<pair<int, int>, int, pair_hash> Map;
typedef pair <int, pair < int, int >> Node;
typedef vector < Node > Mst;


void Generate_map (Map &My_map, const int &num_of_vertices, const int &num_of_edges, const int &max_weight);

void write_graph (const Map &My_map, const int &num_of_vertices, const int &num_of_edges);

void make_graph (const Map &My_map, Graph &My_graph, const int &num_of_vertices, const int &num_of_edges);

void Read_data(Map &My_map, Graph &My_graph, int &num_of_vertices, int &num_of_edges, int &max_weight);

