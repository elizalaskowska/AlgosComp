#include "prim.hpp"

void find_mst (Graph &my_graph, Mst &my_mst, const int &num_of_vertices, int &result){
    priority_queue < Node > prior_queue; // < cost, < vert_1, vert_2 >>
    vector < bool > if_in_mst (num_of_vertices+1);
    Node act_node;
    if_in_mst [1] = 1;
    int size_of_mst = 1, total_cost = 0;
    for (int i = 0; i < my_graph[1].size(); i++)
        prior_queue.push ({-my_graph[1][i].second, {my_graph[1][i].first, 1}});
    while(size_of_mst < num_of_vertices){
            act_node = prior_queue.top();
            prior_queue.pop();
        if (!if_in_mst [act_node.second.first]){
            if_in_mst [act_node.second.first] = 1;
            size_of_mst ++;
            act_node.first*=(-1);
            total_cost += act_node.first;
            my_mst.push_back(act_node);
            for(int j=0; j<my_graph[act_node.second.first].size(); j++)
                prior_queue.push({(-my_graph[act_node.second.first][j].second), {my_graph[act_node.second.first][j].first, act_node.second.first}});
        }
    }
    result = total_cost;
}
